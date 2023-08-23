#include "Game.hpp"
#include "Player.hpp"
#include "Timer.hpp"
#include "Object.hpp"
#include "Physics.hpp"

Scene   *scene;
Player player({SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2});
Object object({SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2});


bool keystates[256];

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        keystates[key] = true;
    } else if (action == GLFW_RELEASE) {
        keystates[key] = false;
    }
}

void    player_movement()
{
    if (keystates[GLFW_KEY_W])
        player.position.y -= 1;
    if (keystates[GLFW_KEY_S])
        player.position.y += 1;
    if (keystates[GLFW_KEY_A])
        player.position.x -= 1;
    if (keystates[GLFW_KEY_D])
        player.position.x += 1;
}

Player  *createPlayer(float radius, int segments)
{
    Player *p = new Player({Random::getRandomFloat(SCREEN_WIDTH / 2 - 300, SCREEN_WIDTH / 2 + 300), Random::getRandomFloat(SCREEN_HEIGHT / 2 - 300, SCREEN_HEIGHT / 2 + 300)});
    *p = scene->gameobjectManager->create2dCircleColor(radius, glm::vec4(Random::getRandomVec3(0.3f, 1), 1), segments);
    return (p);
}

void    initObjects(std::vector<Player*> &objects, int count)
{
    for (int i = 0; i < count; i++)
    {
        Player *player = createPlayer(50, 100);
        objects.push_back(player);
    }
}

int main(int ac, char **av)
{
    scene = new Scene(SCREEN_WIDTH, SCREEN_HEIGHT);
    Timer timer;
    PhysicalObject ps;

    std::vector<Player*> objects;
    initObjects(objects, 20);
    GLuint texture = scene->textureManager->loadTexture("textures/grass_block.png", GL_RGBA);
    player = scene->gameobjectManager->create2dCircleColor(50, glm::vec4(1,0,0,1), 100);
    object = scene->gameobjectManager->create2dCircleColor(400, glm::vec4(0, 0, 0, 1), 100);
    object.position = glm::vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    scene->shaderProgram->addUniform("ObjTransform");
    glm::vec2 normalizedCoordinates;
    objects.push_back(&player);
    glfwSetKeyCallback(scene->window, key_callback);
    ps.m_PhysicalObjects = objects;
    while (glfwGetKey(scene->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(scene->window))
    {
        glClearColor(185.0f/255.0f, 185.0f/255.0f, 185.0f/255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        normalizedCoordinates.x = (2.0f * object.position.x) / SCREEN_WIDTH - 1.0f;
        normalizedCoordinates.y = 1.0f - (2.0f * object.position.y) / SCREEN_HEIGHT;
        scene->shaderProgram->setVec2("ObjTransform", glm::vec2(normalizedCoordinates.x, normalizedCoordinates.y));
        object.draw();
        double elapsedTime = timer.elapsedSeconds();
        player_movement();
        ps.update(elapsedTime);
        for (auto& obj : objects)
        {
            normalizedCoordinates.x = (2.0f * obj->position.x) / SCREEN_WIDTH - 1.0f;
            normalizedCoordinates.y = 1.0f - (2.0f * obj->position.y) / SCREEN_HEIGHT;
            scene->shaderProgram->setVec2("ObjTransform", glm::vec2(normalizedCoordinates.x, normalizedCoordinates.y));
            obj->draw();
        }
        glfwSwapBuffers(scene->window);
        glfwPollEvents();
    }
}

