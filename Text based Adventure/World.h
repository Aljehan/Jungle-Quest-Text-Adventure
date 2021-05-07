#ifndef WORLD_H
#define WORLD_H
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cassert>
#include "Location.h"
#include "ObstructedNode.h"
#include "Node.h"
using namespace std;

const int MAX_DESCRIPTION_COUNT = 1000;

class World
{
public:
	World();
	World(const string& game_name);
	/*
	World

	Purpose:it is to initialize a new world which passes a string by refrence
	Parameters:
	<1> game_name: name of the game to allow to call the load functions expressed as a string
	Preconditions:N/A
	Returns: N/A
	Side effects: Initializes the World by calling the loadNodes and loadDescripitions
	functions.
	*/

	World(const World& to_copy);
	/*
	World

	Purpose:to make a copy of the world
	Parameters:
	<1> to_copy: the world that will be copied
	Preconditions:N/A
	Returns: N/A
	Side effects: will create a copy for the user
	*/

	~World();
	/*
	~World

	Purpose:to destroy all dynamically allocated memory
	Parameters:N/A
	Preconditions:N/A
	Returns: N/A
	Side effects: delets all dynamically allocated memory
	*/

	World& operator= (const World& to_copy);
	/*
	operator= 

	Purpose: to be able to use the = operator to compare two worlds
	Parameters:
	<1> to_copy: the world that will be copied
	Preconditions:N/A
	Returns: N/A
	Side effects: will delete the allocated memory and create a new copy of it
	*/

	void debugPrint() const;
	/*
	debugPrint

	Purpose: to print out the current values to see if there are any errors
	Parameters:N/A
	Preconditions:N/A
	Returns:N/A
	Side effects: Will print out on the console the layout of the nodes and
	every description out

	*/
	Location getStart() const;
	/*
	getStart

	Purpose: to find the starting location and return that value
	Parameters:N/A
	Preconditions:N/A
	Returns: The Location of which equals to the starting node
	Side effects: N/A

	*/
	bool isValid(const Location& location) const;
	/*
	isValid

	Purpose: to check if the current location isValid to move to
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: True or False
	Side effects: N/A
	*/
	void printDescription(const Location& location) const;
	/*
	printDescription

	Purpose: to print the description of the current location
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: N/A
	Side effects:
	*/
	bool canGoNorth(const Location& location) const;
	/*
	canGoNorth

	Purpose: to check if from the current location it can go north
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: True or False
	Side effects: N/A
	*/
	bool canGoSouth(const Location& location) const;
	/*
	canGoSouth

	Purpose: to check if from the current location it can go south
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: True or False
	Side effects: N/A
	*/
	bool canGoEast(const Location& location) const;
	/*
	canGoNorth

	Purpose: to check if from the current location it can go east
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: True or False
	Side effects: N/A
	*/
	bool canGoWest(const Location& location) const;
	/*
	canGoNorth

	Purpose: to check if from the current location it can go west
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: True or False
	Side effects: N/A
	*/
	Location getNorth(const Location& location) const;
	/*
	getNorth

	Purpose: to check if from the current location it can go north and then retrive the location needed to go north
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: a Location
	Side effects: N/A
	*/
	Location getSouth(const Location& location) const;
	/*
	getSouth

	Purpose: to check if from the current location it can go south and then retrive the location needed to go south
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: a Location
	Side effects: N/A
	*/
	Location getEast(const Location& location) const;
	/*
	getEast

	Purpose: to check if from the current location it can go east and then retrive the location needed to go east
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: a Location
	Side effects: N/A
	*/
	Location getWest(const Location& location) const;
	/*
	getWest

	Purpose: to check if from the current location it can go west and then retrive the location needed to go west
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: a Location
	Side effects: N/A
	*/
	bool isDeath(const Location& location) const;
	/*
	isDeath

	Purpose: will compare the current location to se if it is death
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: True or False
	Side effects: N/A
	*/
	bool isVictory(const Location& location) const;
	/*
	isVictory

	Purpose: will compare the current location to se if it is victory
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: True or False
	Side effects: N/A
	*/
	bool isObstructed(const Location& location) const;
	/*
	isObstructed

	Purpose: will check to see if the current node is an obstructed node
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: True or False
	Side effects: N/A
	*/
	char getRequiredItem(const Location& location) const;
	/*
	getRequiredItem

	Purpose: will return the item id from the current location
	Parameters:
	<1> location: the current row and column which is expressed as a Location
	Preconditions:N/A
	Returns: char
	Side effects: N/A
	*/
	void printDescriptionFailure(const Location& location) const;
	/*
	printDescriptionFailure

	Purpose: to print out the failure description if you do not have the item 
	Parameters:N/A
	Preconditions:N/A
	Returns:N/A
	Side effects: Will print out on the console the failure description
	*/
	void printDescriptionSuccess(const Location& location) const;
	/*
	printDescriptionSuccess

	Purpose: to print out the success description if you do have the item
	Parameters:N/A
	Preconditions:N/A
	Returns:N/A
	Side effects: Will print out on the console the success description
	*/
private:
	Node**Node_Array = new Node*;
	unsigned int VICTORY, START, NODE_COUNT;
	unsigned int DESCRIPTION_COUNT;
	string descriptions[MAX_DESCRIPTION_COUNT];
	void LoadNodes(const string& filename);
	/*
	LoadNodes

	Purpose: will load the the nodes used from the text file
	Parameters:
	<1> filename: name of the file that is used to call the nodes file and set them to the nodes array
	Preconditions:N/A
	Returns: N/A
	Side effects: nodes array gets values,
	*/
	void LoadDescriptions(const string& filename);
	/*
	LoadDescriptions

	Purpose: to load all the descriptions into the descriptions array
	Parameters:
	<1> filename: name of the file that is used to call the description file and set them to the description array
	Preconditions:N/A
	Returns: N/A
	Side effects: DESCRIPTION_COUNT gets a value, the descriptions arrays gets values
	*/
	bool invariant() const;
	/*
	invariant

	Purpose: checks certain characteristics to see if the code should end if the do not return true
	Parameters:N/A
	Preconditions:N/A
	Returns: True or False
	Side effects: N/A
	*/
};
#endif
