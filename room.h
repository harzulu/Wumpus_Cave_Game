#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"

using namespace std;

class Room
{
	private:

		bool debug;
		int shot;

		Wumpus w;
		Gold g;
		Bats b;
		Pit p;

	public:

	Room();

	void make_map(int p_row, int p_col, bool bug);

	void w_rand();

	void g_rand();

	void b_rand();

	void p_rand();

	void check_overlap_w(int p_row, int p_col);

	void check_overlap_g(int p_row, int p_col);

	void check_overlap_b(int p_row, int p_col);

	void check_overlap_p(int p_row, int p_col);

	void print_map(int p_row, int p_col);

	void near_event(int p_row, int p_col);

	int if_on_event(int p_row, int p_col);

	void arrow_shot(char choice, int p_row, int p_col);
};
#endif