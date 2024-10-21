#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>



class VBO
{
public:
	VBO(const void* data, const unsigned int size);

	void Bind() const;

	void Unbind() const;

private:
	unsigned int ID;
};

