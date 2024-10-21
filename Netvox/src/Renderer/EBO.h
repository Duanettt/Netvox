#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class EBO
{
public:
	EBO(const void* data, const unsigned int size);
	//~EBO();

	void Bind();
	void Unbind();


private:
	unsigned int ID;
};

