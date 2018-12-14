#include "lib.h"
#include "SIGame.hpp"

int		main()
{
	SIGame	*game = new SIGame();

	while (game->countHuman()) {
		game->doCycle();
	}
	return(0);
}