#include "room.h"
#include "item.h"
#include "creature.h"
#include "npc.h"
#include "exit.h"

//Constructor
Room::Room(const char* name, const char* description) :
Entity(name, description, this)
{
	this->entity_type = ROOM;
}

//Destructor
Room::~Room() {

}

void Room::Look() {
	
	cout << name << endl;
	cout << description << endl;

	//List Exits
	for (list<Entity*>::iterator it = container.begin();
		it != container.end(); ++it) 
	{
		if ((*it)->entity_type == EXIT) {
			Exit* ex = (Exit*)*it;
			cout << "From " << ex->GetRoomName(this) << " you see " << ex->GetRoomDestination(this)->name << endl;
		}
	}

	//List Items
	for (list<Entity*>::iterator it = container.begin();
		it != container.end(); ++it)
	{
		if ((*it)->entity_type == ITEM) {
			Item* item = (Item*)*it;
			cout << "There is one item: " << item->name << endl;
		}
	}

	//List Creatures
	for (list<Entity*>::iterator it = container.begin();
		it != container.end(); ++it)
	{
		if ((*it)->entity_type == CREATURE) {
			Creature* creature = (Creature*)*it;
			if (creature->creature_type == NPC) {
				Npc* npc = (Npc*)creature;
				cout << "There is someone here: " << creature->name ;
				if (!npc->isAlive())
					cout << "(dead)";
				cout << endl;
			}
		}
	}
}
