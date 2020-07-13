#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include "player.h"
#include "room.h"

using namespace std;

Player::Player()
{
	p_row = (rand() % 5) + 1;
	p_col = (rand() % 5) + 1;

	arrows = 3;
	shot = 0;
	choice = 9;
	turn = true;
	debug = false;
	alive = 0;
}

void Player::menu(bool mode)
{
	debug = mode;

	cout << "Welcome to Wumpus!" << endl;
	cout << "Here is your map:" << endl;
	r.w_rand();
	r.g_rand();
	r.b_rand();
	r.p_rand();
	
	r.make_map(p_row, p_col, debug);

	r.near_event(p_row, p_col);

	while (turn == true)
	{
		cout << "What would you like to do?" << endl;
		cout << "w,a,s,d to move rooms" << endl;
		cout << "Press '1' to shoot an arrow" << endl;
		cout << "Press 'q' to quit the game " << endl;
		cout << " " << endl;
		cin >> choice;

		if (choice == 'w' || choice == 'a' || choice == 's' || choice == 'd')
		{
			player_move(choice);
		}

		else if (choice == '1')
		{
			if (arrows == 0)
			{
				cout << "You are all out of arrows. .." << endl;
			}

			else
			{
				while (shot == 0)
				{
					cout << "Which way do you want to shoot an arrow? (w,a,s,d) " << endl;
					cin >> choice;

					if (choice == 'w' || choice == 'a' || choice == 's' || choice == 'd')
					{
						r.arrow_shot(choice, p_row, p_col);
						arrows -= 1;
						shot = 1;
					}
					else
					{
						cout << "Invalid choice... Try again: " << endl;
						shot = 0;
					}
				}
				shot = 0;
			}
		}

		else if (choice == 'q')
		{
			exit(0);
		}

		else
		{
			cout << "Invalid choice. Try again: " << endl;
		}
		cout << " " << endl;
	}
}

void Player::player_move(char direction)
{
	if (direction == 'w'){
		p_row -= 1;
		if_at_wall();
	}

	else if (direction == 'a'){
		p_col -= 1;
		if_at_wall();
	}

	else if (direction == 's'){
		p_row += 1;
		if_at_wall();
	}

	else if (direction == 'd'){
		p_col += 1;
		if_at_wall();
	}

	else
		cout << "ERROR" << endl;

	r.print_map(p_row, p_col);
	r.near_event(p_row, p_col);
	alive = r.if_on_event(p_row, p_col);

	if (alive == 1)
	{
		srand(time(NULL));
		p_row = (rand() % 5) + 1;
		p_col = (rand() % 5) + 1;
	}
	else
		cout << "";
}

void Player::if_at_wall()
{
	if (p_row > 5){
		p_row -= 1;
		cout << "You can't go in that direction. Try again." << endl;
	}

	else if (p_row < 1){
		p_row += 1;
		cout << "You can't go in that direction. Try again." << endl;
	}

	else if (p_col > 5){
		p_col -= 1;
		cout << "You can't go in that direction. Try again." << endl;
	}

	else if (p_col < 1){
		p_col += 1;
		cout << "You can't go in that direction. Try again." << endl;
	}

	else{
		cout << "";
	}
}