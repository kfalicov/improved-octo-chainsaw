#include "Camera.h"



Camera::Camera(glm::vec3 position)
{
	_position = position;
}


Camera::~Camera()
{
}

glm::vec3 Camera::getPosition()
{
	return _position;
}

float Camera::getPitch()
{
	return _pitch;
}

float Camera::getRoll()
{
	return _roll;
}

float Camera::getYaw()
{
	return _yaw;
}

void Camera::move(InputHandler* handler)
{
	// TODO: Handle camera movement
}
