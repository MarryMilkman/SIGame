#include "SIGame.hpp"

#include "PlayerH.hpp"
#include "GrayBotH.hpp"

SIGame::SIGame() {
	this->_startMenu();
}

SIGame::SIGame(SIGame const & ref) {
	*this = ref;
}

SIGame		& SIGame::operator=(SIGame const & ref) {
	this->_peopleList = ref._peopleList;
	this->date = ref.date;
	this->_placeList = ref._placeList;
	return (*this);
}

SIGame::~SIGame() {
	int 		size = this->_placeList->size();
	Place		*place;

	this->_nullifyGameData();
	while (size-- > 0) {
		place = this->_placeList->pop(size);
		delete place;
	}
	std::cout << "GG & WP!\n";
}

// MARK: - pablic func

void		SIGame::bornHuman() {

}

// Place		*SIGame::getRandomPlace(int chance) {
// 	int				m;
// 	int				size = this->_placeList.size();
// 	Place			*place;

// 	m = 0;
// 	if (!chance)
// 		return 0;
// 	m = size * 100 / chance;
// 	m = rand() % m;
// 	if (m >= size)
// 		return 0;
// 	place = 0;
// 	try {
// 		place = this->_placeList[m];
// 	} catch (std::exception & e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	return place;
// }

// IHuman		*SIGame::getRandomHuman(int chance) {
// 	int				m;
// 	int				size = this->_peopleList.size();
// 	IHuman			*human;

// 	if (!chance)
// 		return 0;
// 	m = size * 100 / chance;
// 	m = rand() % m;
// 	if (m >= size)
// 		return 0;
// 	human = 0;
// 	try {
// 		human = this->_peopleList[m];
// 	} catch (std::exception & e) {}
// 	return human;
// }

// MARK: - Cycle logic

void		SIGame::doCycle() {
	int	i;
	IHuman			*player;
	IHuman			*delH = 0;

	i = 0;
	std::cout << "valera!!!!!\n";
	while (i < this->_peopleList->size()) {
		std::cout << "de?\n";
		if (this->_changeStr != "") {
			this->_changeMemory();
			return ;
		}
		//////////////////////
		std::cout << this->_peopleList->size() << "= size; i = " <<  i << "??????\n";
		//////////////////////
		try {
			player = (*this->_peopleList)[i];
		} catch (std::exception & e) {
			return ;
		}
		this->_startCheckHuman(player);
		player->status();
		player->doAction();
		player->age++;
		if (this->_endCheckHuman(player)) {
			std::cout << "chooooooooo\n";
			delH = this->_peopleList->pop(i);
			delete delH;
		}
		i++;
	}
	this->date.year++;
}

// MARK: - cheack cycle

void		SIGame::_startCheckHuman(IHuman *human) {
	// human->stats.happy -= 1;
}

bool		SIGame::_endCheckHuman(IHuman *human) {
	int n = rand();

	if ((unsigned)human->age > n % 100 + 50)
		return (true);
	return (false);
}

void		SIGame::_changeMemory() {
	std::string		change = this->_changeStr;

	this->_changeStr = "";
	if (change == "new") {
		this->_newGame();
	}
	if (change == "load") {
		this->_menuForLoad();
	}
}