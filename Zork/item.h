#ifndef __Item__
#define __Item__

#include <string>
#include <list>
#include "entity.h"

using namespace std;

enum ItemType {
	WEAPON,
	ARMOUR,
	OBJECT
};

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity*	parent, ItemType item_type = OBJECT);
	~Item();

	virtual void Look();

	int min_value;
	int max_value;
	ItemType item_type;
};

#endif // __Item__