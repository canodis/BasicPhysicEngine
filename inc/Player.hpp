#pragma once

class Player;

#include "../glm/glm.hpp"
#include "Gameobject.hpp"

class Player : public Gameobject
{
public:
    Player() {};
    Player(glm::vec2 pos)
    {
        position = pos;
        oldPosition = pos;
    };
    ~Player() {};
    Player& operator=(Gameobject *obj)
    {
        m_Vao = obj->getVao();
        m_IndexCount = obj->getIndexCount();
        m_VertexCount = obj->getVertexCount();
        return (*this);
    }
public:
    glm::vec2   position;
    glm::vec2   oldPosition;
    glm::vec2   m_Acceleration;
    glm::vec2   m_Gravity = {0, 200};
private:
};