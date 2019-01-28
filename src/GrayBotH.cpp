#include "GrayBotH.hpp"

GrayBotH::GrayBotH(std::string name, std::string gender, bool isPlayer, IDataSIController *ptrSIGame) 
{
	this->name = name;
	this->ptrSIGame = ptrSIGame;
	this->age = 0;
	this->stats = t_stats();
	this->isPlayer = isPlayer;
	this->gender = gender;
	this->_initPlaceList();
	this->_initHuamnList();
}

GrayBotH::GrayBotH(GrayBotH const & ref) {
	*this = ref;
}

GrayBotH::~GrayBotH() {}

GrayBotH		& GrayBotH::operator=(GrayBotH const & ref) {
	(void)(ref);
	return *this;
}

void		GrayBotH::doAction() {
	this->_walk();
}

bool		GrayBotH::getAnswer(IHuman const *h_ask, std::string const object) const {
	bool answ;

	answ = false;
	if (object == "talk")
		answ = true;
	this->_resultAnswer(h_ask, object, answ);
	return answ;
}

void		GrayBotH::_visitPlace() {
	
}