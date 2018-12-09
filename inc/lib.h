#ifndef LIB_H
# define LIB_H

# include <vector>
# include <iostream>
# include <windows.h>
# include <ctime>
# include <time.h>

# define DEF_HAPPY 10

typedef	struct	s_date
{
	unsigned int	year;
}				t_date;

typedef struct	s_stats
{
	// s_stats(){
	// 	this->happy = -5;
	// 	this->money = 0;
	// 	this->intelect = 0;
	// 	this->health = 0;
	// 	this->socialStatus = 0;
	// }
	int			happy;

	int			money;
	
	int			intelect;
	int			health;
	
	int			socialStatus;
}				t_stats;


#endif