#include "utils.h"

bool compareChar(const char& c1, const char& c2)
{
	if (c1 == c2)
		return true;
	else if (toupper(c1) == toupper(c2))
		return true;
	return false;
}

// Compare two strings (case-insensitive)
bool Compare(const string& str1, const string& str2)
{
	return ((str1.size() == str2.size()) &&
		std::equal(str1.begin(), str1.end(), str2.begin(), &compareChar));
}

// Split input by ' '
void ParseInput(const string& line, vector<string>& arguments)
{
	const char* str = line.c_str();

	do
	{
		const char *begin = str;

		while (*str != ' ' && *str)
			str++;

		arguments.push_back(string(begin, str));
	} while (0 != *str++);
}

string GetHelp() {
	return (
		"List of commands : \n"
		"----------------------\n"
		"> look --> General look\n"
		"> look <entity> --> Look the object <entity>"
		"(Ex: look garden --> Look all the entities from the Garden)\n"
		"> stats --> Show the stats from the player \n"
		"> inventory --> Show inventory from the player \n"
		"> go <somewhere> --> Go to the indicated room \n"
		"> pick <item> --> Take the item and put it to the inventory\n"
		"> pick <item> to <place> --> Take the item and put it to the place "
		"(Ex: pick letter to bag)\n"
		"> drop <item> --> Drop item to current Room\n"
		"> drop <item> from <place> --> Drop item from place to current Room "
		"(Ex: drop letter from bag)\n"
		"> equip <item> --> Equip item that is in the inventory\n"
		"> equip <item> from <place> --> Equip item from place that"
		"is in that place (Ex: equip sword from bag)\n"
		"> unequip <item> --> Unequip item equipped before\n"
		"> inspect <item> --> Show info from item picked\n"
		"> attack <creature> --> Attack creature from the room\n"
		"> unlock <room> with <item> --> Unlock the room with the"
		"item from the inventory\n"
		"----------------------\n");
}

string GetStory() {
	return("We are on 2020. This hospital has a virus (corona-shaped) that can cause global "
		"chaos. You're a secret agent. Your mission?\nTo recover that virus "
		"before it is too late. Take it back. Good Luck.");
}