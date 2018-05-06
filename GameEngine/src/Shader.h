#ifndef _SHADER_H
#define _SHADER_H
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <glm\glm.hpp>
#include "Camera.h"
#include "Util.h"
/*
	Defines a shader.
	Based on the ThinMatrix's version of a shader
*/
class Shader
{
public:
	/*
		Creates a new Shader
		@param vertexShaderFilename The filename of the vertex shader to load
		@param fragmentShaderFilename The filename of the fragment shader to load
	*/
	Shader(char* vertexShaderFilename, char* fragmentShaderFilename);

	/*
		Loads a boolean value into a shader uniform
		@param location The location of the uniform
		@param value The boolean value to load
	*/
	void loadBooleanUniform(GLuint location, bool value);

	/*
		Loads a matrix into a shader uniform
		@param location The location of the uniform
		@param mat The matrix to load
	*/
	void loadMatrixUniform(GLuint location, glm::mat4 mat);

	/*
		Destroys the shader
	*/
	~Shader(); // destroys the shader

	/*
		Binds the shader so it will be used when rendering
	*/
	void bind(); // binds the shader program so it will be used by opengl

	/*
		Unbinds the shader to it will not be used when rendering
	*/
	void unbind();

	/*
		Binds attributes to the shader (A pure virtual function and must be overridden)	
	*/
	virtual void bindAttributes() = 0;

	/*
		Gets all of the uniform locations (A pure virtual function and must be overridden)
	*/
	virtual void getAllUniformLocations() = 0;

	/*
		Binds an attribute to the shader
		@param attrib The number to store the attribute in
		@param variableName The name of the attribute
	*/
	void bindAttribute(int attrib, char* variableName);

	/*
		Returns the location of a uniform
		@param name The name of the uniform
		@return Returns the location of a uniform
	*/
	GLuint getUniformLocation(char* name);

	/*
		Loads a float into a shader uniform
		@param location The location of the uniform
		@param value The value to load into the uniform
	*/
	void loadFloatUniform(GLuint location, float value);

	/*
		Loads a vector into a shader uniform
		@param location The location of the uniform
		@param vector The vector to load into the uniform
	*/
	void loadVectorUniform(GLuint location, glm::vec3 vector);

	/*
		Loads a transformation matrix into the shader
		@param matrix The transformation matrix to load
	*/
	void loadTransformationMatrix(glm::mat4 matrix);

	/*
		Loads a projection matrix into the shader
		@param projection The projection matrix to load
	*/
	void loadProjectionMatrix(glm::mat4 projection);

	/*
		Loads a view matrix into the shader
		@param camera A pointer to the game camera
	*/
	void loadViewMatrix(Camera * camera);

private:
	/*
		Creates a new shader program (helper method)
		@param shaderCode The source code of the shader program
		@param shaderType The type of shader to create
		@return Returns a location of a shader
	*/
	GLuint createShader(const std::string& shaderCode, GLenum shaderType);

	/*
		Loads the shader programs code from a file (Helper method)
		@param filename The filename to load the shader code from
		@return Returns the source code of the shader
	*/
	std::string getShaderCode(char* filename); // helper method to get the code of a shader

	GLuint _program;
	GLuint _fragmentShader;
	GLuint _vertexShader;
	GLuint _transformationMatrixLocation;
	GLuint _projectionMatrixLocation;
	GLuint _viewMatrixLocation;
protected:


};

#endif