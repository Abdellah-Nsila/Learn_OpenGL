#include "prototypes.hpp"

int	main()
{
	t_game	game{};

	init_engine(&game);
	// Destroy Window 
	glfwDestroyWindow(game.window);
    glfwTerminate();
    return 0;
}
