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
	this->permission = ref.permission;
	return *this;
}

Place::~Place() {
}

bool	Place::visitedBy(Human *human) {
	if (this->_checkPermission(*human)) {
		this->_changeStats(human);
		return true;
	}
	std::cout << human->name << " was not allowed into the " <<
			this->placeParam.name << "\n";
	return false;
}

// MARK: = init place

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

	if (sid.name == "ifHappy" && sid.type == "int")
		this->permission.ifHappy = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifHappyLess" && sid.type == "int")
		this->permission.ifHappyLess = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifHappyMore" && sid.type == "int")
		this->permission.ifHappyMore = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifIntelect" && sid.type == "int")
		this->permission.ifIntelect = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifIntelectLess" && sid.type == "int")
		this->permission.ifIntelectLess = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifIntelectMore" && sid.type == "int")
		this->permission.ifIntelectMore = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifMoney" && sid.type == "int")
		this->permission.ifMoney = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifMoneyLess" && sid.type == "int")
		this->permission.ifMoneyLess = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifMoneyMore" && sid.type == "int")
		this->permission.ifMoneyMore = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifHealth" && sid.type == "int")
		this->permission.ifHealth = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifHealthLess" && sid.type == "int")
		this->permission.ifHealthLess = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifHealthMore" && sid.type == "int")
		this->permission.ifHealthMore = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifSocialStatus" && sid.type == "int")
		this->permission.ifSocialStatus = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifSocialStatusLess" && sid.type == "int")
		this->permission.ifSocialStatusLess = *(reinterpret_cast<int *>(sid.value));
	if (sid.name == "ifSocialStatusMore" && sid.type == "int")
		this->permission.ifSocialStatusMore = *(reinterpret_cast<int *>(sid.value));

	if (sid.type == "string")
		delete reinterpret_cast<std::string *>(sid.value);
	else
		delete reinterpret_cast<int *>(sid.value);
}

// end init

void			Place::_changeStats(Human *human) {
	t_stats	& stats = human->stats;
	t_place & sPlace = this->placeParam;

	stats.happy < this->permission.ifHappyMore ? stats.happy += sPlace.happy : 0;
	stats.money += sPlace.money;
	stats.intelect < this->permission.ifIntelectMore ? stats.intelect += sPlace.intelect : 0;
	stats.health < this->permission.ifHealthMore ? stats.health += sPlace.health : 0;
	stats.socialStatus < this->permission.ifSocialStatusMore ? stats.socialStatus += sPlace.socialStatus : 0;
}

bool			Place::_checkPermission(Human const & human) const {
	t_stats const			& stats = human.stats;
	PlacePermission const	& sPlace = this->permission;

	if (stats.happy < sPlace.ifHappyLess || (stats.happy != sPlace.ifHappy && sPlace.ifHappy != INT_MIN)
		|| stats.money < sPlace.ifMoneyLess || stats.money > sPlace.ifMoneyMore || (stats.money != sPlace.ifMoney && sPlace.ifMoney != INT_MIN)
		|| stats.intelect < sPlace.ifIntelectLess || (stats.intelect != sPlace.ifIntelect && sPlace.ifIntelect != INT_MIN)
		|| stats.health < sPlace.ifHealthLess || (stats.health != sPlace.ifHealth && sPlace.ifHealth != INT_MIN)
		|| stats.socialStatus < sPlace.ifSocialStatusLess || (stats.health != sPlace.ifSocialStatus && sPlace.ifSocialStatus != INT_MIN))
	{
		return false;
	}
	return true;
}