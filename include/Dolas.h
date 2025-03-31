#ifndef DOLAS_H
#define DOLAS_H
#include <windows.h>
class Dolas
{
public:
    Dolas();
    ~Dolas();
    bool Initialize(HINSTANCE hInstance);
    void Run();
    void Clear();

    class CpuTimer* m_cpu_timer = nullptr;
    class WindowsPlatform* m_windows_platform = nullptr;
    class D3D11RHI* m_d3d11_rhi = nullptr;
    class ShaderManager* m_shader_manager = nullptr;
    
private:
    void UpdateScene(float delta_time);
    void DrawScene();
};
extern Dolas g_dolas_context;
#endif