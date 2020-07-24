#include "player.h"
#include "room.h"
#include "creature.h"
#include "item.h"
#include "exit.h"


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

bool Player::Go(const vector<string>& args)
{
	// Get Room from Player (Creature)
	Room* room = GetCurrentRoom();
	// Check Exit from Room
	Exit* ex = room->GetExit(args[1]);
	if (ex == NULL) {
		cout << "No direction found." << endl;
		return false;
	}
	else if (ex->locked) {
		cout << "The door is locked. You need a pass." << endl;
		return false;
	}
	else if (ex->blocked) {
		cout << "The door is blocked for the enemies. "
			"You need to kill them." << endl;
		return false;
	}
	cout << "You've entered to " << ex->GetNameDestination(room) << '.' << endl;

	// Setting new Parent Room
	SetNewParent(ex->GetRoomDestination(room));

	//Display info from current Room
	parent->Look();
	return true;
}

