#include <iostream>
#include <chrono>
#include <thread>
#include "opengl_playground.h"


int main()
{
    std::cout << "Hello world from main\n";



    GLTutorialClass ctx;
    
    ctx.gl_init_window("Hello World Window");
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //std::array<float, 4> new_bg_color{0.2,0.2,0.2,1.0};
    //std::cout << "Changing background color \n";
    //ctx.change_background_color(new_bg_color);


}
