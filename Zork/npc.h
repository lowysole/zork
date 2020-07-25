#ifndef __Npc__
#define __Npc__

#include "creature.h"

class Npc : public Creature
{
public:
	Npc(const char* name, const char* description, Room* location);
	~Npc();
	
	bool isAlive();
};

#endif // __Npc__
