#ifndef _STATIC_SHADER_H
#define _STATIC_SHADER_H
#include "Shader.h"
#include "Util.h"

/*
	A shader to be used with a static model
*/
class StaticShader : public Shader
{
public:
	/*
		Creates a new StaticShader
		@param vertexShaderFilename The filename of the vertex shader code
		@param fragmentShaderFilename The filename of the fragment shader code
	*/
	StaticShader(char* vertexShaderFilename, char* fragmentShaderFilename);

	/*
		Destroys a StaticShader
	*/
	~StaticShader();

	/*
		Overrides the bindAttributes in the parent Shader class
	*/
	void bindAttributes();

	/*
		Overrides the getAllUniformLocations in the parent Shader class
	*/
	void getAllUniformLocations();

private:
};

#endif