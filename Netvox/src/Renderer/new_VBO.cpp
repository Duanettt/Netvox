#include "new_VBO.h"

void new_VBO::GenerateBuffer()
{
	glGenBuffers(1, &VBO);
}

void new_VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void new_VBO::Setup(const void* data, GLenum usage)
{
	glBindBuffer(1, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, usage);

}

void new_VBO::Unbind()
{
	glDeleteBuffers(1, &VBO);
}
