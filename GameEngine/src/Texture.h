#ifndef _TEXTURE_H
#define _TEXTURE_H
#include <glew.h>
#include <glfw3.h>

/*
	Stores information about a Texture
*/
class Texture
{
public:
	
	/*
		Creates a new texture
		@param The location of the texture
	*/
	Texture(GLuint id);

	/*
		Destroys the texture
	*/
	~Texture();

	/*
		Returns the location of the texture
		@return Returns the location of the texture
	*/
	GLuint getID();

	/*
		Binds the texture so it can be rendered
	*/
	void bind();
private:
	GLuint _texture;
};

#endif