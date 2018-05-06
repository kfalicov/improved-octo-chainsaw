#include "Mesh.h"



Mesh::Mesh(GLuint vaoID, int vertexCount) : 
	_vaoID(vaoID), 
	_vertexCount(vertexCount)
{}


Mesh::~Mesh()
{
}

GLuint Mesh::getVAOID()
{
	return _vaoID;
}

int Mesh::getVertexCount()
{
	return _vertexCount;
}
