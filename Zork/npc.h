#ifndef __Npc__
#define __Npc__

#include "creature.h"

class Npc : public Creature
{
public:
	Npc(const char* name, const char* description, Entity* parent, Room* location);
	~Npc();
	
	int health;
};

#endif // !__Npc__
