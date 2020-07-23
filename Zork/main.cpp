#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "utils.h"
#include "world.h"

using namespace std;

int main()
{
	string player_input = "";
	vector<string> args;
	args.reserve(5);

	cout << "Welcome to MyZork!" << endl;
	cout << "------------------" << endl;

	string description = "Type 'help' to show all the commands or 'quit' to close the game";

	string help = "List of commands:";
	cout << description << endl;
	cout << "------------------" << endl;
	cout << "> ";

	World my_world;

	while (1)
	{
		cin >> player_input;
		ParseInput(player_input, args);
		cout << args[0];
		if (args.size() > 0 && args[0] == "help")
			cout << help << endl;
		else if (args.size() > 0 && args[0] == "quit")
			break;

		if (my_world.ParseArgs(args) == false)
			cout << "\nSorry, I do not understand your command.\n";

		if (args.size() > 0)
		{
			args.clear();
			player_input = "";
			cout << "> ";
		}
	}

	cout << "\nThanks for playing, Bye!" << endl;
	return 0;
}