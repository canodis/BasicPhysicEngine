#include "GameobjectManager.hpp"

GameobjectManager::GameobjectManager(VertexArrayObjectManager *vaoManager)
{
    m_VaoManager = vaoManager;
}

Gameobject* GameobjectManager::create2dSquareColor(float width, float heigth, glm::vec4 color)
{
    std::vector<Object2dColor> vertices;
    std::vector<unsigned int> indices;
    Object2dColor v[4];

    v[0].pos = glm::vec2(-width / 2, heigth / 2);
    v[1].pos = glm::vec2(-width/ 2, -heigth / 2);
    v[2].pos = glm::vec2(width / 2, -heigth / 2);
    v[3].pos = glm::vec2(width / 2, heigth / 2);
    
    v[0].rgba = color;
    v[1].rgba = color;
    v[2].rgba = color;
    v[3].rgba = color;

    for (int i = 0; i < 4; i++)
    {
        vertices.push_back(v[i]);
    }
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(2);

    VertexArrayObject   *vao = new VertexArrayObject();
    vao->build(vertices, indices);
    m_VaoManager->addNewObject(vao);
    m_VaoMap.push_back(vao);
    Gameobject *gameobject = new Gameobject();
    gameobject->m_Vao = vao;
    gameobject->m_IndexCount = gameobject->m_Vao->getIndexCount();
    gameobject->m_VertexCount = gameobject->m_Vao->getVertexCount();
    return (gameobject);
}

Gameobject* GameobjectManager::create2dSquareTexture(float width, float heigth, GLuint textureIndex)
{
    std::vector<Object2dTex> vertices;
    std::vector<unsigned int> indices;

    Object2dTex v[4];

    v[0].pos = glm::vec2(-width / 2, heigth / 2);
    v[1].pos = glm::vec2(-width/ 2, -heigth / 2);
    v[2].pos = glm::vec2(width / 2, -heigth / 2);
    v[3].pos = glm::vec2(width / 2, heigth / 2);

    v[0].texCoord = glm::vec2(0, 0);
    v[1].texCoord = glm::vec2(0, 1);
    v[2].texCoord = glm::vec2(1, 1);
    v[3].texCoord = glm::vec2(1, 0);

    for (int i = 0; i < 4; i++)
    {
        vertices.push_back(v[i]);
    }
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(2);

    VertexArrayObject   *vao = new VertexArrayObject();
    vao->build(vertices, indices);
    m_VaoManager->addNewObject(vao);
    m_VaoMap.push_back(vao);
    Gameobject *gameobject = new Gameobject();
    gameobject->m_Vao = vao;
    gameobject->m_IndexCount = gameobject->m_Vao->getIndexCount();
    gameobject->m_VertexCount = gameobject->m_Vao->getVertexCount();
    gameobject->textureIndex = textureIndex;
    return (gameobject);
}

Gameobject* GameobjectManager::create2dCircleColor(float radius, glm::vec4 color, int numSegments)
{
    std::vector<Object2dColor> vertices;
    std::vector<unsigned int> indices;
        
    glm::vec2 center(0.0f);

    int screenWidth = 1920;
    int screenHeight = 1080;

    float radiusInPixelsX = (radius / static_cast<float>(screenWidth)) * 2.0f;
    float radiusInPixelsY = (radius / static_cast<float>(screenHeight)) * 2.0f;

    radiusInPixelsX = glm::clamp(radiusInPixelsX, 0.0f, 1.0f);
    radiusInPixelsY = glm::clamp(radiusInPixelsY, 0.0f, 1.0f);

    float angleIncrement = 3.14159265358979323846f * 2.0f / numSegments;

    for (int i = 0; i < numSegments; i++)
    {
        Object2dColor vertex;
        float angle = i * angleIncrement;
        vertex.pos = center + glm::vec2(radiusInPixelsX * std::cos(angle), radiusInPixelsY * std::sin(angle));
        vertex.rgba = color;
        vertices.push_back(vertex);
    }

    for (int i = 0; i < numSegments - 2; i++)
    {
        indices.push_back(0);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }

    VertexArrayObject* vao = new VertexArrayObject();
    vao->build(vertices, indices);
    m_VaoManager->addNewObject(vao);
    m_VaoMap.push_back(vao);
    Gameobject* gameobject = new Gameobject();
    gameobject->m_Vao = vao;
    gameobject->m_IndexCount = gameobject->m_Vao->getIndexCount();
    gameobject->m_VertexCount = gameobject->m_Vao->getVertexCount();
    return gameobject;
}
