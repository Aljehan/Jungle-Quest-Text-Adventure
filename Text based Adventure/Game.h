#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <cassert>
#include "World.h"
#include "Location.h"
#include "ItemManager.h"
using namespace std;

class Game
{
public:
	Game(const string& game_name);
	bool isOver() const;
	int getScore() const;
	void printDescription() const;
	void printInventory() const;
	void reset();
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void takeItem(char id);
	void leaveItem(char id);
private:
	void moveTo(const Location& location);
	bool invariant() const;
	World world;
	Location playerLocation;
	ItemManager storage;
};

#endif