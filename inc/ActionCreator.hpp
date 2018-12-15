#ifndef ACTION_CREATOR_HPP
# define ACTION_CREATOR_HPP

# include "lib.h"

class IAction;

class ActionCreator
{
	ActionCreator();
public:
	ActionCreator(ActionCreator const & ref);
	~ActionCreator();
	
	static IAction	*createAction(std::string model_des);

	ActionCreator	& operator=(ActionCreator const & ref);
};

#endif