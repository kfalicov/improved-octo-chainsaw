#include "TexturedEntity.h"
#include "Util.h"

TexturedEntity::TexturedEntity(glm::vec3 position, float rx, float ry, float rz, float scale, TexturedMesh* texturedMesh) : Entity(position,rx,ry,rz,scale), _texturedMesh(texturedMesh)
{
}


TexturedEntity::~TexturedEntity()
{
}

TexturedMesh* TexturedEntity::getTexturedMesh()
{
	return _texturedMesh;
}

void TexturedEntity::render(Shader* shader)
{
	Mesh* mesh = _texturedMesh->getMesh();
	glBindVertexArray(mesh->getVAOID()); // loads the vao
	glEnableVertexAttribArray(0); // enables both vertex attribute arrays defined by the shader
	glEnableVertexAttribArray(1);

	glm::mat4 transformationMatrix = createTransformationMatrix(getPosition(), getRotationX(), getRotationY(), getRotationZ(), getScale()); // create a transformation matrix based on the current entity
	shader->loadTransformationMatrix(transformationMatrix); // loads the matrix into the transformation matrix
	glActiveTexture(GL_TEXTURE0);
	_texturedMesh->getTexture()->bind(); // binds the texture
	glDrawElements(GL_TRIANGLES, mesh->getVertexCount(), GL_UNSIGNED_INT, 0); // draws the mesh

	// cleans up memory
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}

void TexturedEntity::update()
{
	// tmp
	//std::cout << "TEST rotation code\n";
	//setRotationX(getRotationX() + 0.4f);
	//setRotationY(getRotationY() + 0.4f);
	//setRotationZ(getRotationZ() + 0.8f);
}