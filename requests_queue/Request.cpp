#include "Request.h"
#include <exception>
#include <iostream>
#include <thread>

Request::Request()
{
    std::cout << "request created" << std::endl;
}

Request::~Request()
{
    std::cout << "request destroyed" << std::endl;
}

Request*
Request::getRequest() noexcept
{
    try
    {
        return new Request();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
        return nullptr;
    }
}

void
Request::processRequest(Request* request) noexcept
{
    try
    {
        if (!request)
            return;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "request processed" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
}