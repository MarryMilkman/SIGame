#include "PlayerA.hpp"
#include "SIGame.hpp"

PlayerA::PlayerA() {}

PlayerA::PlayerA(PlayerA const & ref) {
	*this = ref;
}

PlayerA::~PlayerA() {}

PlayerA		& PlayerA::operator=(PlayerA const & ref) {
	(void)(ref);
	return *this;
}

void		PlayerA::doAction(Human *player) {
	char c;

	while (true) {
		std::cout << "What do you want to do?\n"
				<< "1. walk\n"
				<< "2. visit place\n"
				<< "3. check friend list\n";
		c = 0;
		while (c != '1' && c != '2' && c != '3') {
			std::cin.clear();
			std::cin >> c;
		}
		if (c == '1') {
			this->_walk(player);
			break ;
		}
		if (c == '2')
			if (this->_visitPlace(player))
				break ;
		if (c == '3')
			this->_checkFriendList(player);
	}
	this->_status(player);
	std::cin.clear();
	std::cin.ignore();
	getchar();
}

bool		PlayerA::_visitPlace(Human *player) {
	int		size = player->familiarPlaceList.size();

	std::cout << "What place do you want to visit?\n";
	int i = -1;
	while (++i < size)
		std::cout << i << ") " << player->familiarPlaceList[i]->placeParam.name << "\n";
	std::cout << "-------------\nb) back\n";
	char c = 0;
	std::cout << "I want go to place #: ";
	while ((c < '0' || c >= '0' + i) && c != 'b')
		std::cin >> c;
	if (c == 'b')
		return false;
	player->familiarPlaceList[c - '0']->visitedBy(player);
	return true;
}

void		PlayerA::_checkFriendList(Human *player) {
	int					i = -1;
	int					size = player->familiarHumanList.size();
	HumanRelationship	checkFriend;

	if (size <= 0)
		std::cout << "Your friend list is empty\n";
	else
		std::cout << "Friend list\n";
	while (++i < size) {
		checkFriend = player->familiarHumanList[i];
		std::cout << i << ") " << checkFriend.human->name << ", "
					<< checkFriend.relationship << "\n";
	}
	std::cin.clear();
	std::cin.ignore();
	getchar();
}

void		PlayerA::_status(Human *player) {
	std::cout << "Name:		" << player->name << "\n";
	std::cout << "Age:		" << player->age << "\n";
	std::cout << "Gender:		" << player->gender << "\n";
	std::cout << "Happy:		" << player->stats.happy << "\n";
	std::cout << "Money:		" << player->stats.money << "\n";
	std::cout << "Intelect:	" << player->stats.intelect << "\n";
	std::cout << "Health:		" << player->stats.health << "\n";
	std::cout << "Social:		" << player->stats.socialStatus << "\n";
}