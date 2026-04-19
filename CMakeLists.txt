cmake_minimum_required(VERSION 3.25)
project(saivox-engine)

set(OpenGL_GL_PREFERENCE GLVND)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(saivox-engine
    src/glad/glad.c
    src/main.cpp
    src/GameWindow.cpp
    src/Game.cpp
    src/Renderer.cpp
)

target_include_directories(saivox-engine PRIVATE include)

target_link_libraries(saivox-engine PRIVATE glfw OpenGL::GL)