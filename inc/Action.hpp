#ifndef ACTION_HPP
# define ACTION_HPP

# include "lib.h"

class Action
{
public:
	~Action();

	void	doAction();

protected:
	Action();

	void	_walk(std::string str);
	void	_goToPlace(std::string str);
	void	_speakWith(std::string str);

	int		_choiseCommand();

	void	_displayAllCommand();

	static int	_countCommand;
};

#endif