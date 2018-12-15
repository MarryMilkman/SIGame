#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "lib.h"
# include "memlist.hpp"

class SIGame;
class Place;
class IAction;

typedef struct			s_pList
{
	Place				*Place;
	struct s_avPlaces	*next;
}						t_pList;

class Human
{
public:
	Human(
		std::string name,
		std::string gender,
		bool isPlayer,
		SIGame *ptrSIGame,
		std::string ctionModel
	);
	
	Human(
		std::string name,
		std::string gender,
		bool isPlayer,
		int age,
		t_stats stats,
		SIGame *ptrSIGame,
		std::string ctionModel
	);
	
	Human(Human const & ref);
	~Human();
	
	void			status() const;
	void			doAction();

	bool				isPlayer;
	std::string			name;
	int					age;
	std::string const	gender;
	SIGame				*ptrSIGame;

	t_stats				stats;
	memlist<Place *>	familiarPlaceList;
	memlist<Human *>	familiarHumanList;

	Human	& operator=(Human const & ref);

private:
	Human();
	
	IAction		*_action;
	void		_initPlaceList();
	void		_initHuamnList();
	

	// void			_prolog_start_cut_scene() const;
	// void			_prolog_end_cut_scene() const;
	// std::string		_gender_cut_scene() const;
	// std::string		_nema_cut_scene() const;
};

#endif