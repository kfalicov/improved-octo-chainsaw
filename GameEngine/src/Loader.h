#ifndef _LOADER_H
#define _LOADER_H
#include <glew.h>
#include <SOIL.h>
#include <glfw3.h>
#include <stdio.h>
#include "Mesh.h"
#include "Util.h"
#include <iostream>
#include <vector>

/*
	Loads files/meshes/textures into the game
	Loading meshes is based off of the ThinMatrix's implementation
*/
class Loader
{
public:

	/*
		Loads a mesh and returns the resulting mesh
		@param positions The array of vertices that make up the mesh
		@param indices The array of indices that say how to connect the vertices
		@param textureCoords The array of texture coordinates
		@param vertexCount The number of vertices in the mesh
		@param indicesCount The number of indices in the mesh
		@return Returns a loaded mesh
	*/
	Mesh* loadMesh(float* positions, int* indices, float* textureCoords, int vertexCount, int indicesCount); // Loads a mesh from a list of vertices and indices. Based on the ThinMatrix's implementation
	
	/*
		Creates a loader
	*/
	Loader();

	/*
		Destroys a loader
	*/
	~Loader();

	/*
		Loads a texture from a file
		@param filename The path to the file to load
		@return Returns a integer that represents the location of the texture in memory
	*/
	GLuint loadTexture(char* filename);

	Mesh* loadObj(char* filename);

private:
	std::vector<GLuint>* vaos; // stores all of the vaos
	std::vector<GLuint>* vbos; // stores all of the vbos
	std::vector<GLuint>* textures; // stores all of the loaded textures

	/*
		Creates a VAO. Based on the ThinMatrix's implementation. (Helper method)
		@return Returns the VAO
	*/
	GLuint createVAO(); 

	/*
		Stores data in an attribute list. Based on the ThinMatrix's implementation (Helper Method)
	*/
	void storeDataInAttributeList(int attribNumber, int size, float* data, int vertexCount);

	/*
		Unbinds the VAO (Helper method). Based on the ThinMatrix's implementation
	*/
	void unbindVAO();

	/*
		Binds vertices. (Helper method). Based on the ThinMatrix's implementation
		
	*/
	void bindIndicesBuffer(int* indices, int indicesCount);
};

#endif