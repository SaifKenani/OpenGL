#include "Texture.h"
#include <iostream>

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
    // تعيين نوع الـ Texture
    type = texType;
    this->slot=slot;
    // تخزين أبعاد الصورة وعدد القنوات
    int widthImg, heightImg, numColCh;
    // قلب الصورة عموديًا لجعلها تظهر بشكل صحيح
    stbi_set_flip_vertically_on_load(true);
    // تحميل الصورة من الملف
    unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

    if (bytes) {
        // تحديد التنسيق تلقائيًا بناءً على عدد القنوات
        if (numColCh == 1) {
            format = GL_RED;
            std::cout<<"GL_RED";
        } else if (numColCh == 3) {
            format = GL_RGB;
            std::cout<<"GL_RGB";

        } else if (numColCh == 4) {
            format = GL_RGBA;
            std::cout<<"GL_RGBA";

        } else {
            std::cerr << "Unsupported number of channels: " << numColCh << std::endl;
            stbi_image_free(bytes);
            return;
        }

        // إنشاء Texture في OpenGL
        glGenTextures(1, &ID);
        glActiveTexture(slot);
        glBindTexture(texType, ID);

        // إعداد خيارات التغليف والترشيح
        glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

        // تعيين الصورة كـ Texture
        glTexImage2D(texType, 0, format, widthImg, heightImg, 0, format, pixelType, bytes);
        glGenerateMipmap(texType);

        // تحرير البيانات المحملة
        stbi_image_free(bytes);

        // فك الربط مع Texture
        glBindTexture(texType, 0);
    } else {
        std::cerr << "Failed to load texture: " << image << std::endl;
    }
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit) {
    GLuint texUni = glGetUniformLocation(shader.ID, uniform);
    shader.use();
    glUniform1i(texUni, unit);
}

void Texture::Bind() {
    glActiveTexture(slot);
    glBindTexture(type, ID);
}

void Texture::Unbind() {
    glBindTexture(type, 0);
}

void Texture::Delete() {
    glDeleteTextures(1, &ID);
}