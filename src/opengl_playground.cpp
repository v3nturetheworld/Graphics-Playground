#include "opengl_playground.h"

//General glfw error callback handler.
static void error_callback(int error, const char* description)
{
    std::cerr << "[Error!][" << error << "]: " << description << '\n';
}

void framebuffer_size_callback(GLFWwindow *w, int width, int height)
{
    std::cout << "Resizing window: new width: " << width << " new height: " << height << '\n';
    glViewport(0, 0, width, height);
}

GLTutorialClass::GLTutorialClass()
{
    std::cout << "OpenGL Dummy Class Constructed\n";
    window = nullptr;
    bg_color = {0,0,0,1};
    induce_seizures = true;
    is_key_down = false;
}

GLTutorialClass::~GLTutorialClass()
{
    glfwTerminate();
}

void GLTutorialClass::gl_dummy_func()
{
    std::cout << "gl dummy func called\n"; 
}

void GLTutorialClass::gl_init_window(const std::string name, int width, int height)
{
    glfwSetErrorCallback(error_callback);

    if(!glfwInit())
    {
        std::cerr << "[Error!]: glfwInit failed.\n";
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

    if(!window)
    {
        std::cerr << "[Error!] Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    //Abstract handler for handling some of the non-cross platform setup stuff
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cerr << "[Error!] Failed to initialize GLAD\n";
        return;
    }

    //Handle coordinate transformation from gl-coords to screen coords
    glViewport(0,0, width, height);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    std::cout << "An openGL Window should have been created\n";
    
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
    start_render_loop();
}


int GLTutorialClass::start_render_loop()
{
    std::cout << "Starting main event loop...\n";
   
    long count = 0;
    while(!glfwWindowShouldClose(window))
    {
        process_user_input();
        glClearColor(bg_color[0],bg_color[1],bg_color[2],bg_color[3]);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();

        if(count % 25 == 0)
            set_random_bg_color();
        ++count;
    }

    std::cout << "Main event loop has been exited\n";
}

void GLTutorialClass::process_user_input()
{
    if(window)
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            std::cout << "Escape key pressed! Closing window.\n";
            glfwSetWindowShouldClose(window, true);
        }
        else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            std::cout << "Seizure inducing mode " << ((induce_seizures) ? "Enabled" : "Disabled") << '\n';
            induce_seizures = !induce_seizures;
        }
    }

}

void GLTutorialClass::set_random_bg_color()
{
    float red =  static_cast<float>(std::rand() % 100) / 100;
    float green =  static_cast<float>(std::rand() % 100) / 100;
    float blue = static_cast<float>(std::rand() % 100) / 100;
    change_background_color(red,green,blue,1.0f);

    std::cout << "New Random Background Color: " << bg_color[0] << ", " << bg_color[1] << ", " << bg_color[2] << "\n";
}
void GLTutorialClass::change_background_color(const std::array<float, 4> bg)
{
    bg_color = bg;
}

void GLTutorialClass::change_background_color(const float red, const float green, const float blue, const float alpha)
{
    bg_color = {red,blue,green,alpha};
}
