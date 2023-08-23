#pragma once

#include <vector>
#include <iostream>

class VertexArrayObject;

class VertexArrayObjectManager
{
public:
    VertexArrayObjectManager();
    void addNewObject(VertexArrayObject *vao);
private:
    std::vector< VertexArrayObject *>  m_VaoMap;
};
