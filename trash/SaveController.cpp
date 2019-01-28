#include "SaveController.hpp"


	// DROP TABLE Save_List;\
	// 				CREATE TABLE IF NOT EXISTS Save_List(\
	// 					save_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\
	// 					name_save CHAR(40)\
	// 				);\
	// 				INSERT INTO Save_List (name_save) VALUES ('save1');\
	// 				INSERT INTO Save_List (name_save) VALUES ('save2');\

SaveController::SaveController() {
	this->_initSaveList();
}

SaveController::~SaveController() {
}

// MARK: - init list save


static int	scb_initSaveList(void *data, int nbrColums, char **strText, char **nameFild) {
	SaveController	*sc = reinterpret_cast<SaveController *>(data);
	std::string		str;
	t_save			save;

	while (nbrColums-- > 0) {
		str = *nameFild++;
		if (str == "save_id")
			save.save_id = atoi(*strText++);
		else
			save.name = *strText++;
	}
	sc->listSave.push_back(save);
	return 0;
}

void		SaveController::_initSaveList() {

	sqlite3 	*db		= 0;
	char 		*err	= 0;
	const char*	sql		= "SELECT save_id, name_save FROM Save_List;";


	listSave = std::vector<t_save>();
	if( sqlite3_open("./db/saveList.dblite", &db) )
		std::cout << "something wrong....\n";
	else if (sqlite3_exec(db, sql, &scb_initSaveList, this, &err))
	{
		fprintf(stderr, "Ошибка SQL: %sn", err);
		sqlite3_free(err);
	}
	sqlite3_close(db);
}


void		SaveController::menuControll() {
	char	c;

	std::cout << "(<< Hello in conntroll menu of SaveController >>)\n";
	while (true) {
		std::cout << "Option:\n";
		std::cout	<< "1) Menu for Load\n"
				<< "2) New save\n" 
				<< "3) Out\n";
		while ((c = _getch()) && c != '1' && c != '2' && c != '3' && c != 27) ;
		if (c == '1')
			this->menuForLoad();
		if (c == '2')
			this->createSave();
		if (c == '3' || c == 27)
			return ;
	}
	
}

// MARK: - show / save / load / remove

void		SaveController::menuForLoad() {
	int		i = -1;
	int		size = this->listSave.size();
	t_save	save;
	char	c;

	while (++i < size) {
		save = this->listSave[i];
		std::cout << save.save_id << ") " << save.name << "\n"; 
	}
	while (1) {
		while ((c = _getch()) && c < '0' && c >= '0' + size && c != 27) ;
		if (c == 27)
			break ;
		std::cout << "\nOption for " << c -'0' << ":\n1) load\n2) remove\n";
		while ((c = _getch()) && c != '1' && c != '2' && c != 27) ;
		if (c == '1')
			this->_loadSave(c - '0');
		if (c == '2')
			this->_removeSave(c - '0');
	}
	
}

	// save
void		SaveController::createSave() {
	std::string		nameSave;
	sqlite3 		*db = 0;
	char 			*err = 0;
	std::string		sql = "INSERT INTO Save_List (name_save) VALUES ('";

	std::cout << "Name: ";
	std::cin >> nameSave;
	sql += nameSave + "');";
	if (sqlite3_open("./db/saveList.dblite", &db))
		std::cout << "something wrong....\n";
	else if (sqlite3_exec(db, sql.c_str(), 0, 0, &err)) {
		fprintf(stderr, "Ошибка SQL: %sn", err);
		sqlite3_free(err);
	}
	sqlite3_close(db);
}

	// load
void		SaveController::_loadSave(int save_id) {
	std::cout << "load...\n";
}

	// remove
static int	scb_getNameAndRemove(void *data, int nbrColums, char **strText, char **nameFild) {
	std::cout << *strText << " - " << nbrColums << "\n";
	*(reinterpret_cast<std::string *>(data)) = *strText;
	std::cout << "remove...\n";
}

void		SaveController::_removeSave(int	save_id) {
	std::string		strName;
	sqlite3 		*db = 0;
	char 			*err = 0;
	std::string		sql = "SELECT name_save FROM Save_List WHERE save_id = ";

	sql += save_id + ";";
	if (sqlite3_open("./db/saveList.dblite", &db))
		std::cout << "something wrong....\n";
	else if (sqlite3_exec(db, sql.c_str(), &scb_getNameAndRemove, &strName, &err)) {
		fprintf(stderr, "Ошибка SQL: %sn", err);
		sqlite3_free(err);
	}
	sqlite3_close(db);
	std::cout << "U want delete '" << strName << "' save\n";
}