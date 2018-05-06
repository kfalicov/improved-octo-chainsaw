#ifndef _TEXTURED_MESH_H
#define _TEXTURED_MESH_H
#include "Texture.h"
#include "Mesh.h"

/*
	Stores data about a mesh that is textured
*/
class TexturedMesh
{
public:
	/*
		Creates a new TexturedMesh
		@param mesh The mesh
		@param texture The texture for the mesh
	*/
	TexturedMesh(Mesh* mesh, Texture* texture);

	/*
		Destroys the TexturedMesh
	*/
	~TexturedMesh();

	/*
		Returns the mesh
		@return Returns the mesh
	*/
	Mesh* getMesh();

	/*
		Returns the texture
		@return Returns the texture
	*/
	Texture* getTexture();

private:
	Mesh* _mesh;
	Texture* _texture;
};

#endif