//
// Created by saif on 12/30/24.
//

#include "Building.h"
#include <glad/glad.h>
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

Building::Building(GLfloat vertices, GLuint indices) {
}

void Building::load() {
    VAO.Bind();
    VBO.setVBO(vertices, sizeof(vertices));
    VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *) 0);
    VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    VAO.LinkAttrib(VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *) (6 * sizeof(float)));

    VAO.Unbind();
    VBO.Unbind();


}

void Building::Draw() {
    EBO.setEBO(indices, sizeof(indices));
    EBO.Bind();
    VAO.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    VAO.Unbind();
    EBO.Unbind();

}


void Building::Delete() {
}
