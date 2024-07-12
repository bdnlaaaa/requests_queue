#include "Manager.h"
#include "Request.h"

namespace
{
constexpr int MAX_THREADS = 2;
}

Manager::Manager()
{
    int count = 0;
    // ограничение в 100 запросов, потому что ждать,
    // когда Request::getRequest() вернет nullptr, очень долго
    while (true && count < 100)
    {
        Request* request = Request::getRequest();
        if (!request)
            break;
        m_queue.populate(request);
        count++;
    }
}

Manager::~Manager()
{
    m_queue.cleanup();
}

void
Manager::start()
{
    auto f = [this]()
    {
        while (m_running)
        {
            if (m_queue.empty())
                continue;
            Request::processRequest(m_queue.popFront());
        };
    };

    for (int i = 0; i < MAX_THREADS; i++)
        m_threads.emplace_back(std::thread(f));
}

void
Manager::stop()
{
    m_running = false;
    for (auto& thread : m_threads)
        thread.join();
}