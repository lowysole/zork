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

	string help = GetHelp();
	cout << description << endl;
	cout << "------------------" << endl;
	cout << GetStory() << endl;
	cout << "------------------" << endl;

	cout << "> ";

	World my_world;

	while (1)
	{
		getline(cin, player_input);
		ParseInput(player_input, args);
		cout << endl;

		if (args.size() > 0 && args[0] == "help")
			cout << help << endl;
		else if (args.size() > 0 && args[0] == "quit")
			break;

		else if (my_world.ParseCommand(args) == false)
			cout << "Sorry, I do not understand your command." << endl;

		else if (my_world.CheckVictory()) {
			cout << "------------------" << endl;
			cout << "Mission completed. " << endl;
			cout << "You've saved the virtual humanity. "
				"Please, come now to save the real world." << endl;
			break;
		}

		if (args.size() > 0)
		{
			args.clear();
			player_input = "";
			cout << "> ";
		}
	}

	cout << endl << "\nThanks for playing, Bye!" << endl;
	cout << "------------------" << endl;
	cout << "Credits: github@lowysole" << endl;

	getline(cin, player_input);
	return 0;
}