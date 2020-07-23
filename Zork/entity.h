#ifndef __Entity__
#define __Entity__

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

	EntityType entity_type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> container;
};

#endif // __Entity__
