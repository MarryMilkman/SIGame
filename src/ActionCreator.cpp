#include "ActionCreator.hpp"
#include "GrayBotA.hpp"
#include "PlayerA.hpp"

ActionCreator::ActionCreator() {}
ActionCreator::ActionCreator(ActionCreator const & ref) {
	*this = ref;
}

ActionCreator::~ActionCreator() {}

ActionCreator		& ActionCreator::operator=(ActionCreator const & ref) {
	(void)(ref);
	return *this;
}

IAction				*ActionCreator::createAction(std::string model_des) {
	if (model_des == "player")
		return new PlayerA();
	else
		return new GrayBotA();
}