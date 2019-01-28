// #include "IAction.hpp"
// #include "SIGame.hpp"

// void		IAction::_walk(IHuman *player) {
// 	Place				*place;
// 	HumanRelationship	metHumRel;
// 	IHuman				*metHuman;

// 	std::cout << "It was a good walk.\n";

// 	player->stats.happy < 10 ? player->stats.happy++ : 0;
// 	player->stats.health < 7 ? player->stats.health += 2 : 0;

// 	place = player->ptrSIGame->getRandomPlace(100);
// 	metHuman = player->ptrSIGame->getRandomHuman(100);

// 	metHumRel.human = metHuman;
// 	metHumRel.relationship = 0;

// 	if (!player->familiarPlaceList.checkExistence(place) && place != 0) {
// 		std::cout << "You find new place: \"" << place->placeParam.name << "\"\n";
// 		player->familiarPlaceList.push_front(place);
// 	}

// 	if (!player->familiarHumanList.checkExistence(metHumRel) && metHumRel.human != 0
// 				&& player != metHumRel.human) {
// 		std::cout << "You find new person: \"" << metHuman->name << "\"\n";
// 		player->familiarHumanList.push_front(metHumRel);
// 	}
// }

// void		IAction::_talkTo(IHuman *thisPlayer) {

// }

// // void		IAction::_hurt(Human *thisPlayer) {

// // }

// bool		IAction::_answerFor_talk(IHuman *thisPlayer, HumanRelationship & askingPlayer) {
// 	t_stats		askPl_stats = askingPlayer.human->stats;
// 	t_stats		thisPl_stats = thisPlayer->stats;

// 	if (askPl_stats.happy > 0)
// 		return (true);
// 	return false;
// }

// // bool		IAction::_answerFor_hurt(Human *thisPlayer, HumanRelationship & askingPlayer) {
// // 	if (askingPlayer.relationship > 0)
// // 		return (true);
// // 	return false;
// // }