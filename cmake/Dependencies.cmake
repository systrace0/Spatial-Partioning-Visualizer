find_package(OpenGL REQUIRED)

include(FetchContent)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    glfw
    URL https://github.com/glfw/glfw/archive/refs/tags/3.4.tar.gz
    URL_HASH SHA256=c038d34200234d071fae9345bc455e4a8f2f544ab60150765d7704e08f3dac01
)
FetchContent_MakeAvailable(glfw)


FetchContent_Declare(
    imgui
    URL https://github.com/ocornut/imgui/archive/refs/tags/v1.92.7-docking.tar.gz
    URL_HASH SHA256=2c58e28c957497eba0ed01c48a0bc5f118ec5f10a1c3721ba9436253a623bd72
)
FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
    glm
    URL https://github.com/g-truc/glm/archive/refs/tags/1.0.3.tar.gz
    URL_HASH SHA256=6775e47231a446fd086d660ecc18bcd076531cfedd912fbd66e576b118607001
)
FetchContent_MakeAvailable(glm)

add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/spdlog)

include(${CMAKE_CURRENT_LIST_DIR}/Targets.cmake)