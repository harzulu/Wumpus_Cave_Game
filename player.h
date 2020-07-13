#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "event.h"
#include "room.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"

using namespace std;

class Player
{
	private:
		int p_row;
		int p_col;
		int arrows;
		int shot;
		char choice;
		bool turn;
		bool debug;
		int alive;

		Room r;

	public:

		Player();

		void menu(bool debug);

		void player_move(char direction);

		void if_at_wall();
};
#endif