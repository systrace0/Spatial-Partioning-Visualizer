#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
namespace
{
    void ErrorCallBack(int error, const char* description)
    {
        std::cerr << "GLFW Error [" << error << "]: " << description << '\n';
    }

    void frameBuffer_size_callback(GLFWwindow* window, int wdith, int height)
    {
        glViewport(0, 0, wdith, height);
    }

    void processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, 1);
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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    const GLubyte* vendor = glGetString(GL_VENDOR);
    const GLubyte* renderer = glGetString(GL_VERSION);
    const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

    int major = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
    int minor = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);

    while (glfwWindowShouldClose(window) == 0)
    {
        glfwPollEvents();
        glClearColor(0.08F, 0.08F, 0.10F, 1.0F);
        glClear(GL_COLOR_BUFFER_BIT);

        processInput(window);
        glfwSetFramebufferSizeCallback(window, frameBuffer_size_callback);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

        // Window creation
        ImGui::Begin("SPV - Debug Info");
        ImGui::Text("Window: %d x %d", window_width, window_height);
        ImGui::Text("Vendor: %s", vendor);
        ImGui::Text("Renderer: %s", renderer);
        ImGui::Text("GLSL: %s", glslVersion);
        ImGui::Text("GL MAJOR: %d", major);
        ImGui::Text("GL MINOR: %d", minor);
        ImGui::End();

        ImGui::ShowDemoWindow();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}