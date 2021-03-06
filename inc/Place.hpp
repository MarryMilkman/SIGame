#ifndef PLACE_HPP
# define PLACE_HPP

# include "lib.h"
# include "sid.hpp"
# include "IHuman.hpp"
# include "PlacePermission.hpp"

typedef	struct	s_place
{
	std::string	name;
	int			happy;
	int			intelect;
	int			money;
	int			health;
	int			socialStatus;
}				t_place;

class Place
{
public:
	Place(t_place & place);
	Place(std::vector<t_sid> vSid);
	Place(Place const & ref);
	~Place();

	t_place				placeParam;
	PlacePermission		permission;

	Place			& operator=(Place const & ref);

	bool			visitedBy(IHuman *human);

private:
	Place();
	void			_initPlace(t_sid & sid);
	void			_changeStats(IHuman *human);
	bool			_checkPermission(IHuman const & human) const;
};

#endif

