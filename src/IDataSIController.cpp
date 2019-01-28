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
	int				m = this->_placeList.size();
	Place			*place;

	if (!chance)
		return 0;
	m = m * 100 / chance; 
	place = this->_placeList[rand() % m];
	return place;
}

IHuman		*IDataSIController::getRandomHuman(int chance) {
	int				i = 0;
	int				m = this->_placeList.size();
	IHuman			*human;

	if (!chance)
		return 0;
	m = m * 100 / chance; 
	human = this->_peopleList[rand() % m];
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
	std::string		str;
	t_save			save;

	while (nbrColums-- > 0) {
		str = *nameFild++;
		if (str == "save_id")
			save.save_id = atoi(*strText++);
		else
			save.name = *strText++;
	}
	_listSave->push_back(save);
	return 0;
}

void		IDataSIController::_initSaveList() {

	sqlite3 	*db		= 0;
	char 		*err	= 0;
	const char*	sql		= "SELECT save_id, name_save FROM Save_List;";


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




// MARK: - load / save / remove / new / nullify

	// load
void		IDataSIController::_load(int save_id) {
	std::cout << "load...\n";
}

	// save
void		IDataSIController::_save(std::string saveName) {
	sqlite3 		*db = 0;
	char 			*err = 0;
	std::string		sql = "INSERT INTO Save_List (name_save) VALUES ('";

	sql += saveName + "');";
	if (sqlite3_open("./db/saveList.dblite", &db))
		std::cout << "something wrong....\n";
	else if (sqlite3_exec(db, sql.c_str(), 0, 0, &err)) {
		fprintf(stderr, "Ошибка SQL: %sn", err);
		sqlite3_free(err);
	}
	this->_createNewSave(saveName);
	sqlite3_close(db);
}

void		IDataSIController::_createNewSave(std::string	saveName) {
	sqlite3		*db = 0;
	char		*err = 0;
	std::string	path;

	std::string	fild;
	int			size;
	int			i;

		// init table in DB
	std::string	sql = "CREATE TABLE IF NOT EXISTS Check;\
						CREATE TABLE IF NOT EXISTS PeopleTable;\
						CREATE TABLE IF NOT EXISTS PlaceTable;\
						CREATE TABLE IF NOT EXISTS LinkPeople;\
						CREATE TABLE IF NOT EXISTS LinkPlace;\n";
		
		// for PeopleTable
	sql = sql + "ALTER TABLE PeopleTable ADD name CHAR(30);\
				ALTER TABLE PeopleTable ADD isPlayer INT;\
				ALTER TABLE PeopleTable ADD age INT;\
				ALTER TABLE PeopleTable ADD gender CHAR(30);\
				ALTER TABLE PeopleTable ADD happy INT;\
				ALTER TABLE PeopleTable ADD money INT;\
				ALTER TABLE PeopleTable ADD intelect INT;\
				ALTER TABLE PeopleTable ADD health INT;\
				ALTER TABLE PeopleTable ADD socialStatus INT;\n";
		// for PlaceTable
	sql = sql + "ALTER TABLE PlaceTable ADD name CHAR(30);\
				ALTER TABLE PlaceTable ADD happy INT;\
				ALTER TABLE PlaceTable ADD money INT;\
				ALTER TABLE PlaceTable ADD intelect INT;\
				ALTER TABLE PlaceTable ADD health INT;\
				ALTER TABLE PlaceTable ADD socialStatus INT;\
				\
				ALTER TABLE PlaceTable ADD ifHappy INT;\
				ALTER TABLE PlaceTable ADD ifHappyLess INT;\
				ALTER TABLE PlaceTable ADD ifHappyMore INT;\
				\
				ALTER TABLE PlaceTable ADD ifIntelect INT;\
				ALTER TABLE PlaceTable ADD ifIntelectLess INT;\
				ALTER TABLE PlaceTable ADD ifIntelectMore INT;\
				\
				ALTER TABLE PlaceTable ADD ifMoney INT;\
				ALTER TABLE PlaceTable ADD ifMoneyLess INT;\
				ALTER TABLE PlaceTable ADD ifMoneyMore INT;\
				\
				ALTER TABLE PlaceTable ADD ifHealth INT;\
				ALTER TABLE PlaceTable ADD ifHealthLess INT;\
				ALTER TABLE PlaceTable ADD ifHealthMore INT;\
				\
				ALTER TABLE PlaceTable ADD ifSocialStatus INT;\
				ALTER TABLE PlaceTable ADD ifSocialStatusLess INT;\
				ALTER TABLE PlaceTable ADD ifSocialStatusMore INT;\n";
		// for LinkPeople
	sql = sql + "ALTER TABLE LinkPeople ADD namePlayer CHAR(30);\n";
	size = this->_peopleList.size();
	i = -1;
	while (++i < size) {
		fild = "ALTER TABLE LinkPeople ADD " + this->_peopleList[i]->name + " CHAR(30);\n";
		sql = sql + fild;
	}
		// for LinkPlace
	sql = sql + "ALTER TABLE LinkPlace ADD namePlayer CHAR(30);\n";
	size = this->_placeList.size();
	i = -1;
	while (++i < size) {
		fild = "ALTER TABLE LinkPlace ADD " + this->_placeList[i]->placeParam.name + " CHAR(30);\n";
		sql = sql + fild;
	}
	// SQL request ready

	path = "./db/save_dir/" + saveName + ".dblite";
	if (sqlite3_open(path.c_str(), &db))
		std::cout << "something wrong....\n";

}

	// remove
static int	scb_getNameAndRemove(void *data, int nbrColums, char **strText, char **nameFild) {
	*(reinterpret_cast<std::string *>(data)) = *strText;

	return 0;
}

void		IDataSIController::_remove(int	save_id) {
	std::string		*strName = new std::string();
	sqlite3 		*db = 0;
	char 			*err = 0;
	std::string		sql = "SELECT name_save FROM Save_List WHERE save_id = ";

	*strName = "";

	sql = sql + std::to_string(save_id) + ";";
	if (sqlite3_open("./db/saveList.dblite", &db))
		std::cout << "something wrong....\n";
	else if (sqlite3_exec(db, sql.c_str(), &scb_getNameAndRemove, strName, &err)) {
		fprintf(stderr, "Error SQL: %s\n", err);
		sqlite3_free(err);
	}
	sqlite3_close(db);
	std::cout << "U want delete '" << *strName << "' save\n";
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
	// 					save_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\
	// 					name_save CHAR(40)\
	// 				);\
	// 				INSERT INTO Save_List (name_save) VALUES ('save1');\
	// 				INSERT INTO Save_List (name_save) VALUES ('save2');
