#ifndef __Room__
#define __Room__

#include <string>
#include "entity.h"

using namespace std;

class Exit;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();

	//void Look() const;
	//Exit* GetExit(const string& description);
};

#endif // __Room__
