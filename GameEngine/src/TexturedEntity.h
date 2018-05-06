#ifndef _TEXTURED_ENTITY_H
#define _TEXTURED_ENTITY_H

#include "Entity.h"
#include "TexturedMesh.h"

/*
	An entity that is textured
*/
class TexturedEntity : public Entity
{
public:

	/*
		Creates a new TexturedEntity
		@param position The initial position of the TexturedEntity
		@param rx The initial pitch of the TexturedEntity
		@param ry The initial yaw of the TexturedEntity
		@param rz The initial roll of the TexturedEntity
		@param scale The initial scale of the TexturedEntity
		@param mesh The TexturedMesh of the TexturedEntity
	*/
	TexturedEntity(glm::vec3 position, float rx, float ry, float rz, float scale, TexturedMesh* mesh);

	/*
		Destroys the TexturedEntity
	*/
	~TexturedEntity();

	/*
		Returns the TexturedMesh of the TexturedEntity
		@return Returns the TexturedMesh of the TexturedEntity
	*/
	TexturedMesh* getTexturedMesh();

	/*
		Overrides the render function in the Entity class
	*/
	void render(Shader* shader);

	/*
		Overrides the update function in the Entity class
	*/
	void update();
private:
	TexturedMesh* _texturedMesh;
};

#endif