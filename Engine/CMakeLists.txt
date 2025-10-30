cmake_minimum_required(VERSION 3.16)
project(Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Precompiled header
set(PCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/enginepch.h")

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(Engine STATIC ${ENGINE_SOURCES})

target_include_directories(Engine
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/stb_image
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link system dependencies (e.g. OpenGL)
find_package(OpenGL REQUIRED)
target_link_libraries(Engine PRIVATE OpenGL::GL)
