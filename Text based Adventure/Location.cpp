#include "Location.h"

Location::Location()
{
	node = 0;
}

Location::Location(unsigned int node1)
{
	node = node1;
}

bool Location::operator== (const Location& other) const
{
	return(node == other.node);
}

bool Location::isInaccessible() const
{
	return (node == 0);
}

ostream& operator<<(ostream& out, const Location& location)
{
	out << "(node index = " << location.node << ")" << endl;
	return out;
}