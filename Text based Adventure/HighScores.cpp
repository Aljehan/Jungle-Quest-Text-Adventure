#include "HighScores.h"

HighScores::HighScores()
{
	head = NULL;
}

HighScores::HighScores(const string& game_name)
{
	int score1;
	string name1;
	ifstream input;
	head = NULL;
	input.open((getFilename(game_name)).c_str());
	
	if (input.fail())
	{
		ofstream output(getFilename(game_name).c_str());
		output.close();
	}

	do
	{
		input >> score1;
		input.ignore(1,'\t');
		getline(input, name1);

		if (name1 == "")
		{
			break;
		}
		

		insert(score1, name1);
	} while (!(input.eof()));

	input.close();
	assert(invariant());
}

HighScores::HighScores(const HighScores& to_copy)
{
	assert(to_copy.invariant());
	head = copyLinkedList(to_copy.head);
	assert(to_copy.invariant());
	assert(invariant());
}

HighScores::~HighScores()
{
	destroyLinkedList(head);
}
HighScores& HighScores::operator= (const HighScores& to_copy)
{
	assert(to_copy.invariant());
	assert(invariant());

	if (&to_copy != this) 
	{
		destroyLinkedList(head);

		head = copyLinkedList(to_copy.head);
	}

	assert(to_copy.invariant());
	assert(invariant());

	return *this;
}

void HighScores::print() const
{
	assert(invariant());
	cout << "HighScores:" << endl;
	printToStream(cout);
}

void HighScores::save(const string& game_name) const
{
	assert(invariant());
	ofstream output;
	output.open(getFilename(game_name).c_str());
	
	printToStream(output);
}

void HighScores::insert(int score, const string& player_name)
{
        assert(invariant());
	Element* currentElement = head;
	Element* prevElement = NULL;
	
	while ((currentElement != NULL) && (currentElement->score > score))
	{
		prevElement = currentElement;
		currentElement = currentElement->next;
	}
	
	Element* newElement = new Element;
	newElement->score = score;
	newElement->name = player_name;
	
	if (prevElement == NULL)
	{
	   newElement->next = head;
	   head = newElement;
	}
	else if(newElement->score >= prevElement->score)
	{
	   newElement->next = prevElement->next;
	   prevElement->next = newElement;
	}
	else if(prevElement->next == NULL)
	{
	   prevElement->next = newElement;
	   newElement->next = NULL;
	}
	else
	{
	   Element* pTemp = prevElement->next;
	   prevElement->next = newElement;
	   newElement->next = pTemp;
	}
	assert(invariant());
}

Element* HighScores::copyLinkedList(const Element* p_old_head) const
{
	if (p_old_head == NULL)
	{
		return NULL;
	}
	Element* p_new_head = new Element;
	p_new_head->name = p_old_head->name;
	p_new_head->score = p_old_head->score;

	Element *p_new_prev = p_new_head;
	const Element *p_old_prev = p_old_head;
	while (p_old_prev->next != NULL)
	{
		p_new_prev->next = new Element;

		p_new_prev = p_new_prev->next;
		p_old_prev = p_old_prev->next;

		p_new_prev->score = p_old_prev->score;
		p_new_prev->name = p_old_prev->name;
	}

	p_new_prev->next = NULL;

	return p_new_head;
}

void HighScores::destroyLinkedList(Element* p_head) const
{
	Element *p_current = NULL;
	Element *p_next = p_head;
	while (p_next != NULL)
	{
		p_current = p_next;
		p_next = p_current->next;
		delete p_current;
	}
}

void HighScores::printToStream(ostream& out) const
{
	Element* currentElement = head;
	while (currentElement != NULL)
	{
		if (currentElement->next == NULL)
		{
			out << currentElement->score << '\t' << currentElement->name;
			currentElement = currentElement->next;
		}
		else
		{
			out << currentElement->score << '\t' << currentElement->name << endl;
			currentElement = currentElement->next;
		}
	}
}

string HighScores::getFilename(const string& game_name) const
{
	string fileName = game_name + "_highscores.txt";
	return fileName;
}

bool HighScores::invariant() const
{
	Element* currentElement = head;
	  
	if (currentElement == NULL)
	{
		return true;
	}
	
	Element* nextElement = currentElement->next;
	
	while (currentElement != NULL)
	{
		if (nextElement == NULL)
		{
		   return true;
		}
		else if (currentElement->score < nextElement->score)
		{
		   return false;
		}
		currentElement = currentElement->next;
		nextElement = currentElement->next;
	}
	return true;
}
