#ifndef DOLAS_H
#define DOLAS_H
#include <windows.h>
#include <string>
#include "WindowsPlatform.h"
// #include "ShaderManager.h"
#include "D3D11RHI.h"

class Dolas
{
    public:
    Dolas()
    {
        m_windows_platform = new WindowsPlatform();
        m_d3d11_rhi = new D3D11RHI();
        //m_shader_manager = new ShaderManager();
        
    }
    ~Dolas()
    {
        if (m_windows_platform)
        {
            delete m_windows_platform;
            m_windows_platform = nullptr;
        }
        if (m_d3d11_rhi)
        {
            delete m_d3d11_rhi;
            m_d3d11_rhi = nullptr;
        }
        // if (m_shader_manager)
        // {
        //     delete m_shader_manager;
        //     m_shader_manager = nullptr;
        // }
        
    }
    bool Initialize(HINSTANCE hInstance, int client_width, int client_height, std::wstring windowName = L"Dolas")
    {
        m_windows_platform->Initialize(hInstance, client_width, client_height, windowName);
        m_d3d11_rhi->Initialize();
        // m_shader_manager->Initialize();
        return true;
    }
    void Run()
    {

    }
    void Clear()
    {
        // m_d3d11_rhi->Clear();
        // m_shader_manager->Clear();
    }
    WindowsPlatform* m_windows_platform = nullptr;
    D3D11RHI* m_d3d11_rhi = nullptr;
    // ShaderManager* m_shader_manager = nullptr;
    
};
extern Dolas g_dolas_context;
#endif