# Zork Console Game

This is a console game written with C++ using Visual Studio 2017 Community.
It's a Zork style game. You need to investigate the rooms of the game picking objects and deciphering the unknowns that the level raises.

### Story
We are on 2020. This hospital has a virus (corona-shaped) that can cause global chaos. You're a secret agent. Your mission? To recover that virus before it is too late. Take it back. Good Luck.


##  Instalation

## How to play

List of commands:

 -  Look
	 - `look`   --  General look
	 - `look <entity>`  --  Look the object entity
		 - Ex: `look garden`  -- Look all the entities from the Garden
 -  Stats
	 -  `stats` -- Show the stats from the player
 - Inventory
	 -  `inventory` -- Show inventory from the player
 - Go
	 - `go <place>` -- Go to the indicated place
 - Pick
	 - `pick <item>` -- Take the item from the room and put it to the inventory
	  - `pick <item> to <item>` -- Take the item and put it to other item
		  - Ex: `pick letter to bag` -- Take letter and put it to the bag
 - Drop
	 -  `drop <item>` --  Drop item to current room
	 - `drop <item> from <item>` --  Drop item from item to current room
		 - Ex: `drop letter from bag` 
 - Equip
	 -  `equip <item>` --  Equip item that is in the inventory
	 - `equip <item> from <item>` -- Equip item from place
		 - Ex: `equip sword from bag`  

 - Unequip
  	 - `unequip <item>` -- Unequip item equipped before
 - Inspect
  	 - `inspect <item>` -- Show info from item picked
 - Attack
	 - `attack <creature>` -- Attack creature from the room
 - Unlock
  	 - `unlock <room> with <item>` -- Unlock the door with the item
 - Help
	 - `help` - List the commands
 - Quit
	 - `quit` - Quit the game
	 
## How to finish the game

(Better experience) - Skip this part and try to play by yourself. Investigate each room, looking at your inventory and stats, picking and equipping the objects, and come back here if you need some help.

Instructions:

First, you need to go to the operations room, pick the Scalpel, and equip it. Go back to the elevator, kill the worker, and equip the protection. Now you will be able to kill the guard from the security room and pick the key that he will drop. Go back to the elevator, unlock the infirmary, enter it and pick the virus. Go back to the garden and you will complete the mission.

Commands (for Speed Run):

`go hall; go elevator; go operations; pick scalpel to bag; equip scalpel from bag; go elevator; attack worker; pick protection to bag; equip protection from bag; go hall; go security; attack guard; pick card; go hall; go elevator; unlock infirmary with card; go infirmary; pick virus to bag; go elevator; go hall; go garden;`

## Further developments
Some ideas for next developments are:
  - Have good and bad NPCs
  - Add conversations between Player and NPC to add value to this figure and clues
  - The player can lose combats and die
  - Add more rooms, items, and more complexity
  
  
### Credit
Llorenç Solé Franquesa ~ @lowysole.

GitHub: https://github.com/lowysole
