#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <iomanip>
#include <cassert>
#include "Location.h"
using namespace std;

const char REQUIRED_ITEM_NOT_SET = '\0';

class Node
{
public:
	Node();
	Node(unsigned int description1, unsigned int north1, unsigned int south1, unsigned int east1, unsigned int west1, bool is_death1);
	Node(const Node& to_copy);
	virtual ~Node();
	Node& operator= (const Node& to_copy);
	virtual void debugPrint() const;
	virtual Node* getClone() const;
	unsigned int getDescription() const;
	Location getNorth() const;
	Location getSouth() const;
	Location getEast() const;
	Location getWest() const;
	bool is_death() const;
	virtual bool isObstructed() const;
	virtual char getRequiredItem() const;
	virtual unsigned int getDescriptionFailure() const;
	virtual unsigned int getDescriptionSuccess() const;
private:
	unsigned int description;
	unsigned int north, south, east, west;
	bool death;
};

#endif