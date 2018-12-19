#ifndef HUMAN_RELATIONSHIP_HPP
# define HUMAN_RELATIONSHIP_HPP

# include "lib.h"

class Human;

class HumanRelationship
{
public:
	HumanRelationship();
	HumanRelationship(HumanRelationship const & ref);
	~HumanRelationship();
	
	Human		*human;
	int			relationship;


	HumanRelationship	& operator=(HumanRelationship const & ref);
	bool				operator==(HumanRelationship const & ref);
};

#endif