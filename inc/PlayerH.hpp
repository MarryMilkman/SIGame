#ifndef PLAYER_H_HPP
# define PLAYER_H_HPP

# include "lib.h"
# include "IHuman.hpp"

class PlayerH : public IHuman
{
public:
	PlayerH(
		std::string name,
		std::string gender,
		bool isPlayer,
		IDataSIController *ptrSIGame
	);

	PlayerH(
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

	PlayerH(PlayerH const & ref);

	~PlayerH();

	void		doAction() override;
	bool		getAnswer(IHuman const *h_ask, std::string object) const override;

	PlayerH		& operator=(PlayerH const & ref);
private:
	PlayerH();

	bool		_visitPlace();
	bool		_checkFriendList();

	void		_status();
};

#endif