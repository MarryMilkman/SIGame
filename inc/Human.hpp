#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "lib.h"

class SIGame;

class Human
{
public:
	Human(std::string name, std::string gender, bool isPlayer, SIGame *ptrSIGame);
	Human(std::string name, std::string gender, bool isPlayer, int age, t_stats stats, SIGame *ptrSIGame);
	Human(Human const & ref);
	~Human();
	
	void			status() const;
	void			doAction();

	bool				isPlayer;
	std::string			name;
	int					age;
	std::string const	gender;

	t_stats				stats;
	SIGame				*ptrSIGame;

	Human	& operator=(Human const & ref);

private:
	Human();
	
	void		_visitPlace();
	

	// void			_prolog_start_cut_scene() const;
	// void			_prolog_end_cut_scene() const;
	// std::string		_gender_cut_scene() const;
	// std::string		_nema_cut_scene() const;
};

#endif