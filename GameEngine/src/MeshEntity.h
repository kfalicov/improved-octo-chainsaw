#ifndef _MESH_ENTITY_H
#define _MESH_ENTITY_H
#include <glew.h>
#include <glfw3.h>
#include "Entity.h"
#include "Mesh.h"

/*
	An entity that has a simple mesh and no texture
*/
class MeshEntity : public Entity
{
public:

	/*
		Creates a new MeshEntity
		@param position The initial position of the MeshEntity
		@param rx The initial pitch of the MeshEntity
		@param ry The initial yaw of the MeshEntity
		@param rz The initial roll of the MeshEntity
		@param scale The initial scale of the MeshEntity
		@param mesh The mesh of the MeshEntity
	*/
	MeshEntity(glm::vec3 position, float rx, float ry, float rz, float scale, Mesh* mesh);

	/*
		Destroys the MeshEntity
	*/
	~MeshEntity();

	/*
		Renders the MeshEntity (Overrides Render function in Entity)
		@param shader A pointer to the shader used to render the entity
	*/
	void render(Shader* shader);

	/*
		Updates the MeshEntity (Overrides the Update function in Entity)
	*/
	void update();

	/*
		Returns the Mesh the MeshEntity stores
		@return Returns the Mesh the MeshEntity stores
	*/
	Mesh* getMesh();

private:
	Mesh* _mesh;
};

#endif