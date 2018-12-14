#ifndef PLACE_PERMISSION_HPP
# define PLACE_PERMISSION_HPP

# include "lib.h"

class PlacePermission
{
public:
	PlacePermission();
	PlacePermission(PlacePermission const & ref);
	~PlacePermission();

	int			ifHappy;
	int			ifHappyLess;
	int			ifHappyMore;

	int			ifIntelect;
	int			ifIntelectLess;
	int			ifIntelectMore;

	int			ifMoney;
	int			ifMoneyLess;
	int			ifMoneyMore;

	int			ifHealth;
	int			ifHealthLess;
	int			ifHealthMore;

	int			ifSocialStatus;
	int			ifSocialStatusLess;
	int			ifSocialStatusMore;

	PlacePermission		& operator=(PlacePermission const & ref);
};

#endif