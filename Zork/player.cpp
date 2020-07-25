#include "player.h"
#include "room.h"
#include "creature.h"
#include "item.h"
#include "exit.h"


//Constructor
Player::Player(const char* name, const char* description, Room* location) :
	Creature(name, description, location) {
	creature_type = PLAYER;
	max_inventory = 2;
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
	cout << "You've entered to " << ex->GetNameDestination(room) <<
		'.' << endl;

	// Setting new Parent Room
	SetNewParent(ex->GetRoomDestination(room));

	//Display info from current Room
	parent->Look();
	return true;
}

bool Player::Pick(const vector<string>& args) {

	if (args.size() == 2) { // To inventory (pick <object>)
		// Check if the inventory is full
		list<Entity*>  list_items = FindAll(ITEM);
		if (list_items.size() >= max_inventory) {
			cout << "Full inventory. Put the object inside the bag." << endl;
			return false;
		}
		return PickFromRoom(args, false);

	}
	else if (args.size() == 4) { // To bag (pick <object> to bag)
		if (!Compare(args[3], "bag")) {
			cout << "You cannot put this object inside a " << args[3] << endl;
			return false;
		}
		else {
			if (PickFromRoom(args, true)) {
				cout << "It's inside de bag" << endl;
				return true;
			}
			return false;
		}
	} 
	return false;
}
bool Player::PickFromRoom(const vector<string>& args, bool to_bag) {
	Entity* item = ((Room*)parent)->Find(args[1], ITEM);

	if (item == NULL)
	{
		cout << "This item desn't exist." << endl;
		return false;
	}

	cout << "You take " << item->name << "." << endl;
	if (to_bag) {
		Entity* bag = Find("bag", ITEM);
		item->SetNewParent((Item*)bag);
	}
	else
		item->SetNewParent(this);
	
	return true;
}

void Player::Inventory() {

	list<Entity*> list_items = FindAll(ITEM);
	Entity* bag = NULL;

	cout << " Inventory:" << endl;
	cout << "-----------------------" << endl;
	cout << "Max items: " << max_inventory << endl;
	for (list<Entity*>::iterator it = list_items.begin();
		it != list_items.end(); ++it) {
		Item* item = (Item*)*it;
		if (item->item_type == BAG) {
			bag = *it;
		}
		else {
			PrintObject(item);
		}
	}
	if (bag != NULL) {
		cout << "- " << "Bag." << endl;
		cout << "> Items inside bag:" << endl;
		list<Entity*> list_items = ((Item*)bag)->FindAll(ITEM);
		for (list<Entity*>::iterator it = list_items.begin();
			it != list_items.end(); ++it) {
			Item* item = (Item*)*it;
			PrintObject(item);
		}
	}
}

void Player::PrintObject(const Item *item) {
	if (item->item_type == WEAPON) {
		cout << "- " << item->name << " (Weapon)" << endl;
	}
	else if (item->item_type == ARMOUR) {
		cout << "- " << item->name << " (Armour)" << endl;
	}
	else
		cout << "- " << item->name << " (Object)" << endl;
}

bool Player::Drop(const vector<string>& args) {
	if (args.size() == 2) { //From inventory
		Entity* item = Find(args[1], ITEM);
		if (item == NULL) {
			cout << "You don't have this item in the inventory. "
				"Try to find it int he bag" << endl;
			return false;
		}
		else {
			Room* current_room = GetCurrentRoom();
			item->SetNewParent(current_room);
			cout << "Item " << item->name << " dropped to "
				<< current_room->name << endl;
			return true;
		}
	}
	else if (args.size() == 4 ) { //From bag
		Entity* item = Find(args[3], ITEM);
		if (item == NULL) {
			cout << "You cannot drop this item from " << args[3] << endl;
			return false;
		}
		Entity* bag_item = item->Find(args[1], ITEM);
		if (bag_item == NULL) {
			cout << "You don't have this item inside " << args[3] << endl;
			return false;
		}
		else {
			Room* current_room = GetCurrentRoom();
			bag_item->SetNewParent(current_room);
			cout << "Item " << bag_item->name << " dropped to "
				<< current_room->name << endl;
			return true;
		}
	}
	return false;

}

