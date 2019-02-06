#ifndef BOT_CONSTRUCTOR_HPP
# define BOT_CONSTRUCTOR_HPP

#include "lib.h"

#include "PlayerH.hpp"
#include "GrayBotH.hpp"

class BotConstructor
{
	BotConstructor();
public:
	~BotConstructor();

	static IHuman	*create(
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
	);

	static IHuman	*create(
		std::string	typeBot,
		std::string name,
		std::string gender,
		bool isPlayer,
		IDataSIController *ptrSIGame
	) ;
};

#endif