#include "sid.hpp"

sid::sid() {
}

sid::~sid() {
}

static std::vector<t_sid>	sid::deser_sid(std::string path) {
	std::fstream		fd;
	std::string			line;
	std::vector<t_sid>	rVect;
	int					nbrLine;

	fd.open(path_file, std::fstream::in);
	nbrLine = 0;
	while (std::getline(fd, line)) {
		this->_parsLine(line, rVact, nbrLine);
		nbrLine++;
	}
	return rVect;
}

void						sid::_parsLine(std::string line, std::vector<t_sid> & vect) {
	std::stringstream	ss(line);
	std::string			param;
	t_sir				sid;
	int					i;

	ss >> param;
	i = 0;
	while (!param.empty() && i < 3) {
		if (param[0] == '#')
			return ;
		i == 0 ? sid.type = param : 0;
		i == 1 ? sid.name = param : 0;
		i == 2 ? sid.value = this->_initValue(param, sid.type) : 0;
		i++;
		ss >> param;
	}
	i == 3 ? vect.push_back(sid) : std::cout << "Error in .sid file\n";
}

auto						& sid::_initValue(std::string param, std::string const & type) {
	if (type = "int") {
		int	rValue = std::stoi(param);
		return rValue;
	}
	return param;
}






