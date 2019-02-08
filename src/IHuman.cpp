#include "IHuman.hpp"
#include "SIGame.hpp"
#include "Place.hpp"

IHuman::~IHuman() {
	delete this->familiarPlaceList;
	delete this->familiarHumanList;
	this->familiarPlaceList = 0;
	this->familiarHumanList = 0;
	this->ptrSIGame = 0;
}

IHuman	& IHuman::operator=(IHuman const & ref) {
	this->name = ref.name;
	this->age = ref.age;
	this->stats = ref.stats;
	this->isPlayer = ref.isPlayer;
	this->ptrSIGame = ref.ptrSIGame;
	this->familiarPlaceList = ref.familiarPlaceList;
	return (*this);
}

void			IHuman::status() const {
	std::cout << "Name:		" << this->name << "\n";
	std::cout << "Age:		" << this->age << "\n";
	std::cout << "Gender:		" << this->gender << "\n";
	std::cout << "Happy:		" << this->stats.happy << "\n";
	std::cout << "Money:		" << this->stats.money << "\n";
	std::cout << "Intelect:	" << this->stats.intelect << "\n";
	std::cout << "Health:		" << this->stats.health << "\n";
	std::cout << "Social:		" << this->stats.socialStatus << "\n";
}

void		IHuman::_walk() {
	Place				*place = 0;
	IHuman				*metHuman = 0;

	std::cout << "It was a good walk.\n";

	this->stats.happy < 10 ? this->stats.happy++ : 0;
	this->stats.health < 7 ? this->stats.health += 2 : 0;

	place = this->ptrSIGame->getRandomPlace(100);
	metHuman = this->ptrSIGame->getRandomHuman(100);

	if (!this->familiarPlaceList->checkExistence(place) && place != 0) {
		std::cout << "You find new place: \"" << place->placeParam.name << "\"\n";
		this->familiarPlaceList->push_front(place);
	}

	if (!this->familiarHumanList->checkExistence(metHuman) && metHuman != 0
				&& this != metHuman) {
		std::cout << "You find new person: \"" << metHuman->name << "\"\n";
		this->familiarHumanList->push_front(metHuman);
		metHuman->familiarHumanList->push_front(this);
	}
}

void		IHuman::_talkTo(IHuman *h_des) {
	if (!h_des->getAnswer(this, "talk"))
		return ;
	this->ptrSIGame->talk(this, h_des);
	std::cout << "Nice speak\n";
}

// MARK: - init

void			IHuman::_initPlaceList(bool isNew) {
	int				i = 0;
	Place			*place;

	this->familiarPlaceList = new memlist<Place *>();
	*this->familiarPlaceList = memlist<Place *>();
	if (isNew)
		while (i < 3) {
			place = this->ptrSIGame->getRandomPlace(100);
			if (this->familiarPlaceList->checkExistence(place))
				continue;
			this->familiarPlaceList->push_front(place);
			i++;
		}
}

void			IHuman::_initHumanList() {
	this->familiarHumanList = new memlist<IHuman *>;
	*this->familiarHumanList = memlist<IHuman *>();
}

// helpfull function

void		IHuman::_resultAnswer(IHuman const *h_ask, std::string const object, bool answ) const {
	std::string	str;

	str = "\" failure in ";
	if (answ) 
		str = "\" access in ";
	std::cout << "Player \"" << this->name << str 
			<< object << " with \"" << h_ask->name << "\"\n";
}



// Cut scene

// void			IHuman::_prolog_start_cut_scene() const
// {
// 	std::cout << "A child was born who can shake the world.\n"
// 	<< "Or obdolbatsya wheels ... also not bad.\n"
// 	<< "Who he will end up with,"
// 	<< "known only to the peasant in heaven.\n\n";
// }

// void			IHuman::_prolog_end_cut_scene() const
// {
// 	if (this->_gender == "boy")
// 		std::cout << "And his watch began\n\n";
// 	else
// 		std::cout << "And she's watch began\n\n";
// }

// std::string		IHuman::_gender_cut_scene() const
// {
// 	std::string		gender;
// 	char			c;

// 	std::cout << "Midwife: What a sweet pendulous\n";
// 	c = 0;
// 	std::cout << ">>Agree? (y/n): ";
// 	while (c != 'y' && c != 'n')
// 		std::cin >> c;
// 	c == 'y' ? gender = "boy" : gender = "girl";
// 	if (c == 'n')
// 		std::cout << "Midwife: But no, wait, she fell off ...\n";
// 	std::cout << "Midwife: Congratulations, you have a " << gender << std::endl;
// 	return (gender);
// }

// std::string		IHuman::_nema_cut_scene() const
// {
// 	std::string		name;

// 	std::cout << "Midwife: And what's the name of this baby?\n";
// 	while (1)
// 	{
// 		name.clear();
// 		getline(std::cin, name);
// 		if (name != "")
// 			break;
// 		std::cout << ">>Enter name: ";
// 	}
// 	std::cout << "Misa: His name is " << name << std::endl;
// 	return (name);
// }

// Getter / Setter




// operator

