#include "PlayerA.hpp"
#include "Place.hpp"
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
	std::cout << "What do you want to do?\n"
				<< "1)walk\n"
				<< "2)go to...\n";
	char c = 0;
	while (c != '1' && c != '2') {
		std::cin.clear();
		std::cin >> c;
	}
	c == '1' ? this->_walk(player) : this->_visitPlace(player);

	this->_status(player);

	std::cin.clear();
	std::cin.ignore();
	c = getchar();
}

void		PlayerA::_walk(Human *player) {
	Place			*place;

	std::cout << "It was a good walk.\n";
	player->stats.happy < 10 ? player->stats.happy++ : 0;
	player->stats.health < 7 ? player->stats.happy += 2 : 0;
	place = player->ptrSIGame->getRandomPlace();
	if (player->placeList.checkExistence(place))
		return ;
	std::cout << "You find new place: \"" << place->placeParam.name << "\"\n";
	player->placeList.push_front(place);
}

void		PlayerA::_visitPlace(Human *player) {
	int		size = player->placeList.size();

	std::cout << "What place do you want to visit?\n";
	int i = 0;
	while (i < size)
		std::cout << i++ << ") " << player->placeList[i]->placeParam.name << "\n";
	char c = 0;
	std::cout << "I want go to place #: ";
	while (c < '0' || c > '0' + i)
		std::cin >> c;
	player->placeList[c - '0']->visitedBy(player);
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