#ifndef __Player__
#define __Player__

#include "creature.h"

class Player: public Creature
{
public:
	Player(const char* name, const char* description, Entity* parent, Room* location);
	~Player();

	int health;

};

#endif // __Player__
