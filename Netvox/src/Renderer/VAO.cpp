#include "VAO.h"

void VAO::GenVertexArray()
{
	glGenVertexArrays(1, &m_id);
}

void VAO::LinkAttribute(const VBO& vbo, GLuint layout, GLuint components, GLenum type, GLsizei stride, void* offset, GLboolean normalize) const
{
	vbo.Bind();
	glVertexAttribPointer(layout, components, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
}

void VAO::LinkAttribFast(GLuint layout, GLuint components, GLenum type, GLsizei stride, void* offset, GLboolean normalize) const
{
	glVertexAttribPointer(layout, components, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
}


