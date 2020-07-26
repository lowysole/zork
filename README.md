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
   
  
### Credit
Llorenç Solé Franquesa ~ @lowysole. 
GitHub: https://github.com/lowysole
