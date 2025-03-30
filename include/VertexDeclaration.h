#ifndef VERTEX_DECLARATION_H
#define VERTEX_DECLARATION_H

enum class VertexDeclaration : unsigned int
{
    VertexPosColor = 0,
    VertexPosNormal = 1,
    VertexPosTexCoord = 2,
    VertexPosNormalTexCoord = 3,
    VertexPosTangentTexCoord = 4,
    VertexPosNormalTangentTexCoord = 5,
    VertexPosNormalTangentBinormalTexCoord = 6
};
#endif