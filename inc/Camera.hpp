#pragma once

# include "../glm/glm.hpp"
class Scene;
#include "Scene.hpp"

class GLFWwindow;

class Camera
{
public:
	Scene *scene;
	Camera(Scene *s);
	glm::vec3   transform;
	glm::mat4   rotation;
	glm::mat4   mtxTransition;
	glm::vec3   camPosition;
	glm::vec3   camLookAt;
	glm::vec3   camUp;
	glm::mat4   mtxCam;
	glm::mat4   mtxProj;
	glm::vec3 cameraFront;
	void processInput(GLFWwindow *window);
	static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
	static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
private:
	bool	firstMouse;
	float	yaw;
	float	pitch;
	float	lastX;
	float	lastY;
	float	cameraSpeed;
	float	texX;
	float	texY;
};
