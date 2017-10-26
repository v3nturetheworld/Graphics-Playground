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
    start_event_loop();
}


int GLTutorialClass::start_event_loop()
{
    std::cout << "Starting main event loop...\n";
    
    while(!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    std::cout << "Main event loop has been exited\n";
}


