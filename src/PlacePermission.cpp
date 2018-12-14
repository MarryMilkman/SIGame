#include "PlacePermission.hpp"

PlacePermission::PlacePermission() {
	ifHappy = INT_MIN;
	ifHappyLess = INT_MIN;
	ifHappyMore = INT_MAX;

	ifIntelect = INT_MIN;
	ifIntelectLess = INT_MIN;
	ifIntelectMore = INT_MAX;

	ifMoney = INT_MIN;
	ifMoneyLess = INT_MIN;
	ifMoneyMore = INT_MAX;

	ifHealth = INT_MIN;
	ifHealthLess = INT_MIN;
	ifHealthMore = INT_MAX;

	ifSocialStatus = INT_MIN;
	ifSocialStatusLess = INT_MIN;
	ifSocialStatusMore = INT_MAX;
}

PlacePermission::PlacePermission(PlacePermission const & ref) {
	*this = ref;
}

PlacePermission::~PlacePermission() {
}

PlacePermission		& PlacePermission::operator=(PlacePermission const & ref) {
	this->ifHappy = ref.ifHappy;
	this->ifHappyLess = ref.ifHappyLess;
	this->ifHappyMore = ref.ifHappyMore;

	this->ifIntelect = ref.ifIntelect;
	this->ifIntelectLess = ref.ifIntelectLess;
	this->ifIntelectMore = ref.ifIntelectMore;

	this->ifMoney = ref.ifMoney;
	this->ifMoneyLess = ref.ifMoneyLess;
	this->ifMoneyMore = ref.ifMoneyMore;

	this->ifHealth = ref.ifHealth;
	this->ifHealthLess = ref.ifHealthLess;
	this->ifHealthMore = ref.ifHealthMore;

	this->ifSocialStatus = ref.ifSocialStatus;
	this->ifSocialStatusLess = ref.ifSocialStatusLess;
	this->ifSocialStatusMore = ref.ifSocialStatusMore;
	return *this;
}

