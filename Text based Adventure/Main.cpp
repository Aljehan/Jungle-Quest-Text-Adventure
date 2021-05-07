#include "Game.h"
#include "HighScores.h"

int main()
{
	string input, name;
	char quitinput = 'n';
	int finalPoints = 0;
	string Game_name = "jungle";
	Game game(Game_name);

	cout << "Welcome to Jungle Quest!" << endl;
	cout << "You recently obtained an old treasure map in mysterious" << endl;
	cout << "circumstances.  It showed the location of the Lost Jewel of" << endl;
	cout << "Leopold II, evil king of the Congo Free State.  And since you" << endl;
	cout << "have always wanted to be more like Indiana Jones, you have" << endl;
	cout << "mounted an expedition to find it." << endl;
	cout << "\n";

	cout << "Please enter your name" << endl;
	getline(cin, name);

	game.printDescription();

	do
	{
		cout << "Next? ";
		getline(cin, input);

		if (input == "")
		{
			cout << "Invalid Command!" << endl;
		}

		else if (input.at(0) == 'q' || input.at(0) == 'Q')
		{
			cout << "Are you sure you want to quit? ";

			getline(cin, input);
			if (input.at(0) == 'y' || input.at(0) == 'Y')
			{
				quitinput = 'y';
			}
		}

		else if (input.at(0) == 'n' || input.at(0) == 'N')
		{
			game.moveNorth();
		}

		else if (input.at(0) == 's' || input.at(0) == 'S')
		{
			game.moveSouth();
		}

		else if (input.at(0) == 'e' || input.at(0) == 'E')
		{
			game.moveEast();
		}

		else if (input.at(0) == 'w' || input.at(0) == 'W')
		{
			game.moveWest();
		}
		else if (input.at(0) == 't' || input.at(0) == 'T')
		{
			cout << "Take what? ";
			getline(cin, input);

			if (input == "")
			{
				cout << "Invalid item." << endl;
				break;
			}
			else
			{
				game.takeItem(input.at(0));
			}
		}
		else if (input.at(0) == 'l' || input.at(0) == 'L')
		{
			cout << "Leave what? ";
			getline(cin, input);

			if (input == "")
			{
				cout << "Invalid item." << endl;
				break;
			}
			else
			{
				game.leaveItem(input.at(0));
			}
		}

		else if (input.at(0) == 'i' || input.at(0) == 'I')
		{
			game.printInventory();
		}
		else if (input.at(0) == 'r' || input.at(0) == 'R')
		{
			cout << "Are you sure you want to reset? ";

			getline(cin, input);
			if (input.at(0) == 'y' || input.at(0) == 'Y')
			{
				finalPoints = game.getScore();
				cout << "In this game you scored " << finalPoints << " points." << endl;
				cout << endl;
				HighScores highscores(Game_name);
				highscores.insert(finalPoints, name);
				highscores.save(Game_name);
				highscores.print();

				game.reset();
				game.printDescription();
			}
		}
		else
		{
			cout << "Invalid Command!" << endl;
		}

	} while (!(game.isOver()) && (quitinput != 'y'));

	finalPoints = game.getScore();

	cout << "In this game you scored " << finalPoints << " points." << endl;
	HighScores highscores(Game_name);
	highscores.insert(game.getScore(), name);
	highscores.save(Game_name);
	highscores.print();
	cout << '\n';
	cout << "Thank you for playing Jungle Quest!" << endl;
	return 0;
}
