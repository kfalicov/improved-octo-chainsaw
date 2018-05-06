#ifndef _RENDERER_H
#define _RENDERER_H
#include <glew.h>
#include <glfw3.h>
#include "Mesh.h"
#include "TexturedMesh.h"
#include "Util.h"
#include "StaticShader.h"
#include "Entity.h"
#include <vector>

/*
	Renders the game.
*/
class Renderer
{
public:
	/*
		Creates a new renderer
	*/
	Renderer();

	/*
		Destroys the rendereer
	*/
	~Renderer();

	/*
		Clears the screen and relevent buffer bits
	*/
	void clearScreen();

	/*
		Draws entities based on the shader passed in
		@param entities The entities to draw
		@param shader The shader to use
	*/
	void draw(std::vector<Entity*>* entities, StaticShader* shader);
private:

protected:

};

#endif