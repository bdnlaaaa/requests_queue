#pragma once

class Request
{
public:
    ~Request();
    static Request* getRequest() noexcept;
    static void processRequest(Request* request) noexcept;

private:
    Request();
};
