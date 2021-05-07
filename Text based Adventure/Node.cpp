#include "Node.h"



Node::Node()
{
	description = 0;
	north = 0;
	south = 0;
	east = 0;
	west = 0;
	death = 0;
}

Node::Node(unsigned int description1, unsigned int north1, unsigned int south1, unsigned int east1, unsigned int west1, bool is_death1)
{
	description = description1;
	north = north1;
	south = south1;
	east = east1;
	west = west1;
	death = is_death1;
}

Node::Node(const Node& to_copy)
{
	description = to_copy.description;
	north = to_copy.north;
	south = to_copy.south;
	east = to_copy.east;
	west = to_copy.west;
	death = to_copy.death;
}

Node::~Node()
{

}

Node& Node::operator= (const Node& to_copy)
{
	if (&to_copy != this)
	{
		description = to_copy.description;
		north = to_copy.north;
		south = to_copy.south;
		east = to_copy.east;
		west = to_copy.west;
		death = to_copy.death;
	}
	return *this;
}

void Node::debugPrint() const
{
	char dNode;
	if (death == 1)
	{
		dNode = 'D';
	}
	else
	{
		dNode = 'N';
	}

	cout << dNode << setw(5) << description << setw(5) << north << setw(5) << south << setw(5) << east << setw(5) << west << endl;
}

Node* Node::getClone() const
{
	Node toCopy(description, north, south, east, west, death);
	Node* pN = new Node(toCopy);
	return pN;
}


unsigned int Node::getDescription() const
{
	return description;
}

bool Node::is_death() const
{
	return death;
}

Location Node::getNorth() const
{
	return north;
}

Location Node::getSouth() const
{
	return south;
}

Location Node::getEast() const
{
	return east;
}

Location Node::getWest() const
{
	return west;
}

bool Node::isObstructed() const
{
	return false;
}

char Node::getRequiredItem() const
{
	assert(isObstructed());
	return REQUIRED_ITEM_NOT_SET;
}

unsigned int Node::getDescriptionFailure() const
{
	assert(isObstructed());
	return 0;
}
unsigned int Node::getDescriptionSuccess() const
{
	assert(isObstructed());
	return 0;
}