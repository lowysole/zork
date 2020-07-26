#ifndef __Creature__
#define __Creature__

#include <vector>
#include "entity.h"

enum CreatureType {
	NPC,
	PLAYER
};

class Room;
class Item;
class Npc;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* location);
	~Creature();

	virtual void Look();
	Room* GetCurrentRoom();
	void Stats();
	void KillNPC(Npc* npc);

	CreatureType creature_type;
	Room* location;
	int hp;
	int attack;
	Item* armour;
	Item* weapon;
};

#endif // __Creature__