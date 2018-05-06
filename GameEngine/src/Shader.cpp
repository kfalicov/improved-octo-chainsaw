#include "Shader.h"
#include <fstream>
#include <string>

Shader::Shader(char* vertexShaderFilename, char* fragmentShaderFilename)
{
	_program = glCreateProgram(); // Creates a shader program

	// Creates a vertex shader and a fragment shader
	_vertexShader = createShader(getShaderCode(vertexShaderFilename), GL_VERTEX_SHADER);
	_fragmentShader = createShader(getShaderCode(fragmentShaderFilename), GL_FRAGMENT_SHADER);

	// attaches the shaders to the program
	glAttachShader(_program, _vertexShader);
	glAttachShader(_program, _fragmentShader);

	bindAttributes();
	// Links the program and verifies the linking succeeded
	glLinkProgram(_program); 
	GLint result = 0;
	glGetProgramiv(_program, GL_LINK_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cerr << "ERROR: Program Creation Failed. Linking failed\n";
		exit(-1);
	}

	// Validates the program and verifies the validation succeeded
	glValidateProgram(_program);
	glGetProgramiv(_program, GL_VALIDATE_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cerr << "ERROR: Program Creation Failed. Validation failed\n";
		exit(-1);
	}
	getAllUniformLocations();
}

void Shader::bindAttributes()
{

}

void Shader::getAllUniformLocations()
{
	_transformationMatrixLocation = getUniformLocation("transformationMatrix");
	_projectionMatrixLocation = getUniformLocation("projectionMatrix");
	_viewMatrixLocation = getUniformLocation("viewMatrix");
}

GLuint Shader::getUniformLocation(char* name)
{
	return glGetUniformLocation(_program, name);
}

void Shader::loadFloatUniform(GLuint location, float value)
{
	glUniform1f(location, value);
}

void Shader::loadVectorUniform(GLuint location, glm::vec3 vector)
{
	glUniform3f(location, vector.x,vector.y,vector.z);
}

void Shader::loadBooleanUniform(GLuint location, bool value)
{
	float toLoad = 0;
	if (value)
	{
		toLoad = 1;
	}
	glUniform1f(location, toLoad);
}

void Shader::loadMatrixUniform(GLuint location, glm::mat4 mat)
{
	glUniformMatrix4fv(location, 1, false, &mat[0][0]);
}

Shader::~Shader()
{
	unbind();
	// detaches the shaders from the program
	glDetachShader(_program, _fragmentShader);
	glDetachShader(_program, _vertexShader);

	// deletes the shaders and then the program
	glDeleteShader(_fragmentShader);
	glDeleteShader(_vertexShader);
	glDeleteProgram(_program);
}

void Shader::bind()
{
	glUseProgram(_program); // tells opengl to use the shader program
}

void Shader::unbind()
{
	glUseProgram(0);
}


void Shader::bindAttribute(int attrib, char* variableName)
{
	glBindAttribLocation(_program, attrib, variableName);
}

GLuint Shader::createShader(const std::string& shaderCode, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType); // creates a shader

	if (shader == 0) // verifies the shader created successfully
	{
		std::cerr << "Error: Shader Creation Failed\n";
		exit(-1);
	}

	// prepares the shader code to be compiled
	const GLchar* shaderSource[1];
	GLint shaderSourceLength[1];

	shaderSource[0] = shaderCode.c_str();
	shaderSourceLength[0] = shaderCode.length();

	glShaderSource(shader, 1, shaderSource, shaderSourceLength); // adds the shader source code to the shader
	glCompileShader(shader); // compiles the shader

	// verifies the shader compiled successfully
	GLint result = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cerr << "ERROR: Shader failed to compile\n";
		exit(-1);
	}
	return shader;
}
std::string Shader::getShaderCode(char* filename)
{
	std::ifstream file;
	file.open(filename); // opens the file asked to by the parameter

	std::string output;
	std::string line;

	// copies the code from the file and adds newline characters
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << filename << std::endl;
	}
	file.close();
	// returns the contents of the file
	return output;
}


void Shader::loadTransformationMatrix(glm::mat4 matrix)
{
	loadMatrixUniform(_transformationMatrixLocation, matrix);
}

void Shader::loadProjectionMatrix(glm::mat4 projection)
{
	loadMatrixUniform(_projectionMatrixLocation, projection);
}

void Shader::loadViewMatrix(Camera* camera)
{
	glm::mat4 viewMatrix = createViewMatrix(camera);

	loadMatrixUniform(_viewMatrixLocation, viewMatrix);
}