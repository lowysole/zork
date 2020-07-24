#include "creature.h"
#include "npc.h"

//Constructor
Creature::Creature(const char* name, const char* description, Room* location) :
Entity(name, description, (Entity*)location) {
	this->entity_type = CREATURE;
	this->location = location;
}

//Destructor
Creature::~Creature() {

}

void Creature::Look()
{
	if (creature_type == NPC) {
		Npc* npc = (Npc*)this;
		if (npc->isAlive())
		{
			cout << name << endl;
			cout << description << endl;
		}
		else
		{
			cout << name << "'s body, he is dead" << endl;
		}
	}
}

Room* Creature::GetCurrentRoom() {
	return (Room*) parent;
}