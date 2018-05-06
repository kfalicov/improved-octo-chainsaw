#include "StaticShader.h"



StaticShader::StaticShader(char* vertexShaderFilename, char* fragmentShaderFilename) : Shader(vertexShaderFilename,fragmentShaderFilename)
{
}


StaticShader::~StaticShader()
{
}

void StaticShader::bindAttributes()
{
	bindAttribute(0, "position");
	bindAttribute(1, "textureCoords");
}

void StaticShader::getAllUniformLocations()
{

}