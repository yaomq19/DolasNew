#ifndef WINDOWS_PLATFORM_H
#define WINDOWS_PLATFORM_H
#include <windows.h>
#include <string>


LRESULT CALLBACK
MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class WindowsPlatform
{
public:
    WindowsPlatform() = default;
    ~WindowsPlatform() = default;
    LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    bool Initialize(HINSTANCE hInstance, int client_width, int client_height, std::wstring windowName);
    void Clear();
    int m_client_width = 0; // 客户区宽度
    int m_client_height = 0; // 客户区高度
    HINSTANCE m_app_instance;        // 应用实例句柄
    HWND      m_main_window;        // 主窗口句柄
    std::wstring m_main_window_caption;                       // 主窗口标题
};
#endif