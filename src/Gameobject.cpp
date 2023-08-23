#include "Gameobject.hpp"

void    Gameobject::draw()
{
    m_Vao->activate();
    glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, 0);
    m_Vao->deactivate();
}

Gameobject::Gameobject()
{
}

Gameobject::~Gameobject()
{
    // delete m_Vao;
}