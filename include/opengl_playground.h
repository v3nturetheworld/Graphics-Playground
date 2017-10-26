#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class GLTutorialClass
{
public:
    GLTutorialClass();
    ~GLTutorialClass();
    void gl_dummy_func();
    void gl_init_window(const std::string name, int width = 800, int height = 600);
    
    int start_event_loop();

private:
    int ret_code;
    GLFWwindow *window;
};



