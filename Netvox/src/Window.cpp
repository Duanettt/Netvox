#include "Window.h"

Window::Window(unsigned int height, unsigned int width) : m_height(height), m_width(width)
{

    std::cout << "Initialised our GLFW window!" << std::endl;


    this->m_window = glfwCreateWindow(this->m_width, this->m_height, "LearnOpenGL", NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    std::cout << "m_Window is now created and has created our window!" << std::endl;
}

////void Window::CreateWindow()
//{
//    std::cout << "Entering the create window function!" << std::endl;
//	this->m_window = glfwCreateWindow(this->m_width, this->m_height, "LearnOpenGL", NULL, NULL);
//    if (m_window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//    }
//
//    std::cout << "m_Window is now created and has created our window!" << std::endl;
//
//}


void Window::Run()
{
    //std::cout << "Beginning to process input." << std::endl;
    processInput(this->m_window);
    //glfwSwapBuffers(this->m_window);
    glfwPollEvents();
}

bool Window::WindowIsOpen()
{
    return !glfwWindowShouldClose(this->m_window);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
