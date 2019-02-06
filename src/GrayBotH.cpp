#include "GrayBotH.hpp"

GrayBotH::GrayBotH(std::string name, std::string gender, bool isPlayer, IDataSIController *ptrSIGame) 
{
	this->name = name;
	this->ptrSIGame = ptrSIGame;
	this->age = 0;
	this->stats = t_stats();
	this->isPlayer = isPlayer;
	this->gender = gender;

	this->botType = "GrayBotH";

	// написать конструктор ботов................

	this->_initPlaceList(true);
	this->_initHuamnList();
}

GrayBotH::GrayBotH(
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

	this->isPlayer = isPlayer;
	this->gender = gender;
	this->_initPlaceList(false);
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