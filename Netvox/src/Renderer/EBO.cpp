#include "EBO.h"

EBO::EBO(const void* data, const unsigned int size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

//EBO::~EBO()
//{
//	glDeleteBuffers(1, &ID);
//}

void EBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
