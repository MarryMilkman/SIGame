#ifndef I_HUMAN_HPP
# define I_HUMAN_HPP

# include "lib.h"
# include "memlist.hpp"

class IDataSIController;
class Place;
// class IAction;


class IHuman
{
public:
	virtual ~IHuman();

	std::string			name;
	bool				isPlayer;
	int					age;
	std::string			gender;
	IDataSIController	*ptrSIGame;
	t_stats				stats;
	std::string			botType;
	memlist<Place *>	*familiarPlaceList;
	memlist<IHuman *>	*familiarHumanList;

	virtual void		doAction() = 0;
	virtual bool		getAnswer(IHuman const *h_ask, std::string const object) const = 0;

	void				status() const;


	IHuman	& operator=(IHuman const & ref);

protected:

	void				_initPlaceList(bool isNew);
	void				_initHumanList();

	void				_walk();
	void				_talkTo(IHuman *h_des);

	void				_resultAnswer(IHuman const *h_ask, std::string const object, bool answ) const;

	// void			_prolog_start_cut_scene() const;
	// void			_prolog_end_cut_scene() const;
	// std::string		_gender_cut_scene() const;
	// std::string		_nema_cut_scene() const;
};

#endif