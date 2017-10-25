#include "opengl_playground.h"

GLDummyClass::GLDummyClass()
{
    std::cout << "OpenGL Dummy Class Constructed\n";
}
GLDummyClass::~GLDummyClass(){}

void GLDummyClass::gl_dummy_func()
{
    std::cout << "gl dummy func called\n"; 
}

void GLDummyClass::gl_init_window()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    std::cout << "An openGL Window should have been created\n";
};
