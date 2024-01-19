// Open window.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Window.h"

int main()
{
    std::cout << "Creating new Window\n";
    Window* window = new Window();
    Window* window2 = new Window();
    bool running = true;
    bool running2 = true;

    int width = 1080;
    int height = 480;

    HWND handle = window->getHandle();

    ::SetWindowPos(handle, 0, 1000, 2000, width, height, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

    while (running) {
        if (!window->ProcessMessage())
        {
            std::cout << "Closing window";
            running = false;
        }
        if (!window2->ProcessMessage())
        {
            std::cout << "Closing window2";
            running = false;
        }
        Sleep(10);
    }

    delete window;
    delete window2;

    return 0;

}