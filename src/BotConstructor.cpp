#include "BotConstructor.hpp"

BotConstructor::BotConstructor() {}

BotConstructor::~BotConstructor() {}



IHuman	*BotConstructor::create(

	std::string	typeBot,
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
	if (typeBot == "GrayBotH")
		return (new GrayBotH(name, gender, isPlayer, age, happy, money, intelect, health, socialStatus, ptrSIGame));
	else {
		std::cout << typeBot << " - !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1\n";
		return (new PlayerH(name, gender, isPlayer, age, happy, money, intelect, health, socialStatus, ptrSIGame));
	}
}

IHuman	*BotConstructor::create(
	std::string	typeBot,
	std::string name,
	std::string gender,
	bool isPlayer,
	IDataSIController *ptrSIGame
	) 
{
	if (typeBot == "GrayBotH")
		return (new GrayBotH(name, gender, isPlayer, ptrSIGame));
	else
		return (new PlayerH(name, gender, isPlayer, ptrSIGame));
}