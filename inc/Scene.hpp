#pragma once
# include "VertexArrayObjectManager.hpp"
# include "ShaderProgram.hpp"
# include "GameobjectManager.hpp"
# include "TextureManager.hpp"
# include <glad.h>
# include <glfw3.h>

class Scene
{
public:
	Scene(int width, int height);
	VertexArrayObjectManager	*vaoManager;
	ShaderProgram				*shaderProgram;
	GameobjectManager			*gameobjectManager;
	TextureManager				*textureManager;
	GLFWwindow  				*window;
private:
	void	init_window(int width, int height);
};
