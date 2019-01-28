#ifndef I_ACTION_HPP
# define I_ACTION_HPP

# include "lib.h"

class IHuman;

class IAction
{
public:
	virtual ~IAction() {}

	virtual void	doAction(IHuman *thisPlayer) = 0;

// 	// virtual bool	getAnswer(Human *thisPlayer, HumanRelationship & askingPlayer, std::string request);

// protected:
// 	void			_walk(IHuman *thisPlayer);

// 	void			_talkTo(IHuman *thisPlayer);
// 	// void			_hurt(Human *thisPlayer);

// 	bool			_answerFor_talk(IHuman *thisPlayer, HumanRelationship & askingPlayer);
// 	// bool			_answerFor_hurt(Human *thisPlayer, HumanRelationship & askingPlayer);

};

#endif