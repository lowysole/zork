#ifndef __World__
#define __World__

#include <string>
#include <list>
#include <vector>

using namespace std;

class Entity;
class Player;

class World 
{
private:
	list<Entity*> entities;
	Player* player;
	char* player_name;

public :	
	World();
	~World();

	bool ParseCommand(vector<string>& args);

};

#endif // __World__

