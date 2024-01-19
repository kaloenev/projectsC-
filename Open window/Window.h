#pragma once

#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

class Window
{
public:
	Window();
	~Window();
	HWND getHandle() {
		return hwnd;
	}

	bool ProcessMessage();

private:
	HINSTANCE hInstance;
	HWND hwnd;

};

