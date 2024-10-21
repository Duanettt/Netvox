#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "src/Window.h"
#include "src/Renderer/new_VBO.h"
#include "src/Renderer/EBO.h"
#include "src/Renderer/VAO.h"
#include "src/Renderer/Shader.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


int main()
{


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    Window window(SCR_HEIGHT, SCR_WIDTH);

    glfwMakeContextCurrent(window.m_window);
    glfwSetFramebufferSizeCallback(window.m_window, framebuffer_size_callback);

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
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };

    //unsigned int VBO, VAO;
    //glGenVertexArrays(1, &VAO);
    //glGenBuffers(1, &VBO);
    //// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    //glBindVertexArray(VAO);

    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //// position attribute
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);
    //// color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);

    VAO vao;
    VBO vbo;

    vao.GenVertexArray();
    vbo.GenerateBuffer();

    vbo.Setup(vertices, sizeof(vertices), GL_STATIC_DRAW);

    vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    vao.LinkAttribute(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));




    // Instantiate our VAO, VBO and EBO with this data.
    
    // Generate our array and buffers for our data.

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

        // render the triangle
        //shader.use();
        //glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        shader.use();
        vao.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

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
