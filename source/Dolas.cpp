#include "Dolas.h"
#include "DolasSupport.h"
#include "CpuTimer.h"
#include "WindowsPlatform.h"
#include "D3D11RHI.h"
// #include "ShaderManager.h"
Dolas g_dolas_context;

Dolas::Dolas()
{
    m_cpu_timer = DOLAS_NEW(CpuTimer);
    m_windows_platform = DOLAS_NEW(WindowsPlatform);
    m_d3d11_rhi = DOLAS_NEW(D3D11RHI);
    // m_shader_manager = DOLAS_NEW(ShaderManager);
    
}

Dolas::~Dolas()
{
    DOLAS_DELETE(m_cpu_timer)
    DOLAS_DELETE(m_windows_platform)
    DOLAS_DELETE(m_d3d11_rhi)
    // DOLAS_DELETE(m_shader_manager)    
}

bool Dolas::Initialize(HINSTANCE hInstance)
{
    m_cpu_timer->Start();
    m_windows_platform->Initialize(hInstance, 800, 600, L"Dolas Editor");
    m_d3d11_rhi->Initialize();
    // m_shader_manager->Initialize();
    return true;
}

void Dolas::Run()
{
    MSG msg = { 0 };

    m_cpu_timer->Reset();

    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            m_cpu_timer->Tick();
            UpdateScene(m_cpu_timer->DeltaTime());
            DrawScene();
        }
    }

}

void Dolas::Clear()
{
    m_cpu_timer->Stop();
    m_windows_platform->Clear();
    m_d3d11_rhi->Clear();
    // m_shader_manager->Clear();
}

void Dolas::UpdateScene(float delta_time)
{

}

void Dolas::DrawScene()
{
    
}