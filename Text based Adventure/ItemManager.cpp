#include "ItemManager.h"

const unsigned int NO_SUCH_ITEM = 999999999;

ItemManager::ItemManager()
{
	item_count = 0;
	pStorage = new Item[item_count];
	assert(invariant());
}

ItemManager::ItemManager(const string& game_name)
{
	pStorage = NULL;
	load(game_name + "_items.txt");
	sort();
	assert(invariant());
}

ItemManager::ItemManager(const ItemManager& to_copy)
{
	assert(to_copy.invariant());

	pStorage = new Item(*(to_copy.pStorage));

	for (unsigned int i = 0; i < item_count; i++)
	{
		pStorage[i] = to_copy.pStorage[i];
	}

	assert(to_copy.invariant());
	assert(invariant());
}

ItemManager::~ItemManager()
{
	delete [] pStorage;
}

ItemManager& ItemManager::operator= (const ItemManager& to_copy)
{
	assert(to_copy.invariant());
	assert(invariant());

	if (&to_copy != this)
	{
		delete pStorage;
		
		pStorage = new Item(*(to_copy.pStorage));

		for(unsigned int i = 0; i < item_count; i++)
		{
			pStorage[i] = to_copy.pStorage[i];		
		}

	}

	assert(to_copy.invariant());
	assert(invariant());

	return *this;
}

int ItemManager::getScore() const
{
	assert(invariant());
	int finalPoints = 0;
	for (unsigned int i = 0; i < item_count; i++)
	{
		finalPoints += pStorage[i].getPlayerPoints();
	}

	return finalPoints;
}

void ItemManager::printAtLocation(const Location& location) const
{
	assert(invariant());
	for (unsigned int i = 0; i < item_count; i++)
	{
		if (pStorage[i].isAtLocation(location))
		{
			pStorage[i].printDescription();
		}
	}
}

void ItemManager::printInventory() const
{
	assert(invariant());
	for (unsigned int i = 0, j = 0; i < item_count; i++)	// initialize a second variable j that when the first if statement is ever ran the second if will not
	{

		if (pStorage[i].isInInventory())
		{
			pStorage[i].printDescription();
			j++;
		}
		else if (j == 0 && i == item_count - 1)	// will only run if the first if statement never ran once and it checked the last item count
		{
			cout << "I really dont want to leave this place empty handed." << endl;
		}
	}
}

bool ItemManager::isInInventory(char id) const
{
	assert(invariant());

	unsigned int item_index = find(id);

	if (item_index == NO_SUCH_ITEM)
		return false;
	else
		return pStorage[item_index].isInInventory();
}

void ItemManager::reset()
{
	assert(invariant());
	for (unsigned int i = 0; i < item_count; i++)
	{
		pStorage[i].reset();
	}
	assert(invariant());
}

void ItemManager::take(char id, const Location& player_location)
{
	assert(invariant());
	for (unsigned int i = 0; i < item_count; i++)
	{
		if (pStorage[i].getId() == id && (pStorage[i].isAtLocation(player_location)))
		{
			pStorage[i].moveToInventory();
			break;
		}
		else
		{
			if (i < item_count - 1)
			{
				continue;
			}
			else
			{
				cout << "Invalid item." << endl;
			}
		}
	}
	assert(invariant());
}

void ItemManager::leave(char id, const Location& player_location)
{
	assert(invariant());
	for (unsigned int i = 0; i < item_count; i++)
	{
		if (pStorage[i].getId() == id && (pStorage[i].isInInventory()))
		{
			pStorage[i].moveToLocation(player_location);
			break;
		}
		else
		{
			if (i < item_count - 1)
			{
				continue;
			}
			else
			{
				cout << "Invalid item." << endl;
			}
		}
	}
	assert(invariant());
}

void ItemManager::load(const string& filename)
{
	ifstream input;
	input.open(filename.c_str());

	if (input.fail())
	{
		cout << "File " << filename << " could not be opened." << endl;
		exit(1);
	}

	int NMBofItems, locationNode, pointValue;
	char id;
	string worldDescription, inventoryDescription, blank;

	input >> NMBofItems;
	item_count = NMBofItems;

	pStorage = new Item[item_count];
	for (unsigned int i = 0; i < item_count; i++)
	{

		getline(input, blank);
		input >> id;
		input >> locationNode;
		input >> pointValue;
		getline(input, blank);
		getline(input, worldDescription);
		getline(input, inventoryDescription);
		
		pStorage[i].init(id, locationNode, pointValue, worldDescription, inventoryDescription);	
	}
}

unsigned int ItemManager::find(char id) const
{
	int low = 0;
	int high = item_count - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2; 

		if (id == pStorage[mid].getId())
		{
			return mid;
		}
		else if (id < pStorage[mid].getId())
		{
			high = mid - 1;
		}
		else 
		{
			low = mid + 1;
		}
	}

	return NO_SUCH_ITEM;
}

//Selection sort
void ItemManager::sort()
{
	unsigned int i, j, search_min;
	Item temp;

	for (i = 0; i < item_count; i++)
	{
		// Find index of smallest element in unsorted section
		search_min = i;
		for (j = i + 1; j < item_count; j++)
		{
			if (pStorage[j].getId() < pStorage[search_min].getId())
			{
				search_min = j;
			}
		}
		// Swap items at positions search_min and i
		temp = pStorage[search_min];
		pStorage[search_min] = pStorage[i];
		pStorage[i] = temp;
	}
}


bool ItemManager::invariant() const
{
	for (unsigned int i = 0; i < item_count; i++)
	{
		if (i != find(pStorage[i].getId()))
		{
			return false;
		}
	}
	if (pStorage == NULL)
	{
		return false;
	}
	for (unsigned int i = 0; i < item_count; i++)
	{
		for (unsigned int j = i + 1; j < item_count; j++)
		{
			if (pStorage[i].getId() > pStorage[j].getId())
			{
				return false;
			}
		}
	}
	return true;
}
	
