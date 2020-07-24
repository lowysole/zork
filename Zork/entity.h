#ifndef __Entity__
#define __Entity__

#include <iostream>
#include <string>
#include <list>

using namespace std;

enum EntityType {

	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	~Entity();

	void Look();
	void SetNewParent(Entity* new_parent);

	EntityType entity_type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> container;
};

#endif // __Entity__
