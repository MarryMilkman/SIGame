#ifndef SID_HPP
#define SID_HPP

# include <vector>
# include <iostream>
# include <fstream>
# include <sstream>

typedef struct	s_sid
{
	auto		value;
	std::string	type;
	std::string	name;
}				t_sid;

class sid
{
public:
	~sid();

	static t_sid	deser_sid(std::string path);

private:
	sid();

	void			s_parsLine(std::string line, std::vector<t_sid> & vect);
	auto			& sid::_initValue(std::string param, std::string const & type);
};
#endif		