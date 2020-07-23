#include "exit.h"

//Constructor
Exit::Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination):
Entity(name, description, (Entity*)origin){
	this->destination = destination;
	this->opposite_name = opposite_name;
	this->locked = false;
	this->entity_type = EXIT;
}

//Destructor
Exit::~Exit()
{
}
