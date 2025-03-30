#ifndef MESH_H
#define MESH_H
#include <d3d11.h>
#include <string>
#include <wrl/client.h>
#include <DirectXMath.h>

class Mesh
{
public:
    template <class T>
    using ComPtr = Microsoft::WRL::ComPtr<T>;

    struct VertexPosColor
    {
        DirectX::XMFLOAT3 position; // 顶点位置
        DirectX::XMFLOAT4 color;    // 顶点颜色

        static const D3D11_INPUT_ELEMENT_DESC inputLayout[2]; // 输入布局描述
    };

    Mesh() = default;
    virtual ~Mesh() = default;

    void Draw(ComPtr<ID3D11DeviceContext> d3d_context); // 绘制网格
    void GenerateSphere(float radius, int slice, int stack); // 生成球体网格
    void GenerateCube(float width, float height, float depth); // 生成立方体网格
    void LoadFromFile(const std::string& filename); // 从文件加载网格数据
    
private:
    ComPtr<ID3D11InputLayout> m_input_layout; // 输入布局
    ComPtr<ID3D11Buffer> m_vertex_buffer; // 顶点缓冲区
    ComPtr<ID3D11Buffer> m_index_buffer; // 索引缓冲区

    int m_vertex_count = 0;
    int m_index_count = 0;
};

#endif