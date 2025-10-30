cmake_minimum_required(VERSION 3.16)
project(Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------
# 1. Precompiled header
# ---------------------------
set(PCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/enginepch.h")

# ---------------------------
# 2. Source collection
# ---------------------------
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(Engine STATIC ${ENGINE_SOURCES})

# ---------------------------
# 3. Public / Private include folders
# ---------------------------

# Public headers are those exposed to the game/editor using the engine.
target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/spdlog/include
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glm
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glad/include
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/stb_image
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Core
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Renderer
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Utils
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Debug
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Events
)

# ---------------------------
# 4. Definitions
# ---------------------------
target_compile_definitions(Engine
    PRIVATE
        $<$<CONFIG:Debug>:ENGINE_DEBUG>
)

# ---------------------------
# 5. External dependencies
# ---------------------------
find_package(OpenGL REQUIRED)
target_link_libraries(Engine PRIVATE OpenGL::GL)

# ---------------------------
# 6. Precompiled Header (CMake >= 3.16)
# ---------------------------
if (EXISTS ${PCH_FILE})
    target_precompile_headers(Engine PRIVATE ${PCH_FILE})
endif()
