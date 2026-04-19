cmake_minimum_required(VERSION 3.10)
project(saivox-engine)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(saivox-engine
    src/glad/glad.c
    src/main.cpp
    src/GameWindow.cpp
)

target_include_directories(saivox-engine PRIVATE include)

target_link_libraries(saivox-engine PRIVATE glfw OpenGL::GL)