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
	/*
		Creates a new camera
		@param position The initial position of the camera
	*/
	Camera(glm::vec3 position);

	/*
		Destroys the camera	
	*/
	~Camera();

	/*
		Returns the position of the camera
		@return Returns the position of the camera
	*/
	glm::vec3 getPosition();

	/*
		Returns the pitch of the camera
		@return Returns the position of the camera
	*/
	float getPitch();

	/*
		Returns the yaw of the camera
		@return Returns the yaw of the camera
	*/
	float getYaw();

	/*
		Returns the roll of the camera
		@return Returns the roll of the camera
	*/
	float getRoll();

	/*
		Moves the camera
		@param handler A pointer to the input handler
	*/
	void move(EventManager* handler); 

private:
	glm::vec3 _position;
	float _pitch;
	float _yaw;
	float _roll;
protected:

};

#endif