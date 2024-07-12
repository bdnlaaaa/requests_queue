#include "Queue.h"
#include <iostream>

Queue::Queue() {}

Queue::~Queue() {}

void
Queue::populate(Request* request)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queue.push(request);
}

Request*
Queue::popFront()
{
    if (m_queue.empty())
        return {};
    std::lock_guard<std::mutex> lock(m_mutex);
    Request* request = m_queue.front();
    m_deleteQueue.push(request);
    m_queue.pop();
    return request;
}

void
Queue::cleanup()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    while (!m_deleteQueue.empty())
    {
        Request* request = m_deleteQueue.front();
        m_deleteQueue.pop();
        if (request)
            delete request;
    }

    while (!m_queue.empty())
    {
        Request* request = m_queue.front();
        m_queue.pop();
        if (request)
            delete request;
    }
}

bool
Queue::empty()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_queue.empty();
}