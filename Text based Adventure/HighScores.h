#ifndef HIGHSCORES_H
#define HIGHSCORES_H
#include<iostream>
#include<string>
#include<cassert>
#include<cstdlib>
#include<fstream>
using namespace std;

struct Element
{
	int score;
	string name;
	Element* next;
};
class HighScores
{
public:
	HighScores();
	HighScores(const string& game_name);
	HighScores(const HighScores& to_copy);
	~HighScores();
	HighScores& operator= (const HighScores& to_copy);
	void print() const;
	void save(const string& game_name) const;
	void insert(int score, const string& player_name);
private:
	Element* copyLinkedList(const Element* p_old_head) const;
	void destroyLinkedList(Element* p_head) const;
	void printToStream(ostream& out) const;
	string getFilename(const string& game_name) const;
	bool invariant() const;
	Element*head;
};


#endif