#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "VBO.h"


class VAO
{
public:
	VAO();
	~VAO();	

	void Bind();

	void Unbind();

	void LinkAttribute(const VBO& vbo, unsigned int layout, int size, GLenum type, GLsizei stride, const void* offset);


private:
	unsigned int ID;
};

