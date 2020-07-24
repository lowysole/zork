#include "player.h"
#include "room.h"
#include "creature.h"
#include "item.h"


//Constructor
Player::Player(const char* name, const char* description, Room* location) :
	Creature(name, description, location) {
	creature_type = PLAYER;
	this->health = 10;
}

//Destructor
Player::~Player() {
}

void Player::Look(const vector<string>& args) {

	if (args.size() > 1) {

		if (Compare(args[1], "me"))
		{
			cout << name << endl;
			cout << description << endl;
			return;
		}
		//Look all things in the room 
		if (parent->entity_type == ROOM && Compare(args[1], parent->name)) {
			Room *room = (Room*)parent;
			room->Look();
			return;

		}
		//Look something
		for (list<Entity*>::iterator it = parent->container.begin();
			it != parent->container.end(); ++it) {

			if (Compare((*it)->name, args[1]) && (*it)->entity_type != EXIT) {
				if ((*it)->entity_type == CREATURE) {
					Creature* creature = (Creature*)*it;
					creature->Look();
				}
				else if ((*it)->entity_type == ITEM) {
					Item* item = (Item*)*it;
					item->Look();
				}
				else
					(*it)->Look();
				return;
			}
		}

	}
	else {
		parent->Look();
	}

}