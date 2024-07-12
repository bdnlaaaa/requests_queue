#pragma once

#include "Queue.h"
#include <atomic>
#include <thread>
#include <vector>

class Manager
{
public:
    Manager();
    ~Manager();
    void stop();
    void start();

private:
    Queue m_queue;
    std::atomic<bool> m_running = true;
    std::vector<std::thread> m_threads;
};
