#include "World.h"

World::World()
{

}

World::World(const string& game_name)
{
	Node_Array = NULL;
	LoadNodes(game_name + "_nodes.txt");
	LoadDescriptions(game_name + "_text.txt");
	assert(invariant());
}

World::World(const World& to_copy)
{
	Node *p_original = to_copy.Node_Array[NODE_COUNT];
	Node* p_copy = p_original->getClone();
}

World::~World()
{
	for (unsigned int i = 0; i < NODE_COUNT; i++)
	{
		delete Node_Array[i];
	}

	delete[] Node_Array;
}

World& World::operator= (const World& to_copy)
{
	if (&to_copy != this)
	{
		for (unsigned int i = 0; i < NODE_COUNT; i++)
		{
			delete Node_Array[i];
		}

		delete[] Node_Array;

		Node *p_original = to_copy.Node_Array[NODE_COUNT];
		Node* p_copy = p_original->getClone();
	}
	
	return *this;
}

void World::LoadNodes(const string& filename)
{
	assert(Node_Array == NULL);
	ifstream input;
	input.open(filename.c_str());

	if (input.fail())
	{
		cout << "File " << filename << " could not be opened." << endl;
		exit(1);
	}

	char Nodeletter, item;
	unsigned int description, north, south, east, west, descriptionFailure, descriptionSuccess;
	bool deathletter, objectletter;
	input >> NODE_COUNT;
	input >> START;
	input >> VICTORY;

	Node_Array = new Node*[NODE_COUNT];
	for (unsigned int i = 0; i < NODE_COUNT; i++)
	{
		input >> Nodeletter;
		if (Nodeletter == 'D')
		{
			deathletter = true;
			objectletter = false;

			input >> description >> north >> south >> east >> west;
			Node_Array[i] = new Node(description, north, south, east, west, deathletter);
		}
		else if (Nodeletter == 'O')
		{
			objectletter = true;
			deathletter = false;

			input >> description >> north >> south >> east >> west >> item >> descriptionFailure >> descriptionSuccess;
			Node_Array[i] = new ObstructedNode(description, north, south, east, west, item, descriptionFailure, descriptionSuccess);
		}
		else if (Nodeletter == 'N')
		{
			deathletter = false;
			objectletter = false;

			input >> description >> north >> south >> east >> west;
			Node_Array[i] = new Node(description, north, south, east, west, deathletter);
		}
		else
		{
		}
	}
}

void World::LoadDescriptions(const string& filename)
{
	unsigned int count;
	string holder, ignore;
	ifstream input;

	input.open(filename.c_str());

	if (input.fail())
	{
		cout << "File " << filename << " could not be opened." << endl;
		exit(2);
	}

	input >> DESCRIPTION_COUNT;

	getline(input, ignore);
	getline(input, holder);
	descriptions[0] = holder;
	count = 0;

	while (input.good() && count < DESCRIPTION_COUNT)
	{
		string line;;

		if (descriptions[count] == "")
		{
			getline(input, line);
			descriptions[count] += line + "\n";

			do
			{
				getline(input, line);
				if (line.length() > 0)
				{
					descriptions[count] += (line + "\n");
				}
			} while (line != "");
			count++;
		}
		else
		{
			count++;
			if (count < DESCRIPTION_COUNT)
			{
				descriptions[count] = "";
			}

		}
	}
}

void World::debugPrint() const
{
	cout << NODE_COUNT << endl;
	cout << START << "  " << VICTORY << endl;

	for (unsigned int i = 0; i < NODE_COUNT; i++)
	{
		Node_Array[i]->debugPrint();
	}

	unsigned int count = 0;
	while (count < DESCRIPTION_COUNT)
	{
		cout << count << ". " << descriptions[count] << endl;
		count++;
	}

}

Location World::getStart() const
{
	return START;
}

bool World::isValid(const Location& location) const
{
	return(location.node < NODE_COUNT);
}

void World::printDescription(const Location& location) const
{
	assert(invariant());
	if (isValid(location))
	{
		cout << descriptions[Node_Array[location.node]->getDescription()] << endl;
	}
}

bool World::canGoNorth(const Location& location) const
{
	assert(invariant());
	Location tLocation(Node_Array[location.node]->getNorth());
	return (!(tLocation.isInaccessible()));
}

bool World::canGoSouth(const Location& location) const
{
	assert(invariant());
	Location tLocation(Node_Array[location.node]->getSouth());
	return (!(tLocation.isInaccessible()));
}

bool World::canGoEast(const Location& location) const
{
	assert(invariant());
	Location tLocation(Node_Array[location.node]->getEast());
	return (!(tLocation.isInaccessible()));
}

bool World::canGoWest(const Location& location) const
{
	assert(invariant());
	Location tLocation(Node_Array[location.node]->getWest());
	return (!(tLocation.isInaccessible()));
}

Location World::getNorth(const Location& location) const
{
	assert(invariant());
	if (canGoNorth(location))
	{
		Location tLocation(Node_Array[location.node]->getNorth());
		return tLocation;
	}
	else
	{
		return location;
	}
}
Location World::getSouth(const Location& location) const
{
	assert(invariant());
	if (canGoSouth(location))
	{
		Location tLocation(Node_Array[location.node]->getSouth());
		return tLocation;
	}
	else
	{
		return location;
	}
}
Location World::getEast(const Location& location) const
{
	assert(invariant());
	if (canGoEast(location))
	{
		Location tLocation(Node_Array[location.node]->getEast());
		return tLocation;
	}
	else
	{
		return location;
	}
}
Location World::getWest(const Location& location) const
{
	assert(invariant());
	if (canGoWest(location))
	{
		Location tLocation(Node_Array[location.node]->getWest());
		return tLocation;
	}
	else
	{
		return location;
	}
}

bool World::isDeath(const Location& location) const
{
	assert(invariant());
	return (Node_Array[location.node]->is_death());
}

bool World::isVictory(const Location& location) const
{
	assert(invariant());
	return ((location.node == VICTORY));
}

bool World::isObstructed(const Location& location) const
{
	return (Node_Array[location.node]->isObstructed());
}

char World::getRequiredItem(const Location& location) const
{
	assert(isObstructed(location));
	return (Node_Array[location.node]->getRequiredItem());
}

void World::printDescriptionFailure(const Location& location) const
{
	assert(isObstructed(location));
	cout << descriptions[Node_Array[location.node]->getDescriptionFailure()] << endl;
}

void World::printDescriptionSuccess(const Location& location) const
{
	assert(isObstructed(location));
	cout << descriptions[Node_Array[location.node]->getDescriptionSuccess()] << endl;;
}

bool World::invariant() const
{
	if (DESCRIPTION_COUNT > MAX_DESCRIPTION_COUNT)
	{
		return false;
	}

	if (Node_Array == NULL)
	{
		return false;
	}

	for (unsigned int i = 0; i < NODE_COUNT; i++)
	{
		if (Node_Array[i] == NULL)
		{
			return false;
		}
	}
	for (unsigned int c = 0; c < NODE_COUNT; c++)
	{
		if (!(Node_Array[c]->getDescription() < DESCRIPTION_COUNT))
		{
			return false;
		}
	}

	for (unsigned int d = 0; d < DESCRIPTION_COUNT; d++)
	{
		if (descriptions[d] == "")
		{
			return false;
		}
	}

	if (START > NODE_COUNT)
	{
		return false;
	}

	if (VICTORY > NODE_COUNT)
	{
		return false;
	}

	return true;
}