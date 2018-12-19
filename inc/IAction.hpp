#ifndef I_ACTION_HPP
# define I_ACTION_HPP

# include "lib.h"
# include "HumanRelationship.hpp"

class Human;

class IAction
{
public:
	virtual ~IAction() {}

	virtual void	doAction(Human *thisPlayer) = 0;

	// virtual bool	getAnswer(Human *thisPlayer, HumanRelationship & askingPlayer, std::string request);

protected:
	void			_walk(Human *thisPlayer);

	void			_talkTo(Human *thisPlayer);
	// void			_hurt(Human *thisPlayer);

	bool			_answerFor_talk(Human *thisPlayer, HumanRelationship & askingPlayer);
	// bool			_answerFor_hurt(Human *thisPlayer, HumanRelationship & askingPlayer);

};

#endif