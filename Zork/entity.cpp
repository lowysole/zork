#include "entity.h"
#include "utils.h"

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

list<Entity*> Entity::FindAll(EntityType type)
{
	list<Entity*> list_items;
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it) {
		if ((*it)->entity_type == ITEM) {
			list_items.push_back(*it);
		}
	}
	return list_items;
}

Entity* Entity::Find(const string& name, EntityType type) {
	list<Entity*> list_items;
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it) {
		if ((*it)->entity_type == ITEM) {
			if (Compare((*it)->name, name)) {
				return (*it);
			}
		}
	}
	return NULL;
}


