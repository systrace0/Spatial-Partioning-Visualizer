#
# Targets.cmake
# Central place for dependency targets owned by this project.
#

add_library(glad STATIC
    ${CMAKE_SOURCE_DIR}/vendor/glad/src/glad.c
)
target_include_directories(glad PUBLIC
    ${CMAKE_SOURCE_DIR}/vendor/glad/include
)

# ImGui - no CMakeLists of its own, build manually
if(SPV_ENABLE_IMGUI)
    add_library(imgui STATIC
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    )
    target_include_directories(imgui PUBLIC
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
    )
    target_link_libraries(imgui PUBLIC glfw)
endif()

add_library(spv_vendor INTERFACE)
target_link_libraries(spv_vendor
    INTERFACE
        OpenGL::GL
        glfw
        glad
        glm::glm
)

if(SPV_ENABLE_IMGUI)
    target_link_libraries(spv_vendor
        INTERFACE
            imgui
    )
endif()

