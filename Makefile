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
CLASS_SRC	= $(CLASS_DIR)/Shader.cpp
SRCS_CPP    = $(SRC_DIR)/main.cpp $(SRC_DIR)/init.cpp $(SRC_DIR)/events.cpp $(SRC_DIR)/helloTriangle.cpp \
			$(CLASS_SRC)
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
%.o: %.cpp	$(INC_DIR)/game.hpp $(INC_DIR)/includes.hpp $(INC_DIR)/typedef.hpp $(INC_DIR)/settings.hpp $(INC_DIR)/init.hpp \
			$(INC_DIR)/events.hpp
	$(GPP) $(GPPFLAGS) $(INCLUDES) -c $< -o $@

# Compile .c files (for glad)
%.o: %.c
	$(GPP) $(GPPFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
