#include "ObstructedNode.h"

ObstructedNode::ObstructedNode() :Node()
{
	indiceSuccess = 0;
	indiceFailure = 0;
	itemId = REQUIRED_ITEM_NOT_SET;
}

ObstructedNode::ObstructedNode(unsigned int description1, unsigned int north1, unsigned int south1, unsigned int east1, unsigned int west1, char required_item1, unsigned int description_failure1, unsigned int description_success1): Node(description1, north1, south1, east1, west1, 0)
{
	itemId = required_item1;
	indiceSuccess = description_success1;
	indiceFailure = description_failure1;
}
ObstructedNode::ObstructedNode(const ObstructedNode& to_copy) :Node(to_copy)
{
	indiceSuccess = to_copy.indiceSuccess;
	indiceFailure = to_copy.indiceFailure;
	itemId = to_copy.itemId;
}

ObstructedNode::~ObstructedNode()
{

}

ObstructedNode& ObstructedNode::operator= (const ObstructedNode& to_copy)
{
	if (&to_copy != this)
	{
		Node::operator=(to_copy);
		indiceSuccess = to_copy.indiceSuccess;
		indiceFailure = to_copy.indiceFailure;
		itemId = to_copy.itemId;
	}

	return *this;
}

void ObstructedNode::debugPrint() const 
{
	cout << 'O' << setw(5) << getDescription() << setw(5) << getNorth() << setw(5) << getSouth() << setw(5) << getEast() << setw(5) << getWest() << setw(5) << itemId << setw(5) << indiceFailure << setw(5) << indiceSuccess << endl;
}

Node* ObstructedNode::getClone() const
{
	Node* pN = new ObstructedNode();
	return pN;
}

bool ObstructedNode::isObstructed() const
{
	return true;
}

char ObstructedNode::getRequiredItem() const
{
	assert(isObstructed());
	return itemId;
}

unsigned int ObstructedNode::getDescriptionFailure() const
{
	assert(isObstructed());
	return indiceFailure;
}

unsigned int ObstructedNode::getDescriptionSuccess() const
{
	assert(isObstructed());
	return indiceSuccess;
}