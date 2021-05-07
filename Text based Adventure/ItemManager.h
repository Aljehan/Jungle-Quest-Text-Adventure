#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include<iostream>
#include<cassert>
#include<string>
#include<cstdlib>
#include "Location.h"
#include "Item.h"
using namespace std;



class ItemManager
{
public:
	ItemManager();
	ItemManager(const string& game_name);
	ItemManager(const ItemManager& to_copy);
	~ItemManager();
	ItemManager& operator= (const ItemManager& to_copy);
	int getScore() const;
	void printAtLocation(const Location& location) const;
	void printInventory() const;
	bool isInInventory(char id) const;
	void reset();
	void take(char id, const Location& player_location);
	void leave(char id, const Location& player_location);
private:
	void load(const string& filename);
	unsigned int item_count;
	Item*pStorage;
	unsigned int find(char id) const;
	void sort();
	bool invariant() const;
};

#endif