#ifndef GRAY_BOT_A_HPP
# define GRAY_BOT_A_HPP

# include "lib.h"
# include "IAction.hpp"

class GrayBotA : public IAction
{
public:
	GrayBotA();
	GrayBotA(GrayBotA const & ref);
	~GrayBotA();

	void		doAction(Human *player) override;

	GrayBotA		& operator=(GrayBotA const & ref);
private:

	// void		_walk(Human *player);
	void		_visitPlace(Human *player);
};

#endif