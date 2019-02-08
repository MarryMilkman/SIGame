#include "PlayerH.hpp"
#include "SIGame.hpp"

PlayerH::PlayerH() {}

PlayerH::PlayerH(std::string name, std::string gender, bool isPlayer, IDataSIController *ptrSIGame) 
{
	this->name = name;
	this->ptrSIGame = ptrSIGame;
	this->age = 0;
	this->stats = t_stats();
	this->isPlayer = isPlayer;
	this->gender = gender;

	this->botType = "";
	
	this->_initPlaceList(true);
	this->_initHumanList();
}

PlayerH::PlayerH(
	std::string name,
	std::string gender,
	bool isPlayer,
	int age,
	int happy,
	int money,
	int intelect,
	int health,
	int socialStatus,
	IDataSIController *ptrSIGame
) 
{
	this->name = name;
	this->ptrSIGame = ptrSIGame;
	this->age = age;
	this->stats = t_stats();

	this->stats.happy = happy;
	this->stats.money = money;
	this->stats.intelect = intelect;
	this->stats.health = health;
	this->stats.socialStatus = socialStatus;

	this->botType = "";

	this->isPlayer = isPlayer;
	this->gender = gender;
	this->_initPlaceList(false);
	this->_initHumanList();
}


PlayerH::PlayerH(PlayerH const & ref) {
	*this = ref;
}

PlayerH::~PlayerH() {}

PlayerH		& PlayerH::operator=(PlayerH const & ref) {
	this->name = ref.name;
	this->age = ref.age;
	this->stats = ref.stats;
	this->isPlayer = ref.isPlayer;
	this->ptrSIGame = ref.ptrSIGame;
	return (*this);
	return *this;
}

//


void		PlayerH::doAction() {
	char c;

	while (true) {
		std::cout << "What do you want to do?\n"
				<< "1. walk\n"
				<< "2. visit place\n"
				<< "3. check friend list\n";

		while ((c = _getch()) && (c != '1' && c != '2' && c != '3' && c != 27)) ;
		if (c == '1') {
			this->_walk();
			break ;
		}
		if (c == '2')
			if (this->_visitPlace())
				break ;
		if (c == '3')
			if (this->_checkFriendList())
				break ;
		if (c == 27)
			if (this->ptrSIGame->pauseMenu())
				return ;
	}
	this->_status();
	_getch();
}

bool		PlayerH::getAnswer(IHuman const *h_ask, std::string const object) const {
	char	c;
	bool	answ;

	answ = true;
	std::cout << "Player \"" << h_ask->name << "\"" << "want " << object << "\n";
	std::cout << "Answer: (y/n) ";
	c = _getch();
	if (c != 'y')
		answ = false;
	this->_resultAnswer(h_ask, object, answ);
	return answ;
}

//

bool		PlayerH::_visitPlace() {
	int		size = this->familiarPlaceList->size();
	char	c;

	std::cout << "What place do you want to visit?\n";
	int i = -1;
	while (++i < size)
		std::cout << i << ") " << (*this->familiarPlaceList)[i]->placeParam.name << "\n";
	
	while (true) {
		c = _getch();
		if ((c >= '0' && c < '0' + i) || c == 27)
			break ;
	}
	if (c == 27)
		return false;
	(*this->familiarPlaceList)[c - '0']->visitedBy(this);
	return true;
}

bool		PlayerH::_checkFriendList() {
	int					i = -1;
	int					size = this->familiarHumanList->size();
	IHuman				*checkFriend;
	char				c;

	if (size <= 0) {
		std::cout << "Your friend list is empty\n";
		return false;
	}
	else
	{
		std::cout << "Friend list\n";
		while (++i < size) {
			checkFriend = (*this->familiarHumanList)[i];
			std::cout << i << ") " << checkFriend->name << "\n";
		}
		std::cout << "Talk whith:\n";
		while (true) {
			c = _getch();
			if ((c >= '0' && c < '0' + i) || c == 27)
				break ;
		}
		if (c == 27)
			return false;
		std::cout << i << "\n";
		this->_talkTo((*this->familiarHumanList)[c - '0']);
	}
	return true;
}

void		PlayerH::_status() {
	std::cout << "Name:		" << this->name << "\n";
	std::cout << "Age:		" << this->age << "\n";
	std::cout << "Gender:		" << this->gender << "\n";
	std::cout << "Happy:		" << this->stats.happy << "\n";
	std::cout << "Money:		" << this->stats.money << "\n";
	std::cout << "Intelect:	" << this->stats.intelect << "\n";
	std::cout << "Health:		" << this->stats.health << "\n";
	std::cout << "Social:		" << this->stats.socialStatus << "\n";
}