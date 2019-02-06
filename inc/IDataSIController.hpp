#ifndef I_DATA_S_I_CONTROLLER_HPP
# define I_DATA_S_I_CONTROLLER_HPP

# include "lib.h"
# include "IHuman.hpp"
# include "Place.hpp"
# include "memlist.hpp"

class IDataSIController
{
public:
	~IDataSIController();

	virtual int				pauseMenu() = 0;


	t_date					date;

	int						countHuman();
	int						countPlace();

	void					talk(IHuman *h1, IHuman *h2);

	Place					*getRandomPlace(int chance);
	IHuman					*getRandomHuman(int chance);

protected:
	IDataSIController();

	memlist<IHuman *>		_peopleList;
	memlist<Place *>		_placeList;

	std::vector<t_save>		_listSave;

	void					_initPeople();
	void					_initPlaces();
	void					_initSaveList();

	void					_load(std::string saveName); //

	void					_save(std::string saveName); //
	void					_createNewSave(std::string	saveName);
	std::string				_insertSql();

	void					_remove(std::string saveName); //
	void					_newGame();
	void					_nullifyGameData();

};

#endif