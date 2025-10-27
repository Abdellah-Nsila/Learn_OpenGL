cmake_minimum_required(VERSION 3.16)
project(OpenGL_Tuto VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Search for package
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# ------------------------------------------
# Executable
# ------------------------------------------
add_executable(OpenGL_Tuto
	src/glad.c
	src/stb_image.h
	src/config.h
	src/config.cpp
	src/linear_algebros.h
	src/linear_algebros.cpp
	src/main.cpp
	src/Shader.hpp
	src/Shader.cpp
	src/Material.hpp
	src/Material.cpp
	src/Triangle_mesh.hpp
	src/Triangle_mesh.cpp
	)

target_include_directories(OpenGL_Tuto
	PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR/dependencies}"
	"${CMAKE_CURRENT_SOURCE_DIR/src}")

target_link_libraries(OpenGL_Tuto
	OpenGL::GL
	${GLFW3_LIBRARY} glfw
)

# #------------------------------------------
# # Dependencies management (using FetchContent)
# #------------------------------------------
# include(FetchContent)

# # --- GLFW ---
# FetchContent_Declare(
# 	glfw
# 	GIT_REPOSITORY https://github.com/glfw/glfw.git
# 	GIT_TAG latest
# )
# FetchContent_MakeAvailable(glfw)

# # --- GLAD ---
# FetchContent_Declare(
#   glad
#   GIT_REPOSITORY https://github.com/Dav1dde/glad.git
#   GIT_TAG master
# )
# FetchContent_MakeAvailable(glad)

# # --- GLM ---
# FetchContent_Declare(
#   glm
#   GIT_REPOSITORY https://github.com/g-truc/glm.git
#   GIT_TAG master
# )
# FetchContent_MakeAvailable(glm)