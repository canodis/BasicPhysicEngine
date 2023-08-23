#include "Camera.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/glm.hpp"
#include <glfw3.h>

Camera  *c;

Camera::Camera(Scene *s)
{
    scene = s;
    rotation = glm::mat4(1.0f);
    transform = glm::vec3(0.0f);
    mtxTransition = glm::mat4(1.0f);
    camPosition = glm::vec3(0.0f, 0.0f, 10.0f);
    camLookAt = glm::vec3(0.0f, 0.0f, 0.0f);
    camUp = glm::vec3(0.0f, 1.0f, 0.0f);
    mtxCam = glm::lookAt(camPosition, camLookAt, camUp);
    mtxProj = glm::perspective(glm::radians(80.0f), 5120.0f / 2880.0f, .2f, 100.0f);
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

    firstMouse = true;
    yaw   = -90.0f;
    pitch =  0.0f;
    lastX =  800.0f / 2.0;
    lastY =  800.0f / 2.0;
    cameraSpeed = .55f;
    c = this;
}

void Camera::processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camPosition += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camPosition -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camPosition -= glm::normalize(glm::cross(cameraFront, camUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camPosition += glm::normalize(glm::cross(cameraFront, camUp)) * cameraSpeed;
}

void Camera::mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (c->firstMouse)
    {
        c->lastX = xpos;
        c->lastY = ypos;
        c->firstMouse = false;
    }

    float xoffset = xpos - c->lastX;
    float yoffset = c->lastY - ypos;
    c->lastX = xpos;
    c->lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    c->yaw += xoffset;
    c->pitch += yoffset;

    if (c->pitch > 89.0f)
        c->pitch = 89.0f;
    if (c->pitch < -89.0f)
        c->pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(c->yaw)) * cos(glm::radians(c->pitch));
    front.y = sin(glm::radians(c->pitch));
    front.z = sin(glm::radians(c->yaw)) * cos(glm::radians(c->pitch));
    c->cameraFront = glm::normalize(front);
}

void Camera::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if ((key == GLFW_KEY_F) && (action == GLFW_PRESS))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if ((key == GLFW_KEY_P) && (action == GLFW_PRESS))
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    if ((key == GLFW_KEY_L) && (action == GLFW_PRESS))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if ((key == GLFW_KEY_2) && (action == GLFW_PRESS))
        glEnable(GL_MULTISAMPLE);
    if ((key == GLFW_KEY_3) && (action == GLFW_PRESS))
        glDisable(GL_MULTISAMPLE);
    if ((key == GLFW_KEY_LEFT_SHIFT) && (action == GLFW_PRESS))
        c->cameraSpeed = 5.0f;
    if ((key == GLFW_KEY_LEFT_SHIFT) && (action == GLFW_RELEASE))
        c->cameraSpeed = .55f;
    if ((key == GLFW_KEY_Q) && (action == GLFW_PRESS)) {
        c->texX += 1.0f/16.0f;
        c->scene->shaderProgram->setFloat("shiftX", c->texX);
    }
    if ((key == GLFW_KEY_E) && (action == GLFW_PRESS)) {
        c->texY += 1.0f/16.0f;
        c->scene->shaderProgram->setFloat("shiftY", c->texY);
    }
}
