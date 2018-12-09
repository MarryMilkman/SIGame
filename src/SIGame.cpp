#include "SIGame.hpp"

SIGame::SIGame() {
	srand(time(NULL));
	this->date.year = 0;
	this->_initPeople();
	this->_initPlaces();
}

SIGame::SIGame(SIGame const & ref) {
	*this = ref;
}

SIGame		& SIGame::operator=(SIGame const & ref) {
	this->people = ref.people;
	this->places = ref.places;
	this->date = ref.date;
	return (*this);
}

SIGame::~SIGame() {

}

void		SIGame::bornHuman() {
	// this->people.push_back(Human("Sabaka", 0, false));
}

// MARK: - Init

void		SIGame::_initPeople() {
	Human	player("Ivan", "man", true, this);

	this->people = std::vector<Human>();
	try {
		this->people.push_back(player);
		this->people.push_back(Human("Pika", "man", false, this));
		this->people.push_back(Human("Davalka", "woman", false, this));
		this->people.push_back(Human("Vorobushek", "man", false, this));
		this->people.push_back(Human("Zina", "womam", false, this));
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

	i = 0;
	while (places[i] != "")
		this->places.push_back(Place(sid::deser_sid(places[i++])));
}

// MARK: - Cycle logic

void		SIGame::doCycle() {
	unsigned int	i;

	i = 0;
	while (i < this->people.size()) {
		this->_startCheackHuman(this->people[i]);
		this->people[i].doAction();
		this->people[i].age++;
		if (this->_endCheckHuman(this->people[i])) {
			this->people.erase(this->people.begin() + i);
		}
		i++;
	}
	this->date.year++;
}

// MARK: - cheack cycle

void		SIGame::_startCheackHuman(Human & human) {
	human.stats.happy -= 1;
}

bool		SIGame::_endCheckHuman(Human & human) {
	unsigned n = rand();

	if (human.age > n % 100 + 50)
		return (true);
	return (false);
}