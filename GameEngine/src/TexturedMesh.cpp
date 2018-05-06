#include "TexturedMesh.h"



TexturedMesh::TexturedMesh(Mesh* mesh, Texture* texture) : _mesh(mesh), _texture(texture)
{
}


TexturedMesh::~TexturedMesh()
{
}

Mesh* TexturedMesh::getMesh()
{
	return _mesh;
}


Texture* TexturedMesh::getTexture()
{
	return _texture;
}
