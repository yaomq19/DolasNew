#ifndef WINDOWS_PLATFORM_H
#define WINDOWS_PLATFORM_H
#include "DolasCommon.h"
LRESULT CALLBACK
MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // Forward hwnd on because we can get messages (e.g., WM_CREATE)
    // before CreateWindow returns, and thus before m_hMainWnd is valid.
    return g_dolas_context.m_windows_platform->MsgProc(hwnd, msg, wParam, lParam);
}

class WindowsPlatform : public DolasBase
{
public:
    WindowsPlatform() = default;
    ~WindowsPlatform() = default;
    LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    bool Initialize(HINSTANCE hInstance, int client_width, int client_height, std::wstring windowName)
    {
        m_client_width = client_width;
        m_client_height = client_height;
        m_app_instance = hInstance;
        m_main_window_caption = windowName;

        WNDCLASS wc;
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = MainWndProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        wc.hIcon = LoadIcon(0, IDI_APPLICATION);
        wc.hCursor = LoadCursor(0, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
        wc.lpszMenuName = 0;
        wc.lpszClassName = L"D3DWndClassName";

        if (!RegisterClass(&wc))
        {
            MessageBox(0, L"RegisterClass Failed.", 0, 0);
            return false;
        }

        // Compute window rectangle dimensions based on requested client area dimensions.
        RECT R = { 0, 0, m_client_width, m_client_height };
        AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
        int width = R.right - R.left;
        int height = R.bottom - R.top;

        m_main_window = CreateWindow(L"D3DWndClassName", m_main_window_caption.c_str(),
            WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, 0, 0, m_app_instance, 0);
        if (!m_main_window)
        {
            MessageBox(0, L"CreateWindow Failed.", 0, 0);
            return false;
        }

        ShowWindow(m_main_window, SW_SHOW);
        UpdateWindow(m_main_window);

        return true;
    }
    void Clear() override;

    int m_client_width = 0; // 客户区宽度
    int m_client_height = 0; // 客户区高度
    HINSTANCE m_app_instance;        // 应用实例句柄
    HWND      m_main_window;        // 主窗口句柄
    std::wstring m_main_window_caption;                       // 主窗口标题
};
#endif