#include "creature.h"

//Constructor
Creature::Creature(const char* name, const char* description, Room* location) :
Entity(name, description, (Entity*)location) {
	this->entity_type = CREATURE;
	this->location = location;
}

//Destructor
Creature::~Creature() {

}