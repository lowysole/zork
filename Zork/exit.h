#ifndef __Exit__
#define __Exit__

#include "entity.h"

class Room;

class Exit: public Entity
{
public:
	Exit(const char* name, const char* opposite_name, const char* description, 
		Room* origin, Room* destination);
	~Exit();

	bool locked;
	string opposite_name;
	Room* destination;
	
};

#endif // __Exit__