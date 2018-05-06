#include "MeshEntity.h"



MeshEntity::MeshEntity(glm::vec3 position, float rx, float ry, float rz, float scale, Mesh* mesh) : Entity(position, rx, ry, rz, scale), _mesh(mesh)
{
}


MeshEntity::~MeshEntity()
{
}

void MeshEntity::render(Shader* shader)
{
	glBindVertexArray(_mesh->getVAOID());
	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, _mesh->getVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

Mesh* MeshEntity::getMesh()
{
	return _mesh;
}

void MeshEntity::update()
{

}