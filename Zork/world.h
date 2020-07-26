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

public:
	World();
	~World();

	bool ParseCommand(vector<string>& args);
	bool CheckVictory();

};

#endif // __World__

