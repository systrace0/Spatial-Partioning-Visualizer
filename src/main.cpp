#include <iostream>
#include <stdexcept>

#include <GLFW/glfw3.h>
#include <glad/glad.h>
namespace
{
    void ErrorCallBack(int error, const char* description)
    {
        std::cerr << "GLFW Error [" << error << "]: " << description << '\n';
    }
} // namespace

int main()
{
    constexpr int window_width{ 1280 };
    constexpr int window_height{ 720 };

    glfwSetErrorCallback(ErrorCallBack);

    if (glfwInit() == 0)
    {
        std::cerr << "Failed to initialize GLFW.\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window =
        glfwCreateWindow(window_width, window_height, "Spatial Partitioning Visualizer", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cerr << "Failed to create GLFW window.\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)) == 0)
    {
        std::cerr << "Failed to initialize GLAD.\n";
        glfwDestroyWindow(window);
        return -1;
    }

    const GLubyte* vendor = glGetString(GL_VENDOR);
    const GLubyte* renderer = glGetString(GL_VERSION);
    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

    int major{ 0 };
    int minor{ 0 };
    glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
    glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);

    major = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
    minor = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);

    std::cout << "Vendor:        " << (vendor ? reinterpret_cast<const char*>(vendor) : "Unknown") << '\n';
    std::cout << "Renderer:      " << (renderer ? reinterpret_cast<const char*>(renderer) : "Unknown")
              << '\n';
    std::cout << "OpenGL:        " << (version ? reinterpret_cast<const char*>(version) : "Unknown") << '\n';
    std::cout << "GLSL:          " << (glslVersion ? reinterpret_cast<const char*>(glslVersion) : "Unknown")
              << '\n';
    std::cout << "Context:       " << major << '.' << minor << '\n';

    while (glfwWindowShouldClose(window) == 0)
    {
        glClearColor(0.08f, 0.08f, 0.10f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}