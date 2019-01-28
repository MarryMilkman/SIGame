#include "lib.h"
#include "SIGame.hpp"

int		main()
{
	SIGame			*game = new SIGame();

	while (game->countHuman()) {
		game->doCycle();
	}
	delete game;
	system("leaks go_SIGame");
	return(0);
}