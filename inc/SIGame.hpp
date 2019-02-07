#ifndef S_I_GAME_HPP
# define S_I_GAME_HPP

# include "lib.h"
# include "IHuman.hpp"
# include "Place.hpp"
# include "memlist.hpp"
# include "IDataSIController.hpp"
# include "IMenuSIController.hpp"

class SIGame: public IMenuSIController
{
public:
	SIGame();
	SIGame(SIGame const & ref);
	virtual ~SIGame();

	void		doCycle();

	void		bornHuman();

	// Place		*getRandomPlace(int chance);
	// IHuman		*getRandomHuman(int chance);

	SIGame		& operator=(SIGame const & ref);

private:
	void				_changeMemory();

	void				_startCheckHuman(IHuman *human);
	bool				_endCheckHuman(IHuman *human);
};

#endif