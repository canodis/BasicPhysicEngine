#pragma once

class PhysicalObject;

#include "../glm/glm.hpp"
#include "defines.hpp"
#include <iostream>
#include "Player.hpp"

class PhysicalObject
{
public:
    PhysicalObject(std::vector<Player*> &objects) : m_PhysicalObjects(objects) {};
    void    updatePosition(float dt)
    {
        for (auto &object : m_PhysicalObjects)
        {
            const glm::vec2 velocity = object->position - object->oldPosition;
            object->oldPosition = object->position;
            object->position = object->position + velocity + object->m_Acceleration * dt * dt;
            object->m_Acceleration = glm::vec2(0.0f, 0.0f);
        }
        
    }

    void    accelerate(glm::vec2 &acceleration)
    {
        for (auto &object : m_PhysicalObjects)
            object->m_Acceleration += acceleration;
    }

    void    update(float dt)
    {
        applyGravity();
        applyConstrains();
        solveCollisions();
        updatePosition(dt);
    }

    void    applyGravity()
    {
        for (auto &object : m_PhysicalObjects)
            accelerate(object->m_Gravity);
    }

    void    applyConstrains()
    {
        for (auto &object : m_PhysicalObjects)
        {
            glm::vec2 pos{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
            const float radius = 400.0f;
            const glm::vec2 to_obj = object->position - pos;
            const float dist = glm::length(to_obj);
            if (dist > radius - 20.0f)
            {
                const glm::vec2 n = to_obj / dist;
                object->position = object->position - n * (dist - radius + 20.0f);
            }
        }
    }

    void    solveCollisions()
    {
        const int objectCount = m_PhysicalObjects.size();
        for (int i = 0; i < objectCount; i++)
        {
            Player* object1 = m_PhysicalObjects[i];
            for (int k = i + 1; k < objectCount; k++)
            {
                Player* object2 = m_PhysicalObjects[k];
                const glm::vec2 collision_axis = object1->position - object2->position;
                const float dist = glm::length(collision_axis);
                if (dist < 40.0f)
                {
                    const glm::vec2 n = collision_axis / dist;
                    const float delta = 40.0f - dist;
                    object1->position += 0.5f * delta * n;
                    object2->position -= 0.5f * delta * n;
                }
            }
        }
    }
public:
    std::vector<Player*> &m_PhysicalObjects;
};
