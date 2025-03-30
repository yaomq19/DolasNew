struct VertexIn
{
    float3 pos : POSITION;
    float4 color : COLOR;
};

struct VertexOut
{
    float4 posH : SV_POSITION;
    float4 color : COLOR;
};

// 顶点着色器
#if defined(VERTEX_SHADER)
VertexOut VS_Entry(VertexIn vIn)
{
    VertexOut vOut;
    vOut.posH = float4(vIn.pos, 1.0f);
    vOut.color = vIn.color; // 这里alpha通道的值默认为1.0
    return vOut;
}
#endif


// 像素着色器
#if defined(PIXEL_SHADER)
float4 PS_Entry(VertexOut pIn) : SV_Target
{
    return pIn.color;   
}
#endif