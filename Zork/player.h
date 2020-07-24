#ifndef __Player__
#define __Player__

#include <iostream>
#include <vector>
#include "utils.h"
#include "creature.h"

using namespace std;

class Player: public Creature
{
public:
	Player(const char* name, const char* description, Room* location);
	~Player();

	void Look(const vector<string>& args);
	void Go(const vector<string>& args);

	int health;

};

#endif // __Player__
