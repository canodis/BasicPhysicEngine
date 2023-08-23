#version 330 core
layout (location = 0) in vec2 inPos;
layout (location = 1) in vec4 inColor;

out vec4 ObjColor;
uniform vec2 ObjTransform;

void main()
{
    gl_Position = vec4(inPos + ObjTransform, 0.0, 1.0);
    ObjColor = inColor;
}