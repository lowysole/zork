#include "item.h"

//Constructor
Item::Item(const char* name, const char* description, Entity* parent, ItemType item_type):
Entity(name, description, parent) {
	this->item_type = item_type;
	entity_type = ITEM;
	min_value = max_value = 0;
}

//Destructor
Item::~Item() {
}
