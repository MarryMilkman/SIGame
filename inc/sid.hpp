#ifndef SID_HPP
#define SID_HPP

# include <vector>
# include <iostream>
# include <fstream>
# include <sstream>

typedef struct	s_sid
{
	void		*value;
	std::string	type;
	std::string	name;
}				t_sid;

class sid
{
public:
	~sid();

	static std::vector<t_sid>	deser_sid(std::string const & path);

private:
	sid();

	static void		_parsLine(std::string line, std::vector<t_sid> & vect);
	static void		*_initValue(std::string param, std::string const & type);
};
#endif		