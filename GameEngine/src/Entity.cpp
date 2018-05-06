#include "Entity.h"
#include <iostream>


Entity::Entity(glm::vec3 position, float rx, float ry, float rz, float scale)
	:
	_position(position),
	_rx(rx),
	_ry(ry),
	_rz(rz),
	_scale(scale)
{

}
Entity::~Entity()
{

}

glm::vec3 Entity::getPosition()
{
	return _position;
}

float Entity::getRotationX()
{
	return _rx;
}

float Entity::getRotationY()
{
	return _ry;
}

float Entity::getRotationZ()
{
	return _rz;
}

float Entity::getScale()
{
	return _scale;
}

void Entity::setPosition(glm::vec3 pos)
{
	_position = pos;
}

void Entity::setRotationX(float x)
{
	_rx = x;
}

void Entity::setRotationY(float y)
{
	_ry = y;
}

void Entity::setRotationZ(float z)
{
	_rz = z;
}

void Entity::setScale(float s)
{
	_scale = s;
}

void Entity::update() 
{
	std::cerr << "Warning: Using parent Update function\n";
}
void Entity::render(Shader* shader) 
{
	std::cerr << "Warning: Using parent Render function\n";
}