#version 330 core

out vec4 FragColor;

in vec4 ObjColor;

void main()
{
	FragColor = ObjColor;
}