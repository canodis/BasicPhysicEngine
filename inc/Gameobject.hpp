#pragma once

#include "VertexArrayObject.hpp"
#include "GameobjectManager.hpp"

class GameobjectManager;

class Gameobject
{
protected:
    VertexArrayObject   *m_Vao;
    unsigned int m_IndexCount;
    unsigned int m_VertexCount;
    friend  GameobjectManager;
public:
    GLuint textureIndex;
    Gameobject();
    ~Gameobject();
    void    draw();
    VertexArrayObject   *getVao() const {return (m_Vao);};
    unsigned int getIndexCount() const {return (m_IndexCount);};
    unsigned int getVertexCount() const {return (m_VertexCount);};
};