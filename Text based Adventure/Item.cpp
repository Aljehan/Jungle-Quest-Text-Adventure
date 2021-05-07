#include "Item.h"

Item::Item()
{
	id = ID_NOT_INITIALIZED;
	Location start_location();
	Location current_location();
	is_in_inventory = false;
	points = 0;
	world_description = "[Item not Initialized]";
	inventory_description = "[Item not Initialized]";
}

void Item::init(char id1, const Location& location, int points1, const string& world_description1, const string& inventory_description1)
{
	id = id1;
	start_location = Location(location.node);
	current_location = Location(location.node);
	is_in_inventory = 0;
	points = points1;
	world_description = world_description1;
	inventory_description = inventory_description1;
	assert(isInitialized());
}

void Item::debugPrint() const
{
	cout << "id: '" << id << "'" << endl;
	cout << "start_location:" << start_location << endl;
	cout << "current_location:" << current_location << endl;
	cout << "is_in_inventory: " << is_in_inventory << endl;
	cout << "points: " << points << endl;
	cout << "world_description: " << "\"" << world_description << "\"" << endl;
	cout << "inventory_description: " << "\"" << inventory_description << "\"" << endl;
}

bool Item::isInitialized() const
{
	assert(invariant());
	return (id != ID_NOT_INITIALIZED);
}
char Item::getId()const
{
	assert(invariant());
	return id;
}

bool Item::isInInventory() const
{
	assert(invariant());
	return (is_in_inventory);
}

bool Item::isAtLocation(const Location& location) const
{
	assert(invariant());
	if (isInInventory())
	{
		return false;
	}
	else if (current_location.node == location.node)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Item::getPlayerPoints() const
{
	assert(invariant());
	int Temppoints = 0;
	if (isInInventory())
	{
		Temppoints = points;
		return Temppoints;
	}
	else
	{
		return Temppoints;
	}
}

void Item::printDescription()const
{
	assert(invariant());
	if (isInInventory())
	{
		cout << inventory_description << endl;
	}
	else
	{
		cout << world_description << endl;
	}
}

void Item::reset()
{
	assert(invariant());
	current_location = start_location;
	is_in_inventory = 0;
	assert(invariant());
}

void Item::moveToInventory()
{
	assert(invariant());
	is_in_inventory = 1;
	assert(invariant());
}

void Item::moveToLocation(const Location& location)
{
	assert(invariant());
	is_in_inventory = 0;
	current_location = location;
	assert(invariant());
}

bool Item::operator< (const Item& other) const
{
	assert(invariant());
	return (id < other.id);
}

bool Item::invariant() const
{
	return(world_description != "" && inventory_description != "");
}