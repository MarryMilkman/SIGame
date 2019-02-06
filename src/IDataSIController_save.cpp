#include "IDataSIController.hpp"

#include "PlayerH.hpp"
#include "GrayBotH.hpp"
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
	this->_initSaveList();
}

void		IDataSIController::_createNewSave(std::string saveName) {
	sqlite3		*db = 0;
	char		*err = 0;
	std::string	path;

	std::string	fild;
	int			size;
	int			i;

		// init table in DB
	std::string	sql;

	sql = "";
	sql = "DROP TABLE IF EXISTS CheckTable;\n\
DROP TABLE IF EXISTS PeopleTable;\n\
DROP TABLE IF EXISTS PlaceTable;\n\
DROP TABLE IF EXISTS LinkPeople;\n\
DROP TABLE IF EXISTS LinkPlace;\n";

	sql = sql + "CREATE TABLE IF NOT EXISTS CheckTable(save_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT);\n\
CREATE TABLE IF NOT EXISTS PeopleTable(save_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT);\n\
CREATE TABLE IF NOT EXISTS PlaceTable(save_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT);\n\
CREATE TABLE IF NOT EXISTS LinkPeople(save_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT);\n\
CREATE TABLE IF NOT EXISTS LinkPlace(save_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT);\n";

		// for PeopleTable
	sql = sql + "ALTER TABLE PeopleTable ADD name CHAR(30);\n\
ALTER TABLE PeopleTable ADD isPlayer INT;\n\
ALTER TABLE PeopleTable ADD age INT;\n\
ALTER TABLE PeopleTable ADD gender CHAR(30);\n\
ALTER TABLE PeopleTable ADD happy INT;\n\
ALTER TABLE PeopleTable ADD money INT;\n\
ALTER TABLE PeopleTable ADD intelect INT;\n\
ALTER TABLE PeopleTable ADD health INT;\n\
ALTER TABLE PeopleTable ADD socialStatus INT;\n\
ALTER TABLE PeopleTable ADD typeBot CHAR(30);\n";
		// for PlaceTable
	sql = sql + "ALTER TABLE PlaceTable ADD name CHAR(30);\n\
ALTER TABLE PlaceTable ADD happy INT;\n\
ALTER TABLE PlaceTable ADD money INT;\n\
ALTER TABLE PlaceTable ADD intelect INT;\n\
ALTER TABLE PlaceTable ADD health INT;\n\
ALTER TABLE PlaceTable ADD socialStatus INT;\n\
\n\
ALTER TABLE PlaceTable ADD ifHappy INT;\n\
ALTER TABLE PlaceTable ADD ifHappyLess INT;\n\
ALTER TABLE PlaceTable ADD ifHappyMore INT;\n\
\n\
ALTER TABLE PlaceTable ADD ifIntelect INT;\n\
ALTER TABLE PlaceTable ADD ifIntelectLess INT;\n\
ALTER TABLE PlaceTable ADD ifIntelectMore INT;\n\
\n\
ALTER TABLE PlaceTable ADD ifMoney INT;\n\
ALTER TABLE PlaceTable ADD ifMoneyLess INT;\n\
ALTER TABLE PlaceTable ADD ifMoneyMore INT;\n\
\n\
ALTER TABLE PlaceTable ADD ifHealth INT;\n\
ALTER TABLE PlaceTable ADD ifHealthLess INT;\n\
ALTER TABLE PlaceTable ADD ifHealthMore INT;\n\
\n\
ALTER TABLE PlaceTable ADD ifSocialStatus INT;\n\
ALTER TABLE PlaceTable ADD ifSocialStatusLess INT;\n\
ALTER TABLE PlaceTable ADD ifSocialStatusMore INT;\n";
	// for LinkPeople
	sql = sql + "ALTER TABLE LinkPeople ADD name CHAR(30);\n";
	size = this->_peopleList.size();
	i = -1;
	while (++i < size) {
		fild = "ALTER TABLE LinkPeople ADD " + this->_peopleList[i]->name + " CHAR(30);\n";
		sql = sql + fild;
	}
		// for LinkPlace
	sql = sql + "ALTER TABLE LinkPlace ADD name CHAR(30);\n";
	size = this->_placeList.size();
	i = -1;
	while (++i < size) {
		fild = "ALTER TABLE LinkPlace ADD " + this->_placeList[i]->placeParam.name + " CHAR(30);\n";
		sql = sql + fild;
	}
	sql = sql + this->_insertSql();
	// SQL request ready

	std::cout << sql;
	path = "./db/save_dir/" + saveName + ".dblite";
	if (sqlite3_open(path.c_str(), &db))
		std::cout << "something wrong....\n";
	else if (sqlite3_exec(db, sql.c_str(), 0, 0, &err)) {
		fprintf(stderr, "Error SQL: %s\n", err);
		sqlite3_free(err);
	}
	sqlite3_close(db);
}

		//insert SQL
