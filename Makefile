# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = game
GPP         = g++
GPPFLAGS    = -Wall -Wextra -Werror -std=c++17
INCLUDES    = -Iincludes -Iincludes/classes

# --- sources ---
INC_DIR 	= includes
SRC_DIR     = src
CLASS_DIR	= $(SRC_DIR)/classes
CLASS_SRC	= $(CLASS_DIR)/VAO.cpp $(CLASS_DIR)/VBO.cpp $(CLASS_DIR)/EBO.cpp $(CLASS_DIR)/Shader.cpp \
			$(CLASS_DIR)/Texture.cpp
SRCS_CPP    = $(SRC_DIR)/main.cpp $(SRC_DIR)/init.cpp $(SRC_DIR)/events.cpp $(SRC_DIR)/helloTriangle.cpp \
			$(SRC_DIR)/render.cpp $(CLASS_SRC)
SRCS_C      = $(SRC_DIR)/glad.c
OBJS_CPP    = $(SRCS_CPP:.cpp=.o)
OBJS_C      = $(SRCS_C:.c=.o)
OBJS        = $(OBJS_CPP) $(OBJS_C)

# --- libs (for GLFW, OpenGL, X11, etc.) ---
LIBS        = -lglfw -lGL -ldl -lpthread -lX11 -lXrandr -lXi

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(GPP) $(GPPFLAGS) $(OBJS) -o $(NAME) $(LIBS)

# Compile .cpp files
%.o: %.cpp	$(INC_DIR)/* $(INC_DIR)/classes/* $(INC_DIR)/utils/*
	$(GPP) $(GPPFLAGS) $(INCLUDES) -c $< -o $@

# Compile .c files (for glad)
%.o: %.c
	$(GPP) $(GPPFLAGS) $(INCLUDES) -c $< -o $@

includes.hpp.gch: includes.hpp
	$(GPP) $(GPPFLAGS) $(INCLUDES) -x c++-header includes.hpp -o includes.hpp.gch

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
