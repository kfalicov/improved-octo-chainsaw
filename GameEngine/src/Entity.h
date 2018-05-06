#ifndef  _ENTITY_H
#define _ENTITY_H
#include <glm\glm.hpp>
#include "Shader.h"

/*
	Store the basic properties of an Entity. An entity is something that exists in the game world. It does not have to be renderered
*/
class Entity
{
public:

	/*
		Creates a new entity
		@param position The initial position of the entity
		@param rx The initial pitch of the entity
		@param ry The initial yaw of the entity
		@param rz The initial roll of the entity
		@param scale The initial scale of the entity
	*/
	Entity(glm::vec3 position, float rx, float ry, float rz, float scale);

	/*
		Destroys the entity
	*/
	~Entity();

	/*
		Returns the position of the entity
		@return Returns the position of the entity
	*/
	glm::vec3 getPosition();

	/*
		Returns the pitch of the entity
		@return Returns the pitch of the entity
	*/
	float getRotationX();

	/*
		Returns the yaw of the entity
		@return Returns the yaw of the entity
	*/
	float getRotationY();

	/*
		Returns the roll of the entity
		@return Returns the roll of the entity
	*/
	float getRotationZ();

	/*
		Returns the scale of the entity
		@return Returns the scale of the entity
	*/
	float getScale();

	/*
		Sets the position of the entity
		@param pos The new position of the entity
	*/
	void setPosition(glm::vec3 pos); 

	/*
		Sets the pitch of the entity
		@param x The new pitch of the entity
	*/
	void setRotationX(float x); 

	/*
		Sets the yaw of the entity
		@param y The new yaw of the entity
	*/
	void setRotationY(float y);

	/*
		Sets the roll of the entity
		@param z The new roll of the entity
	*/
	void setRotationZ(float z);

	/*
		Sets the scale of the entity
		@param s The new scale of the entity
	*/
	void setScale(float s);

	/*
		A pure virtual function to render the entity in the world (Must be overridden)
		@param shader A pointer to the shader to use to render the entity
	*/
	virtual void render(Shader* shader) = 0;

	/*
		A pure virtual function to update the entity in the world (Must be overridden)
	*/
	virtual void update() = 0;

private:
	glm::vec3 _position;
	float _rx;
	float _ry;
	float _rz;
	float _scale;
};

#endif