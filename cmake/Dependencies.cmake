find_package(OpenGL REQUIRED)

include(FetchContent)

option(SPV_ENABLE_IMGUI "Build Dear ImGui vendored sources" OFF)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    glfw
    URL https://github.com/glfw/glfw/archive/refs/tags/3.4.tar.gz
)
FetchContent_MakeAvailable(glfw)

if(SPV_ENABLE_IMGUI)
    FetchContent_Declare(
        imgui
        URL https://github.com/ocornut/imgui/archive/refs/heads/docking.zip
    )
    FetchContent_MakeAvailable(imgui)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/Targets.cmake)