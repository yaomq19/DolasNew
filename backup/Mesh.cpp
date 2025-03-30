#include "Mesh.h"
const D3D11_INPUT_ELEMENT_DESC Mesh::VertexPosColor::inputLayout[2] = {
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
};

void Mesh::Draw(ComPtr<ID3D11DeviceContext> d3d_context)
{
    // d3d_context->IASetInputLayout(m_input_layout.Get());
    d3d_context->IASetVertexBuffers(0, 1, m_vertex_buffer.GetAddressOf(), nullptr, nullptr);
    d3d_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    if (m_index_count > 0)
    {
        d3d_context->IASetIndexBuffer(m_index_buffer.Get(), DXGI_FORMAT_R32_UINT, 0);
        d3d_context->DrawIndexed(m_index_count, 0, 0); // 绘制网格
    }
    
    else
    {
        d3d_context->Draw(m_vertex_count, 0); // 绘制网格
    }
}

void Mesh::GenerateSphere(float radius, int slice, int stack)
{
    // const wchar_t* m_shader_filepath = L"" PROJECT_ROOT_DIR L"/HLSL/Triangle.hlsl";
    // const UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
    // // 定义顶点着色器的宏
    // D3D_SHADER_MACRO m_vs_defines[] = {
    //     {"VERTEX_SHADER", "1"},  // 定义 VERTEX_SHADER 宏
    //     {"PIXEL_SHADER", "0"},   // 明确取消 PIXEL_SHADER
    //     {nullptr, nullptr}       // 结束标记
    // };

    // // 定义像素着色器的宏
    // D3D_SHADER_MACRO m_ps_defines[] = {
    //     {"PIXEL_SHADER", "1"},   // 定义 PIXEL_SHADER 宏
    //     {"VERTEX_SHADER", "0"},  // 明确取消 VERTEX_SHADER
    //     {nullptr, nullptr}       // 结束标记
    // };

    // HR(D3DCompileFromFile(
    //     m_shader_filepath,
    //     m_vs_defines,
    //     D3D_COMPILE_STANDARD_FILE_INCLUDE,
    //     "VS_Entry",
    //     "vs_5_0",
    //     compileFlags,
    //     0,
    //     m_vs_blob.GetAddressOf(),
    //     nullptr
    // ));
    // HR(
    //     m_pd3dDevice->CreateVertexShader(
    //         m_vs_blob->GetBufferPointer(),
    //         m_vs_blob->GetBufferSize(),
    //         nullptr,
    //         m_pVertexShader.GetAddressOf()
    // ));

    // D3D11SetDebugObjectName(m_pVertexShader.Get(), "Trangle_VS");

    // m_pd3dDevice->CreateInputLayout(
    //     VertexPosColor::inputLayout,
    //     ARRAYSIZE(VertexPosColor::inputLayout),
    //     m_vs_blob->GetBufferPointer(),
    //     m_vs_blob->GetBufferSize(),
    //     m_pVertexLayout.GetAddressOf()
    // );
    // D3D11SetDebugObjectName(m_pVertexLayout.Get(), "VertexPosColorLayout");

    // HR(D3DCompileFromFile(
    //     m_shader_filepath,
    //     m_ps_defines,
    //     D3D_COMPILE_STANDARD_FILE_INCLUDE,
    //     "PS_Entry",
    //     "ps_5_0",
    //     compileFlags,
    //     0,
    //     m_ps_blob.GetAddressOf(),
    //     nullptr
    // ));
    // HR(
    //     m_pd3dDevice->CreatePixelShader(
    //         m_ps_blob->GetBufferPointer(),
    //         m_ps_blob->GetBufferSize(),
    //         nullptr,
    //         m_pPixelShader.GetAddressOf()
    // ));
    // D3D11SetDebugObjectName(m_pPixelShader.Get(), "Trangle_PS");

    // // 设置三角形顶点
    // VertexPosColor vertices[] =
    // {
    //     { XMFLOAT3(0.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
    //     { XMFLOAT3(0.5f, -0.5f, 0.5f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
    //     { XMFLOAT3(-0.5f, -0.5f, 0.5f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) }
    // };

    // // 设置顶点缓冲区描述
    // D3D11_BUFFER_DESC vbd;
    // ZeroMemory(&vbd, sizeof(vbd));
    // vbd.Usage = D3D11_USAGE_IMMUTABLE;
    // vbd.ByteWidth = sizeof vertices;
    // vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    // vbd.CPUAccessFlags = 0;
    // // 新建顶点缓冲区
    // D3D11_SUBRESOURCE_DATA InitData;
    // ZeroMemory(&InitData, sizeof(InitData));
    // InitData.pSysMem = vertices;
    // HR(m_pd3dDevice->CreateBuffer(&vbd, &InitData, m_pVertexBuffer.GetAddressOf()));
    // D3D11SetDebugObjectName(m_pVertexBuffer.Get(), "VertexBuffer");
}

void Mesh::GenerateCube(float width, float height, float depth)
{

}