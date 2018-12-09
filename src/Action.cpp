#include "Action.hpp"

int	Action::_countCommand = 3;

Action::~Action() {
}

void	doAction() {

}

void	Action::doAction() {
	// void	(Action::*arr_func[this->_countCommand])(std::string) = 
	// {
	// 	&Action::_walk,
	// 	&Action::_goToPlace,
	// 	&Action::_speakWith
	// };
	std::cout << "Start do same action\n";

	int				choiceCommand;
	std::string		command = std::string();

	choiceCommand = this->_choiseCommand();
	if (choiceCommand == 0) {
		this->_walk("");
	}
	if (choiceCommand == 1) {
		this->_goToPlace("");
	}
	if (choiceCommand == 2) {
		this->_speakWith("");
	}
	// (this->*arr_func[choiceCommand])("");
}

void	Action::_walk(std::string str) {
	if (str == "hello") {
		std::cout << "wolk\n";
		return ;
	}
	std::cout << " reshil proguliatsya (walk)\n";
}

void	Action::_goToPlace(std::string str) {
	if (str == "hello") {
		std::cout << "go to place\n";
		return ;
	}
	std::cout << "Now we go to some plase\n";
}

void	Action::_speakWith(std::string str) {
	if (str == "hello") {
		std::cout << "speak with someone\n";
		return ;
	}
	std::cout << "hear is list of person\n";
}

// Choise

int		Action::_choiseCommand() {
	int			returnCommand;
	int			nbr;
	std::string	command = "";

	returnCommand = -1;
	std::cout << "???????????????" << "\n"; 
	// if (this->_player->isPlayer) {
		this->_displayAllCommand();
		while (command.empty() && returnCommand == -1) {
			std::cout << "Enter your command!: ";
			getline(std::cin, command);
			std::cout << command << "\n";
			try {
				nbr = std::stoi(command);
				returnCommand = nbr >= 0 && nbr <= this->_countCommand ? nbr : returnCommand;
				if (returnCommand == -1) {
					std::cout << "There is no suitable team\n";
					continue;
				}
			}
			catch (std::exception & what) {
				std::cout << "It is not a nbr!\n";
			}
		}
	// }
	// else {
	// 	// Тут будет поведение ботов...
	// 	std::cout << "IT IS NPS!\n";
	// 	return (0);
	// }
	return (returnCommand);
}


void	Action::_displayAllCommand() {
	std::cout << "0: walk\n";
	std::cout << "1: go to some plase\n";
	std::cout << "2: speak with someone\n";
}