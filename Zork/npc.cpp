#include "npc.h"

// Constructor
Npc::Npc(const char* name, const char* description, Room* location) :
	Creature(name, description, location) {
	this->creature_type = NPC;

}

// Destructor
Npc::~Npc() {

}

bool Npc::isAlive() {
	if (this->hp > 0) {
		return true;
	}
	return false;
}