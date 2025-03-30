#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include <d3d11.h>
#include <wrl/client.h>
#include <string>
#include <map>
//template <class T>
//using ComPtr = Microsoft::WRL::ComPtr<T>;

class ShaderManager
{
public:
    ShaderManager() = default;
    virtual ~ShaderManager() = default;

    ComPtr<ID3D11VertexShader> GetVertexShader(const std::string& shaderName);
    ComPtr<ID3D11PixelShader> GetPixelShader(const std::string& shaderName);
    bool Initialize();
    void Clear(){};
    void AddVertexShader(const std::string& shaderName, const std::string& shaderFileName)
    {
        ComPtr<ID3DBlob> blob = nullptr;
        HR(D3DReadFileToBlob(L"YourShader.cso", blob.GetAddressOf()));
        m_default_vertex_blobs[shaderName] = blob;

        ComPtr<ID3D11VertexShader> shader = nullptr;
        // HR(m_pd3dDevice->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, shader.GetAddressOf()));
        m_default_vertex_shaders[shaderName] = shader;
    }
    void AddPixelShader(const std::string& shaderName, const std::string& shaderFileName);
private:
    std::map<std::string, ComPtr<ID3DBlob>> m_default_vertex_blobs;
    std::map<std::string, ComPtr<ID3D11VertexShader>> m_default_vertex_shaders;
    std::map<std::string, ComPtr<ID3D11PixelShader>> m_default_pixel_shaders;
};
#endif