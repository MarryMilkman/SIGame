#ifndef GRAY_BOT_H_HPP
# define GRAY_BOT_H_HPP

# include "lib.h"
# include "IHuman.hpp"

class GrayBotH : public IHuman
{
public:
	GrayBotH(
		std::string name,
		std::string gender,
		bool isPlayer,
		IDataSIController *ptrSIGame
	);
	GrayBotH(GrayBotH const & ref);
	~GrayBotH();

	void		doAction() override;
	bool		getAnswer(IHuman const *h_ask, std::string const object) const override;

	GrayBotH		& operator=(GrayBotH const & ref);
private:

	void		_visitPlace();
};

#endif