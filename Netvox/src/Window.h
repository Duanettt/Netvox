#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);


class Window
{
public:
		Window(unsigned int height, unsigned int width);

		//void CreateWindow();
		void Run();
		bool WindowIsOpen();
		//void SetContext();


		GLFWwindow* m_window; 
private:
		unsigned int m_height = 0;
		unsigned int m_width = 0;

};



 