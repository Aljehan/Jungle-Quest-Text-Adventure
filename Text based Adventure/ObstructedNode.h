#ifndef OBSTRUCTEDNODE_H
#define OBSTRUCTEDNODE_H
#include "Node.h"
#include <cassert>
#include <iomanip>
#include <iostream>
using namespace std;

class ObstructedNode : public Node
{
public:
	ObstructedNode();
	ObstructedNode(unsigned int description1, unsigned int north1, unsigned int south1, unsigned int east1, unsigned int west1, char required_item1, unsigned int description_failure1, unsigned int description_success1);
	ObstructedNode(const ObstructedNode& to_copy);
	virtual ~ObstructedNode();
	ObstructedNode& operator= (const ObstructedNode& to_copy);
	virtual void debugPrint() const;
	virtual Node* getClone() const;
	virtual bool isObstructed() const;
	virtual char getRequiredItem() const;
	virtual unsigned int getDescriptionFailure() const;
	virtual unsigned int getDescriptionSuccess() const;
private:
	char itemId;
	unsigned int indiceSuccess;
	unsigned int indiceFailure;
};
#endif
