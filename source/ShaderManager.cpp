#include "ShaderManager.h"

ComPtr<ID3D11VertexShader> ShaderManager::GetDefaultVertexShader(const std::string& shaderName)
{
    auto it = m_default_vertex_shaders.find(shaderName);
    if (it != m_default_vertex_shaders.end())
    {
        return it->second;
    }
    return nullptr;
}

ComPtr<ID3D11PixelShader> ShaderManager::GetDefaultPixelShader(const std::string& shaderName)
{
    auto it = m_default_pixel_shaders.find(shaderName);
    if (it != m_default_pixel_shaders.end())
    {
        return it->second;
    }
    return nullptr;
}

bool ShaderManager::initialize()
{
    
}