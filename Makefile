# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = game
GPP         = g++
GPPFLAGS    = -Wall -Wextra -Werror -std=c++17
DFLAGS      = -MMD -MP
INCLUDES    = -Iincludes -Iincludes/core -Iincludes/game -Iincludes/classes

# --- Directories ---
SRC_DIR     = src
BUILD_DIR   = build
PCH_HEADER  = includes/core/Engine.hpp
PCH_FILE    = $(PCH_HEADER).gch

# **************************************************************************** #
#                              SOURCE FILE DISCOVERY                             #
# **************************************************************************** #

# Automatically find all .cpp and .c files in SRC_DIR
SRCS_CPP := $(shell find $(SRC_DIR) -name "*.cpp")
SRCS_C   := $(shell find $(SRC_DIR) -name "*.c")

# Map to object files in BUILD_DIR
OBJS_CPP := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS_CPP))
OBJS_C   := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS_C))
OBJS     := $(OBJS_CPP) $(OBJS_C)

# Dependency files for auto header tracking
DEPS_CPP := $(OBJS_CPP:.o=.d)
DEPS_C   := $(OBJS_C:.o=.d)

# **************************************************************************** #
#                                   LIBS                                        #
# **************************************************************************** #

LIBS = -lglfw -lGL -ldl -lpthread -lX11 -lXrandr -lXi

# **************************************************************************** #
#                                   RULES                                       #
# **************************************************************************** #

all: $(PCH_FILE) $(NAME)

# Link executable
$(NAME): $(OBJS)
	$(GPP) $(GPPFLAGS) $(OBJS) -o $@ $(LIBS)

# Compile C++ files using PCH
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(PCH_FILE)
	@mkdir -p $(dir $@)
	$(GPP) $(GPPFLAGS) $(INCLUDES) -include $(PCH_HEADER) $(DFLAGS) -c $< -o $@

# Compile C files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(GPP) $(GPPFLAGS) $(INCLUDES) $(DFLAGS) -c $< -o $@

# Build the PCH with auto-deps
$(PCH_FILE): $(PCH_HEADER)
	@echo "Building PCH: $<"
	$(GPP) $(GPPFLAGS) $(INCLUDES) -x c++-header $(DFLAGS) $< -o $@

# Include dependencies
-include $(DEPS_CPP) $(DEPS_C)
# Include dependency tracking for PCH
-include $(PCH_FILE:.gch=.d)

# Clean objects
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(OBJS)

# Full clean including binary and PCH
fclean: clean
	rm -f $(NAME)
	rm -f $(PCH_FILE)

# Rebuild everything
re: fclean all

# Fast build: only rebuild changed files (keeps binary)
fast: $(PCH_FILE)
	@$(MAKE) $(NAME) --no-print-directory

.PHONY: all clean fclean re fast
