#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "VBO.h"


class VAO {

public:

    VAO() = default;
    VAO(const VAO& other) = delete;
    //VAO(VAO&& other) { *this = std::move(other); }
    ~VAO() { if (m_id) glDeleteVertexArrays(1, &m_id); }
    //VAO& operator=(const VAO& other) = delete;
    //VAO& operator=(VAO&& other) {
    //    if (this != &other) {
    //        if (m_id) glDeleteVertexArrays(1, &m_id);
    //        m_id = std::exchange(other.m_id, 0);
    //    }
    //    return *this;
    //}

    /**
     * @brief Binds the VAO.
     */
    void Bind() const { glBindVertexArray(m_id); }

    /**
     * @brief Specifies how OpenGL should interpret the vertex buffer data whenever a draw call is made.
     * @param vbo The vertex buffer object to be binded.
     * @param layout Specifies the index of the generic vertex attribute to be modified. Must match the layout in the shader.
     * @param components Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4.
     * @param type Type of the data.
     * @param stride Specifies the byte offset between consecutive generic vertex attributes.
     * @param offset Specifies a offset of the first component of the first generic vertex attribute in the array in the data store.
     * @param normalize Specifies whether fixed-point data values should be normalized.
     */
    void LinkAttribute(const VBO& vbo, GLuint layout, GLuint components, GLenum type, GLsizei stride, void* offset, GLboolean normalize = GL_FALSE) const;

    /**
     * @brief Specifies how OpenGL should interpret the vertex buffer data whenever a draw call is made. IT DOESN'T BIND ANYTHING!
     * @param layout Specifies the index of the generic vertex attribute to be modified. Must match the layout in the shader.
     * @param components Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4.
     * @param type Type of the data.
     * @param stride Specifies the byte offset between consecutive generic vertex attributes.
     * @param offset Specifies a offset of the first component of the first generic vertex attribute in the array in the data store.
     * @param normalize Specifies whether fixed-point data values should be normalized.
     */
    void LinkAttribFast(GLuint layout, GLuint components, GLenum type, GLsizei stride, void* offset, GLboolean normalize = GL_FALSE) const;

    /**
     * @brief Generates the vertex array buffer.
     */
    void GenVertexArray();

    /**
     * @brief Unbinds the VAO.
     */
    void Unbind() const { glBindVertexArray(0); }

private:

    GLuint m_id{};
};
