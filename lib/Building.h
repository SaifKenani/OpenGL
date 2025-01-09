//
// Created by saif on 12/30/24.
//

#ifndef BUILDING_H
#define BUILDING_H

#include "DrawableObject.h"
#include <vector>
#include "glad/glad.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

class Building {

public:
    GLfloat *vertices;
    GLuint *indices;
    class VAO VAO;
    class  VBO VBO;
    class  EBO EBO;

    Building(GLfloat vertices, GLuint indices);

    void load();

    void Draw();

    void Delete();

};

#endif // BUILDING_H
