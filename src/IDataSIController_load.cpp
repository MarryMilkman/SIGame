#include "IDataSIController.hpp"

#include "BotConstructor.hpp"

typedef struct			s_help
{
	memlist<IHuman *>	*peopleList;
	memlist<Place *>	*placeList;
}						t_help;

	// load
static int	scb_loadPeopleTable(void *data, int nbrColums, char **strText, char **nameFild) {
	memlist<IHuman *>	*peopleList = reinterpret_cast<memlist<IHuman *> *>(data);
	std::string			s_fild;
	std::string 		name;
	std::string 		gender;
	bool 				isPlayer;
	int 				age;
	int 				happy;
	int					money;
	int 				intelect;
	int 				health;
	int 				socialStatus;
	std::string			typeBot;

	while (nbrColums-- > 0) {
		s_fild = *nameFild++;
		if (s_fild == "name")
			name = std::string(*strText);
		if (s_fild == "isPlayer")
			isPlayer = std::string(*strText) == "y" ? true : false;
		if (s_fild == "age")
			age = std::stoi(std::string(*strText));
		if (s_fild == "gender")
			gender = std::string(*strText);
		if (s_fild == "happy")
			happy = std::stoi(std::string(*strText));
		if (s_fild == "money")
			money = std::stoi(std::string(*strText));
		if (s_fild == "intelect")
			intelect = std::stoi(std::string(*strText));
		if (s_fild == "health")
			health = std::stoi(std::string(*strText));
		if (s_fild == "socialStatus")
			socialStatus = std::stoi(std::string(*strText));
		if (s_fild == "typeBot")
			typeBot = std::string(*strText);
		strText++;
	}
	// std::cout << name << std::endl;
	if (isPlayer)
		peopleList->push_back(new PlayerH(name, gender, isPlayer, age, happy, money, intelect, health, socialStatus, 0));
	else
		peopleList->push_back(BotConstructor::create(typeBot, name, gender, isPlayer, age, happy, money, intelect, health, socialStatus, 0));
	std::cout << "-------------------\n";
	for (int i = 0; i < peopleList->size(); i++)
	std::cout << (*peopleList)[i]->name << "\n";
	return 0;
}

static int	scb_loadLinkPeople(void *data, int nbrColums, char **strText, char **nameFild) {
	memlist<IHuman *>	*peopleList = reinterpret_cast<memlist<IHuman *> *>(data);
	std::string			fild;
	std::string			value;
	IHuman				*human;
	IHuman				*addHuman;
	int					size;

	size = peopleList->size();
	human = 0;
	while (nbrColums-- > 0) {
		fild = *nameFild++;
		value = *strText++;
		if (fild == "save_id")
			continue;
		if (fild == "name"){
			for (int i = 0; i < size; i++) {
				if ((*peopleList)[i]->name == value)
					human = (*peopleList)[i];
			}
			if (!human) {
				std::cerr << "Error in load\n";
				exit(0);
			}
		}
		else if (human && value == "y") {
			for (int i = 0; i < size; i++) {
				if ((*peopleList)[i]->name == fild)
					addHuman = (*peopleList)[i];
			}
			if (!addHuman) {
				std::cerr << "Error in load\n";
				exit(0);
			}
			if (!human->familiarHumanList->checkExistence(addHuman) && human != addHuman) {
				human->familiarHumanList->push_front(addHuman);
				addHuman->familiarHumanList->push_front(human);
			}
		}

		// std::cout << fild << " - " << value << "\n";
	}
	return 0;
}

static int	scb_loadLinkPlace(void *data, int nbrColums, char **strText, char **nameFild) {
	t_help				*helpData = reinterpret_cast<t_help *>(data);
	memlist<IHuman *>	*peopleList = helpData->peopleList;
	memlist<Place *>	*placeList = helpData->placeList;
	std::string			fild;
	std::string			value;
	IHuman				*human;
	Place				*place;
	int					size;

	std::cout << "asdasd------------------------------------------------------easdasd\n";

	size = 0;
	human = 0;
	while (nbrColums-- > 0) {
		fild = *nameFild++;
		value = *strText++;
		std::cout << fild << ": " << value << "\n";
		if (fild == "save_id")
			continue;
		if (fild == "name"){
			size = peopleList->size();
			for (int i = 0; i < size; i++) {
				if ((*peopleList)[i]->name == value)
					human = (*peopleList)[i];
			}
			if (!human) {
				std::cerr << "Error in load\n";
				exit(0);
			}
		}
		else if (human && value == "y") {
			size = placeList->size();
			for (int i = 0; i < size; i++) {
				if ((*placeList)[i]->placeParam.name == fild)
					place = (*placeList)[i];
			}
			if (!place) {
				std::cerr << "Error in load\n";
				exit(0);
			}
			if (!human->familiarPlaceList->checkExistence(place)) {
				human->familiarPlaceList->push_front(place);
			}
		}
	}
	return 0;
}

void		IDataSIController::_load(std::string saveName) {
	sqlite3				*db = 0;
	char				*err = 0;
	std::string			path;
	std::string			sql_PeopleTable;
	std::string			sql_LinkPeople;
	std::string			sql_LinkPlace;
	memlist<IHuman *>	*peopleList = new memlist<IHuman *>();
	memlist<Place *>	*placeList = this->_placeList;
	t_help				*helpData = new t_help;

	path = "./db/save_dir/" + saveName + ".dblite";

	sql_PeopleTable = "SELECT * FROM PeopleTable;\n";
	sql_LinkPeople = "SELECT * FROM LinkPeople;\n";
	sql_LinkPlace = "SELECT * FROM LinkPlace;\n";

	helpData->placeList = placeList;
	helpData->peopleList = peopleList;
	if (sqlite3_open(path.c_str(), &db))
		std::cout << "Something wrong...\n";
	else {
		this->_nullifyGameData();
			// load PeopleTable
		if (sqlite3_exec(db, sql_PeopleTable.c_str(), &scb_loadPeopleTable, peopleList, &err)) {
			fprintf(stderr, "Ошибка SQL: %s\n", err);
			sqlite3_free(err);
			return;
		}
		int size = peopleList->size();
		this->_peopleList = peopleList;
		for (int i = 0; i < size; ++i)
			(*peopleList)[i]->ptrSIGame = this;
			// load LinkPeople
		if (sqlite3_exec(db, sql_LinkPeople.c_str(), &scb_loadLinkPeople, peopleList, &err)) {
			fprintf(stderr, "Ошибка SQL: %s\n", err);
			sqlite3_free(err);
			return;
		}

		std::cout << "-----------------------------\n";
			// load LinkTable
		if (sqlite3_exec(db, sql_LinkPlace.c_str(), &scb_loadLinkPlace, helpData, &err)) {
			fprintf(stderr, "Ошибка SQL: %s\n", err);
			sqlite3_free(err);
			return;
		}
	}
	// delete helpData;
	sqlite3_close(db);
}