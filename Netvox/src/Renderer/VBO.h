#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#include <vector>



class VBO {

public:

    VBO() = default;
    VBO(const VBO& other) = delete;
    //VBO(VBO&& other) { *this = std::move(other); }
    ~VBO() { if (m_id) glDeleteBuffers(1, &m_id); }
    //VBO& operator=(const VBO& other) = delete;
    //VBO& operator=(VBO&& other) {
    //    if (this != &other) {
    //        if (m_id) glDeleteBuffers(1, &m_id);
    //        m_id = std::exchange(other.m_id, 0);
    //    }
    //    return *this;
    //}

    /**
     * @brief Binds the VBO.
     */
    void Bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_id); }

    /**
     * @brief Generates the buffer for the VBO.
     */
    void GenerateBuffer();

    /**
     * @brief Sets up the data for the buffer.
     * @param vertices A pointer to an array of floats to use as data.
     * @param size The size in bytes of the data.
     * @param usage The usage type, default GL_STATIC_DRAW.
     */
    void Setup(const GLfloat* vertices, GLsizeiptr size, GLenum usage = GL_STATIC_DRAW);

    /**
     * @brief Sets up the data for the buffer.
     * @tparam T Things stored *contiguously* in memory.
     * @param vertices A pointer to an array of Ts to use as data.
     * @param size The size in bytes of the data.
     * @param usage The usage type, default GL_STATIC_DRAW.
     */
    template <typename T>
    void Setup(const T* vertices, GLsizeiptr size, GLenum usage = GL_STATIC_DRAW) {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, usage);
    }

    /**
     * @brief Sets up the data for the buffer.
     * @tparam T You might want this to some numeric, vector, etc type for good result,
     * @param vertices A std::vector of something to use as data.
     * @param usage The usage type, default GL_STATIC_DRAW.
     */
    template <typename T>
    void Setup(const std::vector<T>& vertices, GLenum usage = GL_STATIC_DRAW) {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(T), vertices.data(), usage);
    }

    /**
     * @brief Sets up the data for the buffer avoiding the cost of reallocating
     *  the data store.
     * @tparam T Things stored *contiguously* in memory.
     * @param vertices A pointer to an array of Ts to use as data.
     * @param size The size in bytes of the data.
     * @param offset The offset into the buffer object's data store where data
     *  replacement will begin, measured in bytes.
     */
    template <typename T>
    void SetupSubData(const T* vertices, GLsizeiptr size, GLintptr offset = 0) {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferSubData(GL_ARRAY_BUFFER, offset, size, vertices);
    }

    /**
     * @brief Sets up the data for the buffer avoiding the cost of reallocating
     *  the data store.
     * @tparam T You might want this to some numeric, vector, etc type for good result,
     * @param vertices A std::vector of floats to use as data.
     * @param offset The offset into the buffer object's data store where data
     *  replacement will begin, measured in bytes.
     */
    template <typename T>
    void SetupSubData(const std::vector<T>& vertices, GLintptr offset = 0) {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferSubData(GL_ARRAY_BUFFER, offset, vertices.size() * sizeof(T), vertices.data());
    }

    /**
     * @brief Unbinds the VBO.
     */
    void Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

private:

    GLuint m_id{};
};
