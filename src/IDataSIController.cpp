#include "IDataSIController.hpp"

#include "PlayerH.hpp"
#include "GrayBotH.hpp"

IDataSIController::IDataSIController () {
	srand(time(NULL));
	this->_initSaveList();
	this->_initPlaces();
}

IDataSIController::~IDataSIController() {

}

// MARK: - Public func

int			IDataSIController::countHuman() {
	return (this->_peopleList.size());
}

int			IDataSIController::countPlace() {
	return (this->_placeList.size());
}

void		IDataSIController::talk(IHuman *h1, IHuman *h2) {
	if (h1->stats.happy < h2->stats.happy) {
		h1->stats.happy += 2;
		h2->stats.happy--;
	}
	else if (h2->stats.happy < h1->stats.happy) {
		h2->stats.happy += 2;
		h1->stats.happy--;
	}
	if (h2->stats.happy < 0 || h1->stats.happy < 0)
		return;
	h1->stats.intelect < h2->stats.intelect ? h1->stats.intelect++ : 0;
	h2->stats.intelect < h1->stats.intelect ? h2->stats.intelect++ : 0;
	h1->stats.socialStatus < h2->stats.socialStatus ? h1->stats.socialStatus++ : 0;
	h2->stats.socialStatus < h1->stats.socialStatus ? h2->stats.socialStatus++ : 0;
}

Place		*IDataSIController::getRandomPlace(int chance) {
	int				i = 0;
	int				m;
	int				size = this->_placeList.size();
	Place			*place;

	if (!chance)
		return 0;
	m = size * 100 / chance;
	m = rand() % m;
	if (m >= size)
		return 0;
	place = 0;
	try {
		place = this->_placeList[m];
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	return place;
}

IHuman		*IDataSIController::getRandomHuman(int chance) {
	int				i = 0;
	int				m;
	int				size = this->_peopleList.size();
	IHuman			*human;

	if (!chance)
		return 0;
	m = size * 100 / chance;
	m = rand() % m;
	if (m >= size)
		return 0;
	human = 0;
	try {
		human = this->_peopleList[m];
	} catch (std::exception & e) {}
	std::cout << human->name << "    huuuuuuuuuuuuuy" << std::endl;
	return human;
}




// MARK: - init

void		IDataSIController::_initPeople() {
	IHuman	*player = new PlayerH("Ivan", "man", true, this);

	this->_peopleList = memlist<IHuman *>();
	try {
		this->_peopleList.push_front(player);
		this->_peopleList.push_front(new GrayBotH("Pika", "man", false, this));
		this->_peopleList.push_front(new GrayBotH("dima", "woman", false, this));
		this->_peopleList.push_front(new GrayBotH("Vorobushek", "man", false, this));
		this->_peopleList.push_front(new GrayBotH("Zina", "womam", false, this));
	}	catch (std::exception & e) {
		std::cout << e.what() << "\n";
		exit(0);
	}
}

void		IDataSIController::_initPlaces() {
	std::string		places[] = {"./places/kpi.sid", "./places/hospital.sid", "./places/gym.sid",
						"./places/workFootball.sid", "./places/workNASA.sid", "./places/workSilpo.sid",
						"./places/library.sid", "./places/nauch_vistavka.sid", "./places/stadion.sid", 
						"./places/playGraund.sid", ""};
	int				i;
	int				j;

	this->_placeList = memlist<Place *>();
	i = 0;
	while (places[i] != "") {
		Place *n = new Place(sid::deser_sid(places[i++]));
		this->_placeList.push_front(n);
	}
}


	// init save list
static int	scb_initSaveList(void *data, int nbrColums, char **strText, char **nameFild) {
	std::vector<t_save>	*_listSave = reinterpret_cast<std::vector<t_save> *>(data);
	t_save			save;
	int				i;

	i = -1;
	while (++i < nbrColums) {
		save.save_id = _listSave->size();
		save.name = *strText++;
	}
	_listSave->push_back(save);
	return 0;
}


void		IDataSIController::_initSaveList() {

	sqlite3 	*db		= 0;
	char 		*err	= 0;
	const char*	sql		= "CREATE TABLE IF NOT EXISTS Save_List\
			(\
			name_save CHAR(30)\
			);\
			SELECT name_save FROM Save_List;";


	this->_listSave = std::vector<t_save>();
	if( sqlite3_open("./db/saveList.dblite", &db) )
		std::cout << "something wrong....\n";
	else if (sqlite3_exec(db, sql, &scb_initSaveList, &(this->_listSave), &err))
	{
		fprintf(stderr, "Ошибка SQL: %sn", err);
		sqlite3_free(err);
	}
	sqlite3_close(db);
}




// MARK: - remove / new / nullify

	// remove
// static int	scb_getNameAndRemove(void *data, int nbrColums, char **strText, char **nameFild) {
// 	std::cout << "???????????\n";
// 	while (*nameFild) {
// 		std::cout << *nameFild << "- name column\n";

// 		nameFild++;
// 	}
// 	while (nbrColums-- > 0)
// 		std::cout << *strText++ << "\n";
// 	return 0;
// }

void		IDataSIController::_remove(std::string saveName) {
	std::string		path;
	sqlite3 		*db = 0;
	char 			*err = 0;
	// std::string		sql = "SELECT * FROM Save_List;\n";

	std::string		sql = "DELETE FROM Save_List WHERE name_save = \"" + saveName + "\";\n";

	std::cout << sql;
	if (sqlite3_open("./db/saveList.dblite", &db))
		std::cout << "something wrong....\n";
	else if (sqlite3_exec(db, sql.c_str(), 0, 0, &err)) {
		fprintf(stderr, "Error SQL: %s\n", err);
		sqlite3_free(err);
	}
	sqlite3_close(db);
	path = "./db/save_dir/" + saveName + ".dblite";
	if (remove(path.c_str()))
		perror( "Error deleting file" );
	// leaks may be
	this->_initSaveList();
}

	//new
void		IDataSIController::_newGame() {
	this->date.year = 0;
	this->_nullifyGameData();
	this->_initPeople();
}

	// nullify
void		IDataSIController::_nullifyGameData() {
	int 		size = this->_peopleList.size();
	IHuman		*human;

	this->date.year = 0;
	while (size-- > 0) {
		human = this->_peopleList.pop(size);
		delete human;
	}
}


	// DROP TABLE Save_List;\
	// 				CREATE TABLE IF NOT EXISTS Save_List(\
	// 					name_save CHAR(40)\
	// 				);\
	// 				INSERT INTO Save_List (name_save) VALUES ('save1');\
	// 				INSERT INTO Save_List (name_save) VALUES ('save2');
