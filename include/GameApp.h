#ifndef GAMEAPP_H
#define GAMEAPP_H
#include <d3dcompiler.h>
#include "d3dApp.h"
#include "ShaderManager.h"
class GameApp : public D3DApp
{
public:
    // 使用宏拼接 HLSL 文件路径
    const std::wstring project_path = L"" PROJECT_ROOT_DIR;

    

    GameApp(HINSTANCE hInstance, const std::wstring& windowName, int initWidth, int initHeight);
    ~GameApp();

    bool Init();
    bool Clear();
    void OnResize();
    void UpdateScene(float dt);
    void DrawScene();

private:

    ComPtr<ID3DBlob> m_vs_blob;
    ComPtr<ID3DBlob> m_ps_blob;
    ComPtr<ID3D11InputLayout> m_pVertexLayout;	// 顶点输入布局
    ComPtr<ID3D11Buffer> m_pVertexBuffer;		// 顶点缓冲区
    ComPtr<ID3D11VertexShader> m_pVertexShader;	// 顶点着色器
    ComPtr<ID3D11PixelShader> m_pPixelShader;	// 像素着色器
    
    ShaderManager* m_shader_manager = nullptr; // 着色器管理器
};


#endif