#include "GameApp.h"
#include "D3DUtil.h"
#include "DXTrace.h"
#include "Mesh.h"
using namespace DirectX;



GameApp::GameApp(HINSTANCE hInstance, const std::wstring& windowName, int initWidth, int initHeight)
    : D3DApp(hInstance, windowName, initWidth, initHeight)
{
    m_shader_manager = new ShaderManager();
}

GameApp::~GameApp()
{
    if (m_shader_manager)
    {
        delete m_shader_manager;
        m_shader_manager = nullptr;
    }
}

bool GameApp::Init()
{
    if (!D3DApp::Init())
        return false;
        m_shader_manager->Initialize();
    return true;
}

bool GameApp::Clear()
{
    return m_shader_manager->Clear();
}

void GameApp::OnResize()
{
    D3DApp::OnResize();
}

void GameApp::UpdateScene(float dt)
{
}

void GameApp::DrawScene()
{
    static float blue[4] = { 0.0f, 0.0f, 1.0f, 1.0f };  // RGBA = (0,0,255,255)
    m_pd3dImmediateContext->ClearRenderTargetView(m_pRenderTargetView.Get(), blue);
    m_pd3dImmediateContext->ClearDepthStencilView(m_pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    m_pd3dImmediateContext->OMSetRenderTargets(1, m_pRenderTargetView.GetAddressOf(), m_pDepthStencilView.Get());
    Mesh mesh;
    mesh.GenerateSphere(1.0f, 10, 10);
    ComPtr<ID3D11VertexShader> vertexShader;
    mesh.Draw(m_pd3dImmediateContext.Get());

    HR(m_pSwapChain->Present(0, 0));
}
