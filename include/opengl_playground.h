#pragma once

#include <iostream>
#include <array>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
    


class GLTutorialClass
{
public:
    GLTutorialClass();
    ~GLTutorialClass();
    void gl_dummy_func();
    void gl_init_window(const std::string name, int width = 800, int height = 600);
    
    int start_render_loop();
    void process_user_input();
    void change_background_color(const std::array<float, 4> bg);
    void change_background_color(const float red, const float green, const float blue, const float alpha);
private:
    int ret_code;
    GLFWwindow *window;
    std::array<float, 4> bg_color;
    bool induce_seizures, is_key_down;

    void set_random_bg_color();
};



