﻿#include "Manager.h"
#include <conio.h>
#include <iostream>

int
main()
{
    Manager manager;
    manager.start();
    while (true)
    {
        if (_kbhit())
        {
            manager.stop();
            break;
        }
    }
    return 0;
}