#pragma once

class Gameobject;

#include "Gameobject.hpp"
#include "VertexArrayObjectManager.hpp"
#include <map>
#include "defines.hpp"
#include <vector>
#include <string>

class GameobjectManager
{
public:
    GameobjectManager(VertexArrayObjectManager *vaoManager);
    Gameobject* create2dSquareColor(float width, float heigth, glm::vec4 color);
    Gameobject* create2dSquareTexture(float width, float heigth, GLuint textureIndex);
    Gameobject* create2dCircleColor(float radius, glm::vec4 color, int numSegments);
private:
    std::vector<VertexArrayObject *>  m_VaoMap;
    VertexArrayObjectManager    *m_VaoManager;
};