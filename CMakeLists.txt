cmake_minimum_required(VERSION 3.29)
project(OpenGL_Project VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
include_directories(lib
        lib/glad/include)
configure_file(
        /home/saif/CLionProjects/bonus/lib/root_directory.h.in
        /home/saif/CLionProjects/bonus/lib/root_directory.h
)





add_executable(OpenGL_Project src/main.cpp
        src/glad.c
        src/EBO.cpp
        src/VBO.cpp
        src/VAO.cpp
        src/Texture.cpp
        src/stb.cpp
        lib/DrawableObject.h
        lib/Building.h
        src/Building.cpp
        lib/shader_m.h
)

target_link_libraries(OpenGL_Project glfw)
target_link_libraries(OpenGL_Project glm)
