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
	armour = NULL;
	weapon = NULL;
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
	cout << "Attack: " << attack << endl;
	cout << "Weapon: " <<
		((weapon) ? weapon->name : "no weapon equiped") << endl;


}
void Creature::KillNPC(Npc* npc) {
	npc->hp = 0;

	// Drop enemy items to the current Room
	Room* room = this->GetCurrentRoom();
	list<Entity*> items = npc->FindAll(ITEM);
	for (list<Entity*>::iterator it = items.begin(); it != items.end(); ++it) {
		(*it)->SetNewParent((Entity*)room);
		cout << "Enemy item '" << (*it)->name << "' dropped into the room." << endl;
	}
}
