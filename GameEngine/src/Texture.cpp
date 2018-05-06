#include "Texture.h"



Texture::Texture(GLuint id) : _texture(id)
{
}


Texture::~Texture()
{
}

GLuint Texture::getID()
{
	return _texture;
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, _texture);
}
