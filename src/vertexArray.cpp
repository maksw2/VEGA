#include "vega/vertexArray.hpp"

namespace vega {
    VEGAVertexArray::VEGAVertexArray() {
        glGenVertexArrays(1, &id);
        glBindVertexArray(id);
    }

    VEGAVertexArray::~VEGAVertexArray() {

    }

    void VEGAVertexArray::linkAttrib(VEGAVertexBuffer* buffer, unsigned int index, GLenum type, unsigned int count, unsigned int stride, void* offset) {
        bind();
        buffer->bind();
        glVertexAttribPointer(index, count, type, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(index);
        buffer->unbind();
        unbind();
    }

    void VEGAVertexArray::bind() {
        glBindVertexArray(id);
    }

    void VEGAVertexArray::unbind() {
        glBindVertexArray(0);
    }

    void VEGAVertexArray::destroy() {
        glDeleteVertexArrays(1, &id);
    }
}