#include "SIGame.hpp"

#include "PlayerH.hpp"
#include "GrayBotH.hpp"

SIGame::SIGame() {
	this->_initPlaces();
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
	int 		size = this->_placeList.size();
	Place		*place;

	this->_nullifyGameData();
	while (size-- > 0) {
		place = this->_placeList.pop(size);
		delete place;
	}
	std::cout << "GG & WP!\n";
}

// MARK: - pablic func

void		SIGame::bornHuman() {

}

Place		*SIGame::getRandomPlace(int chance) {
	int				i = 0;
	int				m = this->_placeList.size();
	Place			*place;

	if (!chance)
		return 0;
	m = m * 100 / chance; 
	place = this->_placeList[rand() % m];
	return place;
}

IHuman		*SIGame::getRandomHuman(int chance) {
	int				i = 0;
	int				m = this->_placeList.size();
	IHuman			*human;

	if (!chance)
		return 0;
	m = m * 100 / chance; 
	human = this->_peopleList[rand() % m];
	return human;
}

// MARK: - Cycle logic

void		SIGame::doCycle() {
	unsigned int	i;
	IHuman			*player;
	IHuman			*delH = 0;
	char			c;

	i = 0;
	while (i < this->_peopleList.size()) {
		if (this->_changeStr != "") {
			this->_changeMemory();
			return ;
		}
		//////////////////////
		std::cout << this->_peopleList.size() << "\n";
	//////////////////////////
		player = this->_peopleList[i];
		this->_startCheackHuman(player);
		player->status();
		player->doAction();
		player->age++;
		if (this->_endCheckHuman(player)) {
			delH = this->_peopleList.pop(i);
			delete delH;
		}
		i++;
	}
	this->date.year++;
}

// MARK: - cheack cycle

void		SIGame::_startCheackHuman(IHuman const *human) {
	// human.stats.happy -= 1;
}

bool		SIGame::_endCheckHuman(IHuman const *human) {
	unsigned n = rand();

	if (human->age > n % 100 + 50)
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