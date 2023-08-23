#pragma once

#include "../glm/glm.hpp"
#include "Gameobject.hpp"

class Object : public Gameobject
{
public:
    Object() {};
    Object(glm::vec2 pos)
    {
        position = pos;
    };
    glm::vec2   position;
    Object& operator=(Gameobject *obj)
    {
        m_Vao = obj->getVao();
        m_IndexCount = obj->getIndexCount();
        m_VertexCount = obj->getVertexCount();
        return (*this);
    }
private:

};