#include "HumanRelationship.hpp"
#include "IHuman.hpp"

HumanRelationship::HumanRelationship() {
	this->human = 0;
	this->relationship = 0;
}

HumanRelationship::HumanRelationship(HumanRelationship const & ref) {
	*this = ref;
}

HumanRelationship::~HumanRelationship() {

}

HumanRelationship	& HumanRelationship::operator=(HumanRelationship const & ref) {
	this->human = ref.human;
	this->relationship = ref.relationship;
	return *this;
}

bool				HumanRelationship::operator==(HumanRelationship const & ref) {
	if (this->human == ref.human && this->relationship == ref.relationship)
		return true;
	return false;
}