#include <iostream>
#include "entity.h"
#include "world.h"
#include "utils.h"
#include "player.h"
#include "room.h"
#include "exit.h"
#include "npc.h"
#include "item.h"


World::World() {
	// Create Rooms
	Room* garden = new Room("Garden",
		"You're outside, in the hospital garden. " 
		"Tall trees stand around you.");
	Room* hall = new Room("Hall", 
		"You're inside the Hospital, there are a lot of patients inside.");
	Room* elevator = new Room("Elevator", 
		"It sounds the typical elevator music. You aren't alone.");
	Room* security_room = new Room("Security",
		"Like the movies, there are monitors for all the security cameras.");
	Room* operations_room = new Room("Operations",
		"The room is still messy. Probably, "
		"because it's taken place an operation few time ago.");
	Room* infirmary = new Room("Infirmary",
		"An empty room full of beds with privileged views of the city.");

	entities.push_back(garden);
	entities.push_back(hall);
	entities.push_back(elevator);
	entities.push_back(security_room);
	entities.push_back(operations_room);
	entities.push_back(infirmary);

	// Create Exits
	Exit* ex_garden_hall = new Exit(
		"hall", "garden", "Principal entrance", garden, hall);
	Exit* ex_hall_security = new Exit(
		"security", "hall", "Security Room", 
		hall, security_room);
	Exit* ex_hall_elevator = new Exit(
		"elevator", "hall", "Hall elevator", hall, elevator);
	Exit* ex_elevator_operations = new Exit(
		"operations", "elevator", "Floor 1: Operations Room",
		elevator, operations_room);
	Exit* ex_elevator_infirmary = new Exit(
		"infirmary", "elevator", "Floor 2: Infirmary", elevator, infirmary);
	ex_elevator_infirmary->locked = true;

	entities.push_back(ex_garden_hall);
	entities.push_back(ex_hall_security);
	entities.push_back(ex_hall_elevator);
	entities.push_back(ex_elevator_operations);
	entities.push_back(ex_elevator_infirmary);

	// Create NPC
	Npc* security_guard = new Npc(
		"Security Guard ", "It's the Security guard from the hospital",
		security_room);
	security_guard->health = 10;
	Npc* elevator_guard = new Npc(
		"Worker", "It's the guard from the elevator",
		elevator);

	security_guard->health = 10;
	elevator_guard->health = 10;

	entities.push_back(security_guard);
	entities.push_back(elevator_guard);

	// Create Items
	Item* bag = new Item(
		"Bag", "Personal bag to store items", player);
	bag->owned = true;
	Item* letter = new Item(
		"Letter", "Mission: You need to recover the virus "
		"and escape from the hospital", garden);
	Item* key = new Item(
		"Card", "Card to enter to the infarmary.", security_guard);
	ex_elevator_infirmary->key = key;
	Item* scalpel = new Item(
		"Scalpel", "Scalpel from the last operation",
		operations_room, WEAPON);
	Item* armour = new Item(
		"Protection", "Protection from the guard", elevator_guard, ARMOUR);
	Item* virus = new Item(
		"Virus Sample", "The virus sample you're looking for", infirmary);

	entities.push_back(bag);
	entities.push_back(letter);
	entities.push_back(key);
	entities.push_back(scalpel);
	entities.push_back(armour);
	entities.push_back(virus);


	// Create Player
	string name_input = "";
	cout << "What's your name?" << endl << "> ";
	getline(cin, name_input);
	cout << "> ";
	player = new Player(name_input.c_str(), "You're the secret agent!", garden);
	player->health = 10;

	entities.push_back(player);
}


//Destructor
World::~World() {
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++)
		delete *it;

	entities.clear();
}

bool World::ParseCommand(vector<string>& args) {
	bool parsed = true;

	switch (args.size()) 
	{

		case 1:
		{
			if (Compare(args[0], "look")) 
			{
				player->Look(args);
			}
			else if(Compare(args[0], "stats"))
			{
				// TODO
			}
			else if (Compare(args[0], "bag"))
			{
				// TODO
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
				player->Look(args);
			}
			else if (Compare(args[0], "go"))
			{
				player->Go(args);
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
		case 3:
		{
			if (Compare(args[0], "go"))
			{
				player->Go(args);
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
