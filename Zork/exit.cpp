#include "exit.h"
#include "room.h"

//Constructor
Exit::Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination):
Entity(name, description, (Entity*)origin){
	this->destination = destination;
	this->opposite_name = opposite_name;
	this->locked = false;
	this->entity_type = EXIT;
	this->blocked = false;
}

//Destructor
Exit::~Exit()
{
}

const string& Exit::GetRoomName(const Room* room) {
	if (room == parent) {
		return name;
	}
	else if (room == destination) {
		return opposite_name;
	}
}

Room* Exit::GetRoomDestination(const Room* room) {
	if (room == parent) {
		return destination;
	}
	else if (room == destination) {
		return (Room*) parent;
	}
}