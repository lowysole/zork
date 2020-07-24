#include "entity.h"

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


