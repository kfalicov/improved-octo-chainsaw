#include "Camera.h"



Camera::Camera(glm::vec3 position)
{
	_position = position;

	//these must be initialized
	_pitch = 0.0;
	_yaw = 0.0;
	_roll = 0.0;
}

Camera::Camera(glm::vec3 position, float pitch, float roll, float yaw)
{
	_position = position;

	//these must be initialized
	_pitch = pitch;
	_yaw = yaw;
	_roll = roll;
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

void Camera::move(EventManager* handler)
{
	_yaw -= static_cast<float>(handler->getDX()/10);
	_pitch += static_cast<float>(handler->getDY()/10);
	//std::cout << _yaw << " " << _pitch << std::endl;
	handler->disposeDeltas();	//	after the dx and dy are used they should be 0 again otherwise you get continuous movement. This could potentially be used for damping camera movement by gradually approaching 0.
	float moveSpeed = 0.25;

	//	these statements check for directional key movement and then perform calculations so that movement is relative to the camera
	if (handler->getKeyState(GLFW_KEY_W)) {
		float xComponent = moveSpeed * sin(glm::radians(_yaw));
		float zComponent = moveSpeed * cos(glm::radians(_yaw));
		_position[0] += xComponent;
		_position[2] -= zComponent;
		//std::cout << _position[0] << std::endl;
	}
	if (handler->getKeyState(GLFW_KEY_S)) {
		float xComponent = moveSpeed * sin(glm::radians(_yaw));
		float zComponent = moveSpeed * cos(glm::radians(_yaw));
		_position[0] -= xComponent;
		_position[2] += zComponent;
		//std::cout << _position[0] << std::endl;
	}
	//left movement
	if (handler->getKeyState(GLFW_KEY_A)) {
		float xComponent = moveSpeed * cos(glm::radians(_yaw));
		float zComponent = moveSpeed * sin(glm::radians(_yaw));
		_position[0] -= xComponent;
		_position[2] -= zComponent;
		//std::cout << _position[0] << std::endl;
	}
	//right movement
	if (handler->getKeyState(GLFW_KEY_D)) {
		float xComponent = moveSpeed * cos(glm::radians(_yaw));
		float zComponent = moveSpeed * sin(glm::radians(_yaw));
		_position[0] += xComponent;
		_position[2] += zComponent;
		//std::cout << _position[0] << std::endl;
	}
}
