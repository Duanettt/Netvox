#include "VBO.h"



void VBO::GenerateBuffer()
{
	glGenBuffers(1, &m_id);
}

void VBO::Setup(const GLfloat* vertices, GLsizeiptr size, GLenum usage)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, usage);
}
