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

	Place		*getRandomPlace();
	// Human		*getRandomHuman();

	SIGame		& operator=(SIGame const & ref);

private:

	std::vector<Human>	_people;
	memlist<Place>		_placeList;

	void				_initPeople();
	void				_initPlaces();

	void				_startCheackHuman(Human & human);
	bool				_endCheckHuman(Human & human);

};

#endif