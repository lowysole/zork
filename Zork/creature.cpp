#include "creature.h"

//Constructor
Creature::Creature(const char* name, const char* description, Entity* parent, Room* location) :
Entity(name, description, parent) {
	this->entity_type = CREATURE;
	this->location = location;
}

//Destructor
Creature::~Creature() {

}