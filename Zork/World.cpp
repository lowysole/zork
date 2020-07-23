#include <iostream>
#include "world.h"
#include "utils.h"

World::World() {

}


//Destructor
//World::~World() {
//	for (list<Entity*>::iterator it = entities.begin(); it != entities.end; it++)
//		delete *it;
//
//	entities.clear();
//}

bool World::ParseCommand(vector<string>& args) {
	bool parsed = true;

	switch (args.size()) 
	{

		case 1:
		{
			if (Compare(args[0], "look")) 
			{
				cout << "look chosen" << endl;
			}
			else if (Compare(args[0], "go"))
			{
				cout << "go chosen" << endl;
			}
			else if(Compare(args[0], "stats"))
			{
				cout << "stats chosen" << endl;
			}
			else if (Compare(args[0], "inventory"))
			{
				cout << "inventory chosen" << endl;
			}
			else
			{
				parsed = false;
			}
			break;
		}
		case 2: // commands with one argument ------------------------------
		{
			if (Compare(args[0], "look"))
			{
				// TODO
			}
			else if (Compare(args[0], "go"))
			{
				// TODO
			}
			else if (Compare(args[0], "take"))
			{
				// TODO
			}
			else if (Compare(args[0], "drop"))
			{
				// TODO
			}
			else if (Compare(args[0], "equip"))
			{
				// TODO
			}
			else if (Compare(args[0], "unequip"))
			{
				// TODO
			}
			else if (Compare(args[0], "examine"))
			{
				// TODO
			}
			else if (Compare(args[0], "attack"))
			{
				// TODO
			}
			else if (Compare(args[0], "loot"))
			{
				// TODO
			}
			else
				parsed = false;
			break;
		}
		case 4:
		{
			if (Compare(args[0], "unlock"))
			{
			// TODO
			}
			else
			parsed = false;
			break;
		}
		default:
			parsed = false;
	}
	return parsed;
}
