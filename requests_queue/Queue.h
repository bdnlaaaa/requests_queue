#pragma once

#include "Request.h"
#include <mutex>
#include <queue>

class Queue
{
public:
    Queue();
    ~Queue();
    void populate(Request* data);
    void cleanup();
    Request* popFront();
    bool empty();

private:
    std::queue<Request*> m_queue;
    std::queue<Request*> m_deleteQueue;
    std::mutex m_mutex;
};