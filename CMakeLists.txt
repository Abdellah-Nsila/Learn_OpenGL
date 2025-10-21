# =============== STEP 1: Minimum CMake version ===============
cmake_minimum_required(VERSION 3.16)
project(Learn_OpenGL LANGUAGES CXX C)

# =============== STEP 2: Set C++ standard ===============
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =============== STEP 3: Output directories ===============
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# =============== STEP 4: Find system libraries ===============
find_package(glfw3 REQUIRED)      # Finds installed GLFW
find_package(OpenGL REQUIRED)     # Finds OpenGL

# =============== STEP 5: Include directories ===============
include_directories(
    extern/glad/include          # For #include <glad/glad.h>
    extern/glm                   # For #include <glm/glm.hpp>
    extern/stb                   # For #include <stb/stb_image.h>
    ${GLFW_INCLUDE_DIRS}         # From find_package(glfw3)
)

# =============== STEP 7: Gather all your source files ===============
file(GLOB_RECURSE SOURCES
    src/*.cpp
    extern/glad/src/glad.c
    extern/stb/stb_image.cpp
)

# =============== STEP 8: Create the executable ===============
add_executable(${PROJECT_NAME} ${SOURCES})

# =============== STEP 9: Link libraries ===============
target_link_libraries(${PROJECT_NAME}
    glfw                # From find_package(glfw3)
    OpenGL::GL          # OpenGL functions
)


# =============== STEP 10: Copy assets to build folder ===============
# So your program can find shaders/textures at runtime
file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

