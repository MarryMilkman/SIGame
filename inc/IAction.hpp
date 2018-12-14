#ifndef I_ACTION_HPP
# define I_ACTION_HPP

# include "lib.h"

class Human;

class IAction
{
public:
	virtual ~IAction() {}

	virtual void	doAction(Human *player) = 0;

};

#endif