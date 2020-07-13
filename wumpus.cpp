#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "wumpus.h"

using namespace std;

Wumpus::Wumpus()
{

}

int Wumpus::shoot_arrow(int direction, int p_row, int p_col)
{

	if (direction == 'w' || direction == 's')
	{
		if (p_col == col)
		{
			cout << "You killed the Wumpus!" << endl;
			return 1;
		}
		else if (p_col + 1 == col || p_col - 1 == col)
		{
			cout << "You just missed the wumpus..." << endl;
			cout << "You hear distant movement..." << endl;
			return 3;
		}
		else
		{
			cout << "You didn't hit anything..." << endl;
			return 2;
		}
	}
	else if (direction == 'a' || direction == 'd')
	{
		if (p_row == row)
		{
			cout << "You killed the Wumpus!" << endl;
			return 1;
		}
		else if (p_row + 1 == row || p_row - 1 == row)
		{
			cout << "You just missed the wumpus..." << endl;
			cout << "You hear distant movement..." << endl;
			return 3;
		}
		else
		{
			cout << "You didn't hit anything..." << endl;
			return 2;
		}
	}
	else
	{
		cout << "Invalid input. Try again.." << endl;
		return 0;
	}
}

void Wumpus::at_wumpus()
{
	cout << "You got eaten by the Wumpus!" << endl;
	exit(0);
}