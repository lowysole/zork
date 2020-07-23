#include "npc.h"

// Constructor
Npc::Npc(const char* name, const char* description, Room* location) :
	Creature(name, description, location) {
	this->creature_type = NPC;
	this->health = 10;

}

// Destructor
Npc::~Npc() {

}