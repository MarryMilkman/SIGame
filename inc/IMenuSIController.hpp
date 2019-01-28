#ifndef I_MENU_S_I_CONTROLLER_HPP
# define I_MENU_S_I_CONTROLLER_HPP

# include "IDataSIController.hpp"

class IMenuSIController: public virtual IDataSIController
{
public:
	~IMenuSIController();

	int			pauseMenu();

protected:
	IMenuSIController();

	std::string			_changeStr;

	void				_startMenu();

	void				_menuForLoad();
	void				_menuForSave();

	
};

#endif