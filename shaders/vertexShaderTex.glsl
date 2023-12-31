#version 330 core
layout (location = 0) in vec2 inPos;
layout (location = 1) in vec2 aTexCoord;

uniform vec2 ObjTransform;
out vec2 TexCoord;

void main()
{
    gl_Position = vec4(inPos + ObjTransform, 0.0, 1.0);
    TexCoord = aTexCoord;
}