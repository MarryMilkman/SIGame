#ifndef SAVE_CONTROLLER_HPP
# define SAVE_CONTROLLER_HPP

# include "lib.h"
# include "sqlite3.h"

class SaveController
{
public:
	SaveController();
	~SaveController();
	
	void		menuControll();

	// std::vector<t_save>		listSave;

	// void		createSave();
	// void		menuForLoad();

private:

	// void		_loadSave(int save_id);
	// void		_initSaveList();

	void		_showSaveList();
	// void		_removeSave(int save_id);
};

#endif