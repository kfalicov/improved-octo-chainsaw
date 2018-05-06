#version 400 core

in vec2 passTextureCoords;

out vec4 outputColor;

uniform sampler2D textureSampler;

void main()
{
	outputColor = texture(textureSampler,passTextureCoords);
}