std::string	IDataSIController::_insertSql() {
	int				i;
	int				j;
	int				size;
	int				size2;

	std::string		strRow;
	std::string		strAns;
	
	Place			*place;
	Place			*checkPlace;

	IHuman			*player;
	IHuman			*checkHuman;
	
	std::string		name;
	std::string		bool_s;
	std::string		sql = "";

		// for PeopleTable
	sql = sql + "\n";
	size = this->_peopleList.size();
	i = -1;
	while (++i < size) {
		bool_s = this->_peopleList[i]->isPlayer ? "y" : "n";
		sql = sql + "INSERT INTO PeopleTable (name, isPlayer, age, gender, happy, money, intelect, health, socialStatus, typeBot) VALUES (\""
		+ this->_peopleList[i]->name + "\", \"" + bool_s + "\", \"" + std::to_string(this->_peopleList[i]->age) + "\", \""
		+ this->_peopleList[i]->gender + "\", \"" + std::to_string(this->_peopleList[i]->stats.happy) + "\", \""
		+ std::to_string(this->_peopleList[i]->stats.money) + "\", \"" + std::to_string(this->_peopleList[i]->stats.intelect) + "\", \""
		+ std::to_string(this->_peopleList[i]->stats.health) + "\", \"" + std::to_string(this->_peopleList[i]->stats.socialStatus) + "\", \"" + this->_peopleList[i]->botType + "\");\n";
	}
		// for PlaceTable
	/*

	*/
		// for LinkPeople
	sql = sql + "\n";
	size = this->_peopleList.size();
	i = -1;
	while (++i < size) {
		player = this->_peopleList[i];
		strRow = "name";
		strAns = "\"" + player->name + "\"";
		j = -1;
		while (++j < size) {
			checkHuman = this->_peopleList[j];
			strRow += ", " + checkHuman->name;
			if (j == i) {
				strAns += ", \"n\"";
				continue;
			}
			if (player->familiarHumanList.checkExistence(checkHuman) && checkHuman != player) {
				strAns += ", \"y\"";
			} else
				strAns += ", \"n\"";
		}
		sql = sql + "INSERT INTO LinkPeople (" + strRow +") VALUES (" + strAns + ");\n";
	}
		// for LinkPlace
	sql = sql + "\n";
	size = this->_peopleList.size();
	size2 = this->_placeList.size();
	i = -1;
	while (++i < size) {
		player = this->_peopleList[i];
		strRow = "name";
		strAns = "\"" + player->name + "\"";
		j = -1;
		while (++j < size2) {
			checkPlace = this->_placeList[j];
			strRow += ", " + checkPlace->placeParam.name;
			if (player->familiarPlaceList.checkExistence(checkPlace)) {
				strAns += ", \"y\"";
			} else
				strAns += ", \"n\"";
		}
		sql = sql + "INSERT INTO LinkPlace (" + strRow +") VALUES (" + strAns + ");\n";
	}
	return sql;
}
