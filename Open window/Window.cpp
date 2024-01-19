#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg) {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_NCHITTEST:
    {

        POINTS pt = MAKEPOINTS(lparam);

        RECT rc;
        GetWindowRect(hwnd, &rc);

        if (pt.x >= rc.left && pt.x < rc.left + 5)
        {
            return HTLEFT;
        }
        else if (pt.x < rc.right && pt.x >= rc.right - 5)
        {
            return HTRIGHT;
        }
        else if (pt.y >= rc.top && pt.y < rc.top + 5)
        {
            return HTTOP;
        }
        else if (pt.y < rc.bottom && pt.y >= rc.bottom - 5)
        {
            return HTBOTTOM;
        }
        return HTCLIENT;
    }
    }

    return DefWindowProc(hwnd, msg, wparam, lparam);
}

Window::Window()
    : hInstance(GetModuleHandle(nullptr))
{
    const wchar_t* CLASS_NAME = L"New Window";
    WNDCLASS wndclass = {};
    wndclass.lpszClassName = CLASS_NAME;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpfnWndProc = WindowProc;
    wndclass.hbrBackground = CreateSolidBrush(RGB(48, 8, 64));

    RegisterClass(&wndclass);

    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_THICKFRAME;

    int width = 640;
    int length = 480;

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + length;

    AdjustWindowRect(&rect, style, false);

    hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"New Window",
        style,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    ShowWindow(hwnd, SW_SHOW);
}

Window::~Window()
{
    const wchar_t* CLASS_NAME = L"New Window";
    UnregisterClass(CLASS_NAME, hInstance);

}

bool Window::ProcessMessage()
{
    MSG msg = {};
    while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {
        if (msg.message == WM_QUIT)
        {
            return false;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}
