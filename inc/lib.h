#ifndef LIB_H
# define LIB_H

# include <vector>
# include <iostream>
# include <stdio.h>
# include <ctime>
# include <time.h>

# ifdef __APPLE__
char	_getch();
# endif


# ifdef _WIN32
#  include <conio.h>
#  define INT_MAX 2147483647
#  define INT_MIN -2147483648
# endif

# include "sqlite3.h"


typedef struct	s_save
{
	std::string	name;
	int			save_id;
}				t_save;

typedef	struct	s_date
{
	unsigned int	year;
}				t_date;

typedef struct	s_stats
{
	int			happy;

	int			money;
	
	int			intelect;
	int			health;
	
	int			socialStatus;
}				t_stats;

#endif