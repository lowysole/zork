#include "entity.h"
#include "utils.h"
#include "item.h"

//Constructor
Entity::Entity(const char* name, const char* description, Entity* parent = NULL) {
	this->name = name;
	this->description = description;
	this->parent = parent;
	entity_type = ENTITY;
	if (parent != NULL)
		parent->container.push_back(this);
}

//Destructor
Entity::~Entity()
{
}

void Entity::Look()
{
	cout << name << "\n";
	cout << description << "\n";
}

void Entity::SetNewParent(Entity* new_parent) {
	if (parent != NULL && new_parent != NULL) {
		parent->container.remove(this);
		parent = new_parent;
		parent->container.push_back(this);
	}
}

// Find all objects of type
list<Entity*> Entity::FindAll(EntityType type)
{
	list<Entity*> list_items;
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it) {
		if ((*it)->entity_type == type) {
			list_items.push_back(*it);
		}
	}
	return list_items;
}

// Find object of type with name
Entity* Entity::Find(const string& name, EntityType type) {
	list<Entity*> list_items;
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it) {
		if ((*it)->entity_type == type) {
			if (Compare((*it)->name, name)) {
				return (*it);
			}
		}
	}
	return NULL;
}


//Find item in the inventory. Else, in the bag.
//Return item
Entity* Entity::FindInverntoryItem(const string& name) {
	Item* item = (Item*)Find(name, ITEM);
	if (item == NULL) {
		Item* item = (Item*)Find("bag", ITEM);
		if (item == NULL) {
			cout << "Bag has been dropped." << endl;
			return false;
		}
		Item* bag_item = (Item*)item->Find(name, ITEM);
		if (bag_item == NULL) {
			cout << "You don't have this item in the inventory." << endl;
			return false;
		}
		else
			return bag_item;
	}
	else
		return item;
}