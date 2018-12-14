#include "sid.hpp"

sid::sid() {
}

sid::~sid() {
}

std::vector<t_sid>	sid::deser_sid(std::string const & path_file) {
	std::fstream		fd;
	std::string			line;
	std::vector<t_sid>	rVect;

	fd.open(path_file, std::fstream::in);
	while (std::getline(fd, line))
		sid::_parsLine(line, rVect);
	return rVect;
}

void						sid::_parsLine(std::string line, std::vector<t_sid> & vect) {
	std::stringstream	ss(line);
	std::string			param;
	t_sid				sid;
	int					i;

	ss >> param;
	i = 0;
	while (!param.empty() && i < 3) {
		if (param[0] == '#')
			return ;
		if (!i)
			sid.type = param;
		if (i == 1)
			sid.name = param;
		if (i == 2)
			sid.value = sid::_initValue(param, sid.type);
		i++;
		ss >> param;
	}
	if (i == 3)
		vect.push_back(sid);
	else if (i != 0)
		std::cout << "Error in .sid file\n";
}

void	 					*sid::_initValue(std::string param, std::string const & type) {
	void	*rPtr;

	if (type == "int") {
		int	*rValue = new int(std::stoi(param));
		rPtr = rValue;
		return rPtr;
	}
	rPtr = new std::string(param);
	return rPtr;
}






