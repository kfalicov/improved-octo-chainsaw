#ifndef _CAMERA_H
#define _CAMERA_H
#include <glm/glm.hpp>
#include "EventManager.h"

/*
	Controls what is displayed to the user
*/
class Camera
{
public:

	//	Creates a new camera with initial position
	Camera(glm::vec3 position);

	//	Creates a new camera with initial position and angle
	Camera(glm::vec3 position, float pitch, float roll, float yaw);

	//	Destructor
	~Camera();

	//	Returns the position of the camera
	glm::vec3 getPosition();

	//	Returns the pitch (rotation around an imaginary line horizontal to the screen)
	float getPitch();

	//	Returns the yaw (rotation around an imaginary line vertical to the screen)
	float getYaw();

	//	Returns the roll (rotation around an imaginary line going into the screen)
	float getRoll();

	//	moves the camera using inputs from the event manager
	void move(EventManager* manager); 

private:
	glm::vec3 _position;
	float _pitch;
	float _yaw;
	float _roll;
protected:

};

#endif