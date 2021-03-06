#include "Game.h"

Game::Game(const string& game_name)
		: world(game_name),
		storage(game_name),
		playerLocation(world.getStart())
	{
		assert(invariant());
	}

bool Game::isOver() const
{
	assert(invariant());
	if (world.isDeath(playerLocation))
	{
		return true;
	}
	else if (world.isVictory(playerLocation))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::printDescription() const
{
	assert(invariant());
	world.printDescription(playerLocation);
	storage.printAtLocation(playerLocation);
}

int Game::getScore() const
{
	assert(invariant());
	return (storage.getScore());
}

void Game::printInventory() const
{
	assert(invariant());
	storage.printInventory();
}

void Game::moveNorth()
{
	assert(invariant());
	if (world.canGoNorth(playerLocation))
	{
		moveTo(world.getNorth(playerLocation));
	}
	else
	{
		cout << "There is no way to go in that direction" << endl;
	}
	assert(invariant());
}

void Game::moveSouth()
{
	assert(invariant());
	if (world.canGoSouth(playerLocation))
	{
		moveTo(world.getSouth(playerLocation));
	}
	else
	{
		cout << "There is no way to go in that direction" << endl;
	}
	assert(invariant());
}

void Game::moveEast()
{
	assert(invariant());
	if (world.canGoEast(playerLocation))
	{
		moveTo(world.getEast(playerLocation));
	}
	else
	{
		cout << "There is no way to go in that direction" << endl;
	}
	assert(invariant());
}

void Game::moveWest()
{
	assert(invariant());
	if (world.canGoWest(playerLocation))
	{
		moveTo(world.getWest(playerLocation));
	}
	else
	{
		cout << "There is no way to go in that direction" << endl;
	}
	assert(invariant());
}
void Game::takeItem(char id)
{
	assert(invariant());
	storage.take(id, playerLocation);
	assert(invariant());
}

void Game::leaveItem(char id)
{
	assert(invariant());
	storage.leave(id, playerLocation);
	assert(invariant());
}

void Game::reset()
{
	assert(invariant());
	playerLocation = world.getStart();
	storage.reset();
	assert(invariant());
}

void Game::moveTo(const Location& location)
{
	if (world.isObstructed(location))
	{
		if (world.isObstructed(playerLocation) && world.getRequiredItem(playerLocation)== world.getRequiredItem(location))
		{
			playerLocation = location;
			world.printDescription(playerLocation);
			storage.printAtLocation(playerLocation);
		}
		else if (storage.isInInventory(world.getRequiredItem(location)))
		{
			world.printDescriptionSuccess(location);
			playerLocation = location;
			world.printDescription(playerLocation);
			storage.printAtLocation(playerLocation);
		}
		else
		{
			world.printDescriptionFailure(location);
			world.printDescription(playerLocation);
			storage.printAtLocation(playerLocation);
		}	
	}
	else
	{
		playerLocation = location;
		world.printDescription(playerLocation);
		storage.printAtLocation(playerLocation);
	}
}
bool Game::invariant() const
{
	return(world.isValid(playerLocation));
}
