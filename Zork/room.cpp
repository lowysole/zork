#include "room.h"

//Constructor
Room::Room(const char* name, const char* description) :
Entity(name, description, NULL)
{
	this->entity_type = ROOM;
}

//Destructor
Room::~Room() {

}
