#include "Human.hpp"
#include "SIGame.hpp"

Human::Human()
{
}

Human::Human(std::string name, std::string gender, bool isPlayer, SIGame *ptrSIGame) :
	isPlayer(isPlayer), name(name), age(0), gender(gender), stats(t_stats()), ptrSIGame(ptrSIGame)
{
}

Human::Human(std::string name, std::string gender, bool isPlayer, int age, t_stats stats, SIGame *ptrSIGame) :
	isPlayer(isPlayer), name(name), age(age), gender(gender), stats(stats), ptrSIGame(ptrSIGame)
{
}


Human::Human(Human const & ref) : gender(ref.gender)
{
	
	*this = ref;
}

Human	& Human::operator=(Human const & ref)
{
	this->name = ref.name;
	this->age = ref.age;
	this->stats = ref.stats;
	this->isPlayer = ref.isPlayer;
	this->ptrSIGame = ref.ptrSIGame;
	return (*this);
}

Human::~Human()
{
}

void			Human::status() const
{
	std::cout << "Name:	" << this->name << "\n";
	std::cout << "Age:	" << this->age << "\n";
	std::cout << "Gender:	" << this->gender << "\n";
	std::cout << "Happy:	" << this->stats.happy << "\n";
	std::cout << "Money:	" << this->stats.money << "\n";
	std::cout << "Intelect:	" << this->stats.intelect << "\n";
	std::cout << "Health:	" << this->stats.health << "\n";
	std::cout << "Social:	" << this->stats.socialStatus << "\n";
}

void			Human::doAction() {
	char	pause;

	this->_visitPlace();
	this->status();
	if (this->isPlayer) {
		std::cin >> pause;
	}
}

void			Human::_visitPlace() {
	if (this->isPlayer) {
		std::cout << "What place do you want to visit?\n";
		int i = 0;
		while (i < ptrSIGame->places.size()) {
			std::cout << i++ << ") " << ptrSIGame->places[i].placeParam.name << std::endl;
		}
		char c = 0;
		while (c < '0' || c > '0' + i)
			std::cin >> c;
		ptrSIGame->places[c - '0'].visitedBy(this);
	}
}

// Cut scene

// void			Human::_prolog_start_cut_scene() const
// {
// 	std::cout << "A child was born who can shake the world.\n"
// 	<< "Or obdolbatsya wheels ... also not bad.\n"
// 	<< "Who he will end up with,"
// 	<< "known only to the peasant in heaven.\n\n";
// }

// void			Human::_prolog_end_cut_scene() const
// {
// 	if (this->_gender == "boy")
// 		std::cout << "And his watch began\n\n";
// 	else
// 		std::cout << "And she's watch began\n\n";
// }

// std::string		Human::_gender_cut_scene() const
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

// std::string		Human::_nema_cut_scene() const
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

