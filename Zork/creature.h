#ifndef __Creature__
#define __Creature__

#include "entity.h"

enum CreatureType {
	NPC,
	PLAYER
};

class Room;
class Item;

class Creature: public Entity
{
public:
	Creature(const char* name, const char* description, Room* location);
	~Creature();

	virtual void Look();
	Room* GetCurrentRoom();
	void Stats();

	CreatureType creature_type;
	Room* location;
	int hp;
	int attack;
	Item* armour;
	Item* weapon;
};

#endif // __Creature__