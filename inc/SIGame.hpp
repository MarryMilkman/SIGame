#ifndef S_I_GAME_HPP
# define S_I_GAME_HPP

# include "lib.h"
# include "Human.hpp"
# include "Place.hpp"
# include "memlist.hpp"

class SIGame
{
public:
	SIGame();
	SIGame(SIGame const & ref);
	~SIGame();

	
	t_date				date;

	void		doCycle();
	void		bornHuman();

	int			countHuman();
	int			countPlace();

	Place		*getRandomPlace(int chance);
	Human		*getRandomHuman(int chance);

	SIGame		& operator=(SIGame const & ref);

private:

	memlist<Human *>		_peopleList;
	memlist<Place *>		_placeList;

	void				_initPeople();
	void				_initPlaces();

	void				_startCheackHuman(Human const *human);
	bool				_endCheckHuman(Human const *human);

};

#endif