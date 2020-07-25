#include "creature.h"
#include "npc.h"
#include "item.h"

//Constructor
Creature::Creature(const char* name, const char* description, Room* location) :
Entity(name, description, (Entity*)location) {
	entity_type = CREATURE;
	this->location = location;
	hp = 10;
	attack = 0;
	armour = weapon = NULL;
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

void Creature::Stats() {
	cout << "Stats from " << name << ":" << endl;
	cout << "-----------------------" << endl;
	cout << "HP: " << hp << endl;
	cout << "Armour: " <<
		((armour) ? armour->name : "no armour equiped") << endl;
	cout << "Attack: " << hp << endl;
	cout << "Weapon: " <<
		((weapon) ? weapon->name : "no weapon equiped") << endl;


}