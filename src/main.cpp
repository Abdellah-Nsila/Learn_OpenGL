#include "core/Engine.hpp"

float	transparent = 0.0;

int	main()
{
	t_game	game{};

	init_engine(&game);
	glfwDestroyWindow(game.window);
    glfwTerminate();
    return 0;
}

