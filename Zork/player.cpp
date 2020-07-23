#include "player.h"

//Constructor
Player::Player(const char* name, const char* description, Entity* parent, Room* location) :
	Creature(name, description, parent, location) {
	creature_type = PLAYER;
	this->health = 10;
}

//Destructor
Player::~Player() {
}
