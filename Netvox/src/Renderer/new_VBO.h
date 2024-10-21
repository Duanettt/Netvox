#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


class new_VBO
{
public:
	unsigned int VBO;

	new_VBO() = default;

	void GenerateBuffer();

	void Bind();
	
	void Setup(const void* data, GLenum usage);

	void LinkAttributes();

	void Unbind();


private:
};

