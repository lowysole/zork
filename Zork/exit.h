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

	const string& GetRoomName(const Room* room);
	Room* GetRoomDestination(const Room* room);

	bool locked;
	bool blocked;
	string opposite_name;
	Room* destination;
	Entity* key;
	
};

#endif // __Exit__