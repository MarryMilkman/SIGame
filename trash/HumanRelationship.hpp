#ifndef HUMAN_RELATIONSHIP_HPP
# define HUMAN_RELATIONSHIP_HPP

# include "lib.h"

class IHuman;

class HumanRelationship
{
public:
	HumanRelationship();
	HumanRelationship(HumanRelationship const & ref);
	~HumanRelationship();
	
	IHuman		*human;
	int			relationship;


	HumanRelationship	& operator=(HumanRelationship const & ref);
	bool				operator==(HumanRelationship const & ref);
};

#endif