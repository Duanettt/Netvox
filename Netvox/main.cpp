#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "src/Window.h"
#include "src/Renderer/Buffers/VBO.h"
#include "src/Renderer/Buffers/EBO.h"
#include "src/Renderer/Buffers/VAO.h"
#include "src/Renderer/Shader.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

int main()
{


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    Window window(SCR_HEIGHT, SCR_WIDTH);

    glfwMakeContextCurrent(window.m_window);

    // glfw: initialize and configure
    // ------------------------------


    


    //window.CreateWindow();

   


   // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader shader("res/shaders/vertexShader.vert","res/shaders/fragmentShader.frag");
     float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    // Instantiate our VAO, VBO and EBO with this data.
    VAO vao;
    VBO vbo(vertices, sizeof(vertices));
    EBO ebo(indices, sizeof(indices));

    // We create our VAO and link attributes from the vbo to the VAO.
    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, sizeof(float) * 3, (void*)0);

    // render loop
    // -----------
    while (window.WindowIsOpen())
    {
        // input
        // -----
        window.Run();
       
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        vao.Unbind();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window.m_window);
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}
 // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// --------------------------------------------------
