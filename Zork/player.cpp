#include "player.h"

//Constructor
Player::Player(const char* name, const char* description, Room* location) :
	Creature(name, description, location) {
	creature_type = PLAYER;
	this->health = 10;
}

//Destructor
Player::~Player() {
}
