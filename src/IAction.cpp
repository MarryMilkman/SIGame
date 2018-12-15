#include "IAction.hpp"
#include "SIGame.hpp"

void		IAction::_walk(Human *player) {
	Place			*place;
	Human			*metHuman;

	std::cout << "It was a good walk.\n";

	player->stats.happy < 10 ? player->stats.happy++ : 0;
	player->stats.health < 7 ? player->stats.health += 2 : 0;

	place = player->ptrSIGame->getRandomPlace(100);
	metHuman = player->ptrSIGame->getRandomHuman(100);

	if (!player->familiarPlaceList.checkExistence(place) && place != 0) {
		std::cout << "You find new place: \"" << place->placeParam.name << "\"\n";
		player->familiarPlaceList.push_front(place);
	}
	
	if (!player->familiarHumanList.checkExistence(metHuman) && metHuman != 0
				&& player != metHuman) {
		std::cout << "You find new person: \"" << metHuman->name << "\"\n";
		player->familiarHumanList.push_front(metHuman);
	}
}