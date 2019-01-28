#include "IMenuSIController.hpp"

#include "PlayerH.hpp"
#include "GrayBotH.hpp"

IMenuSIController::IMenuSIController() {

}

IMenuSIController::~IMenuSIController() {

}

// MARK: - pause/start menu

	// pause
int		IMenuSIController::pauseMenu() {
	char	c;

	std::cout << "<----| SIGAME pause |---->\n";
	std::cout << "esc) Continue\n";
	std::cout << "1) Save game\n";
	std::cout << "2) Load save\n";
	std::cout << "3) New game\n";
	std::cout << "4) Exit\n";
	// std::cout << "5) Save menu\n";
	while ((c = _getch()) &&
		(c != '1' && c != '2' && c != '3' && c != '0' && c != '4' && c != 27)) ;
	if (c == '1')
		this->_menuForSave();
	if (c == '2') {
		this->_changeStr = "load";
		return 1;
	}
	else if (c == '3') {
		this->_changeStr = "new";
		return 1;
	}
	else if (c == '4')
		exit(0);
	// else if (c == '5') {
		// this->_saveContr.menuControll();
	// }
	return 0;
}

	// start
void	IMenuSIController::_startMenu() {
	char	c;

	std::cout << "<----| SIGAME |---->\n";
	std::cout << "1) New game\n";
	// std::cout << "2) Load save\n";
	std::cout << "3) Exit\n";
	while ((c = _getch()) && c != '1' && c != '2' && c != '3') ;
	if (c == '1')
		this->_newGame();
	// if (c == '2')
	// 	this->_loadSave();
	if (c == '3')
		exit(0);
}


// MARK: load/save menu

	// load
void	IMenuSIController::_menuForLoad() {
	int		i = -1;
	int		size = this->_listSave.size();
	t_save	save;
	char	c;

	while (++i < size) {
		save = this->_listSave[i];
		std::cout << save.save_id << ") " << save.name << "\n"; 
	}
	while (1) {
		while ((c = _getch()) && c < '0' && c >= '0' + size && c != 27) ;
		if (c == 27)
			break ;
		std::cout << "\nOption for " << c -'0' << ":\n1) load\n2) remove\n";
		while ((c = _getch()) && c != '1' && c != '2' && c != 27) ;
		if (c == '1')
			this->_load(c - '0');
		if (c == '2')
			this->_remove(c - '0');
	}
}

	//save
void	IMenuSIController::_menuForSave() {
	std::cout << "In next patch\n";
}




