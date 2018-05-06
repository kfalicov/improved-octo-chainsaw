#ifndef _MESH_H
#define _MESH_H
#include <glfw3.h>

/*
	Stores data about a Mesh.
*/
class Mesh
{
public:

	/*
		Creates a new mesh
		@param vaoID The id of the vao for the mesh
		@param vertexCount The number of vertices in the mesh
	*/
	Mesh(GLuint vaoID, int vertexCount); 

	/*
		Destroys the mesh
	*/
	~Mesh();

	/*
		Returns the VAOID
		@return Returns the VAOID
	*/
	GLuint getVAOID();

	/*
		Returns the number of vertices in the mesh
		@return Returns the number of vertices in the mesh
	*/
	int getVertexCount();

private:
	GLuint _vaoID; // The id of the vao
	int _vertexCount; // The number of vertices
protected:
};

#endif