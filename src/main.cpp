#include "lib.h"
#include "SIGame.hpp"

int		main()
{
	SIGame	*g_Game = new SIGame();

	while (g_Game->people.size()) {
		g_Game->doCycle();
	}
	return(0);
}