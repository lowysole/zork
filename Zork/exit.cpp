#include "exit.h"
#include "room.h"

//Constructor
Exit::Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination):
Entity(name, description, (Entity*)origin){
	this->opposite_name = opposite_name;
	this->locked = false;
	this->entity_type = EXIT;
	this->blocked = false;
	this->destination = destination;
	destination->container.push_back(this);
}

//Destructor
Exit::~Exit()
{
}

const string& Exit::GetNameDestination(const Room* room) {
	if (room == parent) {
		return name;
	}
	else if (room == destination) {
		return opposite_name;
	}
	return "";
}

Room* Exit::GetRoomDestination(const Room* room) {
	if (room == parent) {
		return destination;
	}
	else if (room == destination) {
		return (Room*) parent;
	}
	return false;
}