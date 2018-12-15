#include "SIGame.hpp"

SIGame::SIGame() {
	srand(time(NULL));
	this->date.year = 0;
	this->_initPlaces();
	this->_initPeople();
}

SIGame::SIGame(SIGame const & ref) {
	*this = ref;
}

SIGame		& SIGame::operator=(SIGame const & ref) {
	this->_peopleList = ref._peopleList;
	this->date = ref.date;
	this->_placeList = ref._placeList;
	return (*this);
}

SIGame::~SIGame() {

}

// MARK: - pablic func

void		SIGame::bornHuman() {

}

int			SIGame::countHuman() {
	return (this->_peopleList.size());
}

int			SIGame::countPlace() {
	return (this->_placeList.size());
}

Place		*SIGame::getRandomPlace(int chance) {
	int				i = 0;
	int				m = this->_placeList.size();
	Place			*place;

	if (!chance)
		return 0;
	m = m * 100 / chance; 
	place = this->_placeList[rand() % m];
	return place;
}

Human		*SIGame::getRandomHuman(int chance) {
	int				i = 0;
	int				m = this->_placeList.size();
	Human			*human;

	if (!chance)
		return 0;
	m = m * 100 / chance; 
	human = this->_peopleList[rand() % m];
	return human;
}

// MARK: - Cycle logic

void		SIGame::doCycle() {
	unsigned int	i;
	Human			*delH = 0;

	i = 0;
	while (i < this->_peopleList.size()) {
		this->_startCheackHuman(this->_peopleList[i]);
		this->_peopleList[i]->doAction();
		this->_peopleList[i]->age++;
		if (this->_endCheckHuman(this->_peopleList[i])) {
			delH = this->_peopleList.delite(i);
			delete delH;
		}
		i++;
	}
	this->date.year++;
}

// MARK: - cheack cycle

void		SIGame::_startCheackHuman(Human const *human) {
	// human.stats.happy -= 1;
}

bool		SIGame::_endCheckHuman(Human const *human) {
	unsigned n = rand();

	if (human->age > n % 100 + 50)
		return (true);
	return (false);
}

// MARK: - Init

void		SIGame::_initPeople() {
	Human	*player = new Human("Ivan", "man", true, this, "player");

	this->_peopleList = memlist<Human *>();
	try {
		this->_peopleList.push_front(player);
		this->_peopleList.push_front(new Human("Pika", "man", false, this, ""));
		this->_peopleList.push_front(new Human("Davalka", "woman", false, this, ""));
		this->_peopleList.push_front(new Human("Vorobushek", "man", false, this, ""));
		this->_peopleList.push_front(new Human("Zina", "womam", false, this, ""));
	}
	catch (std::exception & e) {
		std::cout << e.what() << "\n";
		exit(0);
	}
}

void		SIGame::_initPlaces() {
	std::string		places[] = {"./places/kpi.sid", "./places/hospital.sid", "./places/gym.sid",
						"./places/workFootball.sid", "./places/workNASA.sid", "./places/workSilpo.sid", ""};
	int				i;
	int				j;

	this->_placeList = memlist<Place *>();
	i = 0;
	while (places[i] != "") {
		Place *n = new Place(sid::deser_sid(places[i++]));
		this->_placeList.push_front(n);
	}
}