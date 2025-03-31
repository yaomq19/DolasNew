#include "DXTrace.h"
#include "Dolas.h"
#include "D3D11RHI.h"
#include "WindowsPlatform.h"
bool D3D11RHI::Initialize()
{
    HRESULT hr = S_OK;

    // 创建D3D设备 和 D3D设备上下文
    UINT createDeviceFlags = 0;
#if defined(DEBUG) || defined(_DEBUG)  
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    // 特性等级数组
    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
    };

    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 1;                              // 后台缓冲区数量
    sd.BufferDesc.Width = 640;                       // 分辨率宽度
    sd.BufferDesc.Height = 480;                      // 分辨率高度
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // 颜色格式（RGBA 32位）
    sd.BufferDesc.RefreshRate.Numerator = 60;         // 刷新率分子
    sd.BufferDesc.RefreshRate.Denominator = 1;        // 刷新率分母
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // 缓冲区用途（渲染目标）
    sd.OutputWindow = g_dolas_context.m_windows_platform->m_main_window;  // 目标窗口句柄
    sd.SampleDesc.Count = 1;                         // 多重采样数量（禁用）
    sd.Windowed = TRUE;                               // 窗口模式

    D3D_FEATURE_LEVEL selectedFeatureLevel;
    HR(
        D3D11CreateDeviceAndSwapChain(
            nullptr,                    // 使用默认显卡适配器
            D3D_DRIVER_TYPE_HARDWARE,  // 硬件驱动类型
            nullptr,                    // 非软件光栅器（HARDWARE模式下忽略）
            createDeviceFlags,                         // 标志（如启用调试层：D3D11_CREATE_DEVICE_DEBUG）
            featureLevels,             // 功能级别数组
            ARRAYSIZE(featureLevels),          // 数组长度
            D3D11_SDK_VERSION,          // SDK 版本
            &sd,                        // 交换链描述结构
            &m_swap_chain,               // 返回交换链指针
            &m_d3d_device,                  // 返回设备指针
            &selectedFeatureLevel,     // 返回实际支持的最高功能级别
            &m_d3d_immediate_context                  // 返回即时上下文指针
        )
    )

    return true;
}

void D3D11RHI::Clear()
{
}