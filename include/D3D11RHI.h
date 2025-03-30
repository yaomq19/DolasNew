#ifndef D3D11_RHI_H
#define D3D11_RHI_H

#include <d3d11.h>
class D3D11RHI
{
public:
    D3D11RHI() = default;
    ~D3D11RHI() = default;

    bool Initialize();
    void Clear();

    // Direct3D 11
    ID3D11Device* m_d3d_device;                    // D3D11设备
    ID3D11DeviceContext* m_d3d_immediate_context;   // D3D11设备上下文
    IDXGISwapChain* m_swap_chain;                  // D3D11交换链
};
#endif