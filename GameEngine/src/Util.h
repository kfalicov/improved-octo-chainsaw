#ifndef _UTILS
#define _UTILS
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include "Camera.h"

static float FOV = 65;
static float NEAR = 0.1f;
static float FAR = 1000.0f;
static int width = 1366;
static int height = 768;

// found on https://www.geeksforgeeks.org/how-to-find-size-of-array-in-cc-without-using-sizeof-operator/
#define size_of(x)  (sizeof(x) / sizeof((x)[0]))

/*
	Creates a new transformation matrix based on the details of the object passed in
	@param translation The translation of the position
	@param rx The pitch
	@param ry The yaw
	@param rz The roll
	@param scale The scale
	@return Retuns a transformation matrix for the object passed in
*/
static glm::mat4 createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale)
{
	glm::mat4* matrix = new glm::mat4(1);
	*matrix = glm::translate(*matrix,translation);
	*matrix = glm::rotate(*matrix, glm::radians(rx), glm::vec3(1, 0, 0));
	*matrix = glm::rotate(*matrix, glm::radians(ry), glm::vec3(0, 1, 0));
	*matrix = glm::rotate(*matrix, glm::radians(rz), glm::vec3(0, 0, 1));
	*matrix = glm::scale(*matrix, glm::vec3(scale, scale, scale));

	return *matrix;
}

/*
	Creates a projection matrix
	@param matrix The matrix to store the result in
*/
static void createProjectionMatrix(glm::mat4* matrix)
{
	float aspectRatio = (float)width / (float)height;
	float y_scale = (float)((1.0f / glm::tan(glm::radians(FOV / 2.0f))) * aspectRatio);
	float x_scale = y_scale / aspectRatio;
	float frustum_length = FAR - NEAR;

	glm::mat4* tmp = new glm::mat4();
	(*tmp)[0][0] = x_scale;
	(*tmp)[1][1] = y_scale;
	(*tmp)[2][2] = -((FAR + NEAR) / frustum_length);
	(*tmp)[2][3] = -1;
	(*tmp)[3][2] = -((2 * NEAR * FAR) / frustum_length);
	(*tmp)[3][3] = 0;

	*matrix = *tmp;
}

/*
	Creates a view matrix
	@param camera A pointer to the game camera
	@return Returns the view matrix
*/
static glm::mat4 createViewMatrix(Camera* camera)
{
	glm::mat4* viewMatrix = new glm::mat4(1);
	*viewMatrix = glm::rotate(*viewMatrix,(float)glm::radians(camera->getPitch()), glm::vec3(1, 0, 0));
	*viewMatrix = glm::rotate(*viewMatrix, (float)glm::radians(camera->getYaw()), glm::vec3(0, 1, 0));
	*viewMatrix = glm::rotate(*viewMatrix, (float)glm::radians(camera->getRoll()), glm::vec3(0, 0, 1));

	glm::vec3 cameraPos = camera->getPosition();
	glm::vec3 negativeCameraPos = glm::vec3(-cameraPos.x, -cameraPos.y, -cameraPos.z);
	*viewMatrix = glm::translate(*viewMatrix, negativeCameraPos);
	return *viewMatrix;

}

#endif
