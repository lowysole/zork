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
	bool Go(const vector<string>& args);
	bool Pick(const vector<string>& args);
	bool PickFromRoom(const vector<string>& args, bool to_bag = false);
	void Inventory();
	void PrintObject(const Item *item);
	bool Drop(const vector<string>& args);


	size_t max_inventory; // + 1 (bag)
};

#endif // __Player__
