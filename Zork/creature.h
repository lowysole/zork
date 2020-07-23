#ifndef __Creature__
#define __Creature__

#include "entity.h"

enum CreatureType {
	NPC,
	PLAYER
};

class Room;

class Creature: public Entity
{
public:
	Creature(const char* name, const char* description, Room* location);
	~Creature();

	CreatureType creature_type;
	Room* location;
};

#endif // __Creature__
