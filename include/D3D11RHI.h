#ifndef D3D11_RHI_H
#define D3D11_RHI_H

class D3D11RHI
{
public:
    D3D11RHI() = default;
    ~D3D11RHI() = default;

    bool Initialize();
    void Clear();
};
#endif