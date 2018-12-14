#ifndef PLAYER_A_HPP
# define PLAYER_A_HPP

# include "lib.h"
# include "IAction.hpp"

class PlayerA : public IAction
{
public:
	PlayerA();
	PlayerA(PlayerA const & ref);
	~PlayerA();

	void		doAction(Human *player) override;

	PlayerA		& operator=(PlayerA const & ref);
private:

	void		_walk(Human *player);
	void		_visitPlace(Human *player);
	void		_status(Human *player);
};

#endif