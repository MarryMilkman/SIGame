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
	this->_people = ref._people;
	this->date = ref.date;
	this->_placeList = ref._placeList;
	return (*this);
}

SIGame::~SIGame() {

}

// MARK: - pablic func

void		SIGame::bornHuman() {
	// this->people.push_back(Human("Sabaka", 0, false));
}

int			SIGame::countHuman() {
	return (this->_people.size());
}

int			SIGame::countPlace() {
	return (this->_placeList.size());
}

Place		*SIGame::getRandomPlace() {
	int				i = 0;
	int				m = this->_placeList.size();
	Place			*place;

	place = this->_placeList[rand() % m];
	return place;
}


// MARK: - Cycle logic

void		SIGame::doCycle() {
	unsigned int	i;

	i = 0;
	while (i < this->_people.size()) {
		this->_startCheackHuman(this->_people[i]);
		this->_people[i].doAction();
		this->_people[i].age++;
		if (this->_endCheckHuman(this->_people[i])) {
			this->_people.erase(this->_people.begin() + i);
		}
		i++;
	}
	this->date.year++;
}

// MARK: - cheack cycle

void		SIGame::_startCheackHuman(Human & human) {
	// human.stats.happy -= 1;
}

bool		SIGame::_endCheckHuman(Human & human) {
	unsigned n = rand();

	if (human.age > n % 100 + 50)
		return (true);
	return (false);
}

// MARK: - Init

void		SIGame::_initPeople() {
	Human	player("Ivan", "man", true, this, "player");

	this->_people = std::vector<Human>();
	try {
		this->_people.push_back(player);
		this->_people.push_back(Human("Pika", "man", false, this, ""));
		this->_people.push_back(Human("Davalka", "woman", false, this, ""));
		this->_people.push_back(Human("Vorobushek", "man", false, this, ""));
		this->_people.push_back(Human("Zina", "womam", false, this, ""));
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

	this->_placeList = memlist<Place>();
	i = 0;
	while (places[i] != "") {
		Place *n = new Place(sid::deser_sid(places[i++]));
		this->_placeList.push_front(n);
	}
}