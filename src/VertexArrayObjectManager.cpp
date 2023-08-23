#include "VertexArrayObjectManager.hpp"

VertexArrayObjectManager::VertexArrayObjectManager()
{
    
}

void VertexArrayObjectManager::addNewObject(VertexArrayObject *vao)
{
    m_VaoMap.push_back(vao);
}
