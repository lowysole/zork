#include "item.h"

//Constructor
Item::Item(const char* name, const char* description, Entity* parent, ItemType item_type):
Entity(name, description, parent) {
	this->item_type = item_type;
	entity_type = ITEM;
	atribute = 0;
}

//Destructor
Item::~Item() {
}

// TODO: Fix Look
void Item::Look()
{
	cout << name << endl;
	cout << description << endl;

	list<Entity*> stuff;

	if (stuff.size() > 0)
	{
		cout << "It contains: " << "\n";
		for (list<Entity*>::iterator it = stuff.begin(); it != stuff.end(); ++it)
			cout << (*it)->name << "\n";
	}
}
