#include "GrayBotA.hpp"
# include "Human.hpp"

GrayBotA::GrayBotA() {}

GrayBotA::GrayBotA(GrayBotA const & ref) {
	*this = ref;
}

GrayBotA::~GrayBotA() {}

GrayBotA		& GrayBotA::operator=(GrayBotA const & ref) {
	(void)(ref);
	return *this;
}

void		GrayBotA::doAction(Human *player) {
	std::cout << player->name << " will be do same action in future...\n";
}

// void		GrayBotA::_walk(Human *player) {

// }

void		GrayBotA::_visitPlace(Human *player) {
	
}