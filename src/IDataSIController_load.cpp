#include "IDataSIController.hpp"

#include "BotConstructor.hpp"

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
	std::cout << name << std::endl;
	if (isPlayer)
		peopleList->push_front(new PlayerH(name, gender, isPlayer, age, happy, money, intelect, health, socialStatus, 0));
	else
		peopleList->push_front(BotConstructor::create(typeBot, name, gender, isPlayer, age, happy, money, intelect, health, socialStatus, 0));
	return 0;
}

static int	scb_loadLinkPeople(void *data, int nbrColums, char **strText, char **nameFild) {
	return 0;
}

void		IDataSIController::_load(std::string saveName) {
	sqlite3				*db = 0;
	char				*err = 0;
	std::string			path;
	std::string			sql_PeopleTable;
	std::string			sql_LinkPeople;
	memlist<IHuman *>	peopleList = memlist<IHuman *>();

	path = "./db/save_dir/" + saveName + ".dblite";

	sql_PeopleTable = "SELECT * FROM PeopleTable;\n";
	sql_LinkPeople = "SELECT * FROM LinkPeople;\n";

	if (sqlite3_open(path.c_str(), &db))
		std::cout << "Something wrong...\n";
	else {
		this->_nullifyGameData();
			// load PeopleTable
		if (sqlite3_exec(db, sql_PeopleTable.c_str(), &scb_loadPeopleTable, &peopleList, &err)) {
			fprintf(stderr, "Ошибка SQL: %s\n", err);
			sqlite3_free(err);
			return;
		}
		int size = peopleList.size();
		for (int i = 0; i < size; ++i)
			peopleList[i]->ptrSIGame = this;
		this->_peopleList = peopleList;
			
			// load LinkPeople
		if (sqlite3_exec(db, sql_PeopleTable.c_str(), &scb_loadLinkPeople, &peopleList, &err)) {
			fprintf(stderr, "Ошибка SQL: %s\n", err);
			sqlite3_free(err);
			return;
		}
	}
	sqlite3_close(db);
}