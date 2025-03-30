#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H
#include "Common.h"

class ShaderManager
{
public:
    ShaderManager() = default;
    virtual ~ShaderManager() = default;

    ComPtr<ID3D11VertexShader> GetDefaultVertexShader(const std::string& shaderName);
    ComPtr<ID3D11PixelShader> GetDefaultPixelShader(const std::string& shaderName);
    bool Initialize();
    bool Clear();
private:
    std::map<std::string, ComPtr<ID3D11VertexShader>> m_default_vertex_shaders;
    std::map<std::string, ComPtr<ID3D11PixelShader>> m_default_pixel_shaders;
};
#endif