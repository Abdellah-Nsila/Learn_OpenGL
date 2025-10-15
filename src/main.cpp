#include "core/Engine.hpp"

int	main()
{
	t_game	game{};

	init_engine(&game);
	glfwDestroyWindow(game.window);
    glfwTerminate();
    return 0;
}

