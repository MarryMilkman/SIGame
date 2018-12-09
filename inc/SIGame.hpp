#ifndef S_I_GAME_HPP
# define S_I_GAME_HPP

# include "lib.h"
# include "Human.hpp"
# include "Place.hpp"

class SIGame
{
public:
	SIGame();
	SIGame(SIGame const & ref);
	~SIGame();

	std::vector<Human>	protagonist;
	std::vector<Human>	people;
	std::vector<Place>	places;
	t_date				date;

	void		doCycle();
	void		bornHuman();

	SIGame		& operator=(SIGame const & ref);

private:

	void		_initPeople();
	void		_initPlaces();

	void		_startCheackHuman(Human & human);
	bool		_endCheckHuman(Human & human);

};

#endif