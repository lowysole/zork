#include "npc.h"

Npc::Npc(const char* name, const char* description, Entity* parent, Room* location) :
	Creature(name, description, parent, location) {
	this->creature_type = NPC;
	this->health = 10;

}
