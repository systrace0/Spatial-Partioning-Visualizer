cmake_minimum_required(VERSION 3.25...4.0)

project(SPV VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(SPV_ENABLE_ASAN "Enable AddressSanitizer" OFF)
option(SPV_ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" OFF)
option(SPV_ENABLE_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
option(SPV_ENABLE_CLANG_TIDY "Enable clang-tidy if available" ON)

include(cmake/Dependencies.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/Sanitizer.cmake)
include(cmake/StaticAnalyzer.cmake)

add_subdirectory(src)