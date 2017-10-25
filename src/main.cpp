#include <iostream>
#include "opengl_playground.h"


int main()
{
    std::cout << "Hello world from main\n";


    TestStruct t("foo");
    

    GLDummyClass ctx;
    ctx.gl_init_window();
}
