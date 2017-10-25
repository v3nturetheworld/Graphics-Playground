#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


struct TestStruct
{
    std::string msg;
    TestStruct(const std::string _msg) : msg(_msg)
    {
        std::cout << "TestStruct constructed with message: " << msg << std::endl;
    }
};


class GLDummyClass
{
public:
    GLDummyClass();
    ~GLDummyClass();
    void gl_dummy_func();
    void gl_init_window();
private:
    int ret_code;
};



