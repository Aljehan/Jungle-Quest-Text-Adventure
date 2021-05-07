#ifndef LOCATION_H
#define LOCATION_H
#include<iostream>
#include<fstream>
using namespace std;

class Location
{
public:
	Location();
	Location(unsigned int node1);
	bool operator== (const Location& other) const;
	bool isInaccessible() const;
	unsigned int node;
};

ostream& operator<<(ostream& out, const Location& location);

#endif
