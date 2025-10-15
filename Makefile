# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = game
GPP         = g++
GPPFLAGS    = -Wall -Wextra -Werror -std=c++17
DFLAGS		= -MMD -MP
INCLUDES	= -Iincludes -Iincludes/core -Iincludes/game -Iincludes/classes

# --- Directories ---
BUILD_DIR	= build
INC_DIR 	= includes
SRC_DIR     = src
CLASS_DIR	= $(SRC_DIR)/classes

# --- Sources ---
CLASS_SRC	= $(CLASS_DIR)/VAO.cpp $(CLASS_DIR)/VBO.cpp $(CLASS_DIR)/EBO.cpp \
			  $(CLASS_DIR)/Shader.cpp $(CLASS_DIR)/Texture.cpp
SRCS_CPP    = $(SRC_DIR)/main.cpp $(SRC_DIR)/init.cpp $(SRC_DIR)/events.cpp \
			  $(SRC_DIR)/helloTriangle.cpp $(SRC_DIR)/render.cpp \
			  $(CLASS_SRC) $(SRC_DIR)/core/STB_IMPL.cpp
SRCS_C      = $(SRC_DIR)/glad.c

OBJS_CPP    = $(SRCS_CPP:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
OBJS_C      = $(SRCS_C:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS        = $(OBJS_CPP) $(OBJS_C)

# --- Automatic dependency tracking ---
DEPFILES 	= $(OBJS:.o=.d)
-include $(DEPFILES)

# --- Libraries (GLFW, OpenGL, etc.) ---
LIBS        = -lglfw -lGL -ldl -lpthread -lX11 -lXrandr -lXi

# --- Precompiled Header ---
PCH_HEADER  = includes/core/Engine.hpp
PCH_FILE    = $(PCH_HEADER).gch

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(PCH_FILE) $(NAME)

# Link executable
$(NAME): $(OBJS)
	$(GPP) $(GPPFLAGS) $(OBJS) -o $(NAME) $(LIBS)

# Compile C++ files using the precompiled header
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(PCH_FILE)
	@mkdir -p $(dir $@)
	$(GPP) $(GPPFLAGS) $(INCLUDES) -include $(PCH_HEADER) $(DFLAGS) -c $< -o $@

# Compile C files (glad, etc.)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(GPP) $(GPPFLAGS) $(INCLUDES) $(DFLAGS) -c $< -o $@

# Build the precompiled header only if it or its includes change
$(PCH_FILE): $(PCH_HEADER)
	$(GPP) $(GPPFLAGS) $(INCLUDES) $(DFLAGS) -x c++-header $< -o $@
-include $(PCH_FILE:.gch=.d)

# Clean object files
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(OBJS)

# Full clean (including binary + precompiled header)
fclean: clean
	rm -f $(NAME)
	rm -f $(PCH_FILE)

# Rebuild everything
re: fclean all

# Fast build: only recompile changed .cpp files (keeps binary)
fast:
	@$(MAKE) $(NAME) --no-print-directory

.PHONY: all clean fclean re fast
