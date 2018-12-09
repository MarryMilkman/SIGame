#include "Place.hpp"

Place::Place() {
}

Place::Place(t_place & place) {
	this->placeParam = place;
}

Place::Place(std::vector<t_sid> vSid) {
	int		i;

	i = 0;
	while (i < vSid.size()) {
		this->_initPlace(vSid[i++]);
	}
}

Place::Place(Place const & ref) {
	*this = ref;
}

Place		& Place::operator=(Place const & ref) {
	this->placeParam = ref.placeParam;
	return *this;
}

Place::~Place() {
}

void		Place::visitedBy(Human *human) {
	if (this->_checkPermission(*human)) 
		this->_changeStats(human);
}

void		Place::_initPlace(t_sid & sid) {
	if (sid.name == "happy" && sid.type == "int")
			this->placeParam.happy = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "intelect" && sid.type == "int")
		this->placeParam.intelect = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "money" && sid.type == "int")
		this->placeParam.money = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "health" && sid.type == "int")
		this->placeParam.health = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "socialStatus" && sid.type == "int")
		this->placeParam.socialStatus = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "name" && sid.type == "string")
		this->placeParam.name = *(reinterpret_cast<std::string *>(sid.value));


	
	if (sid.type == "string")
		delete reinterpret_cast<std::string *>(sid.value);
	else
		delete reinterpret_cast<int *>(sid.value);
}

void			Place::_changeStats(Human *human) {
	t_stats	& stats = human->stats;
	t_place & sPlace = this->placeParam;

	stats.happy += sPlace.happy;
	stats.money += sPlace.money;
	stats.intelect += sPlace.intelect;
	stats.health += sPlace.health;
	stats.socialStatus += sPlace.socialStatus;
}

bool			Place::_checkPermission(Human const & human) const {
	return true;
}