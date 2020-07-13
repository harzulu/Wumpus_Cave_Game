#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include "room.h"

using namespace std;

Room::Room()
{
	debug = false;
	shot = 0;
}

void Room::make_map(int p_row, int p_col, bool bug)
{
	debug = bug;

	check_overlap_w(p_row, p_col);
	check_overlap_g(p_row, p_col);
	check_overlap_b(p_row, p_col);
	check_overlap_p(p_row, p_col);

	print_map(p_row, p_col);
}

void Room::w_rand()
{
	w.rand_location();
}

void Room::g_rand()
{
	g.rand_location();
}

void Room::b_rand()
{
	b.rand_location();
}

void Room::p_rand()
{
	p.rand_location();
}

void Room::check_overlap_w(int p_row, int p_col)
{
	if (w.row == p_row && w.col == p_col)
	{
		w.rand_location();
	}
	else
		return;
}

void Room::check_overlap_g(int p_row, int p_col)
{

	if (g.row == p_row && g.col == p_col)
	{
		g.rand_location();
	}
	else if (g == w)
	{
		g.rand_location();
		check_overlap_g(p_row, p_col);
	}
	else
		return;
}

void Room::check_overlap_b(int p_row, int p_col)
{

	if (b.row == p_row && b.col == p_col)
	{
		b.rand_location();
	}
	else if (b == w)
	{
		b.rand_location();
		check_overlap_b(p_row, p_col);
	}
	else if (b == g)
	{
		b.rand_location();
		check_overlap_b(p_row, p_col);
	}
	else
		return;
}

void Room::check_overlap_p(int p_row, int p_col)
{

	if (p.row == p_row && p.col == p_col)
	{
		p.rand_location();
	}
	else if (p == w)
	{
		p.rand_location();
		check_overlap_p(p_row, p_col);
	}
	else if (p == g)
	{
		p.rand_location();
		check_overlap_p(p_row, p_col);
	}
	else if (p == b)
	{
		p.rand_location();
		check_overlap_p(p_row, p_col);
	}
	else 
		return;
}

void Room::print_map(int p_row, int p_col)
{
		if (debug == true)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "-----------" << endl;
			for (int j = 0; j < 6; j++)
			{
				if (p_row == i + 1 && p_col == j + 1)
					cout << "|*";
				else if (w.row == i + 1 && w.col == j + 1)
					cout << "|W";
				else if (g.row == i + 1 && g.col == j + 1)
					cout << "|G";
				else if (b.row == i + 1 && b.col == j + 1)
					cout << "|B";
				else if (p.row == i + 1 && p.col == j + 1)
					cout << "|P";
				else
					cout << "| ";
			}
			cout << endl;
		}
		cout << "-----------" << endl;
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "-----------" << endl;
			for (int j = 0; j < 6; j++)
			{
				if (p_row == i + 1 && p_col == j + 1)
					cout << "|*";

				else
					cout << "| ";
			}
			cout << endl;
		}
		cout << "-----------" << endl;
	}

}

void Room::near_event(int p_row, int p_col)
{
	if (p_row + 1 == w.row && p_col == w.col)
	{
		cout << "You smell a terrible stench..." << endl;
	}

	else if (p_col + 1 == w.col && p_row == w.row)
	{
		cout << "You smell a terrible stench..." << endl;
	}

	else if (p_col - 1 == w.col && p_row == w.row)
	{
		cout << "You smell a terrible stench..." << endl;
	}

	else if (p_row - 1 == w.row && p_col == w.col)
	{
		cout << "You smell a terrible stench..." << endl;
	}

	else if (p_row + 1 == g.row && p_col == g.col)
	{
		cout << "You see a glimmer nearby..." << endl;
	}

	else if (p_col + 1 == g.col && p_row == g.row)
	{
		cout << "You see a glimmer nearby..." << endl;
	}

	else if (p_col - 1 == g.col && p_row == g.row)
	{
		cout << "You see a glimmer nearby..." << endl;
	}

	else if (p_row - 1 == g.row && p_col == g.col)
	{
		cout << "You see a glimmer nearby..." << endl;
	}

	else if (p_row + 1 == b.row && p_col == b.col)
	{
		cout << "You hear wings flapping..." << endl;
	}

	else if (p_col + 1 == b.col && p_row == b.row)
	{
		cout << "You hear wings flapping..." << endl;
	}

	else if (p_col - 1 == b.col && p_row == b.row)
	{
		cout << "You hear wings flapping..." << endl;
	}

	else if (p_row - 1 == b.row && p_col == b.col)
	{
		cout << "You hear wings flapping..." << endl;
	}

	else if (p_row + 1 == p.row && p_col == p.col)
	{
		cout << "You feel a breeze..." << endl;
	}

	else if (p_col + 1 == p.col && p_row == p.row)
	{
		cout << "You feel a breeze..." << endl;
	}

	else if (p_col - 1 == p.col && p_row == p.row)
	{
		cout << "You feel a breeze..." << endl;
	}

	else if (p_row - 1 == p.row && p_col == p.col)
	{
		cout << "You feel a breeze..." << endl;
	}

	else
		return;
}

int Room::if_on_event(int p_row, int p_col)
{
	if (p_row == g.row && p_col == g.col)
	{
		g.at_gold();
		return 0;
	}

	else if (p_row == w.row && p_col == w.col)
	{
		w.at_wumpus();
		return 0;
	}

	else if (p_row == b.row && p_col == b.col)
	{
		b.at_bats();
		b.row = 10;
		b.col = 10;

		return 1;
	}

	else if (p_row == p.row && p_col == p.col)
	{
		p.at_pit();
		return 0;
	}
	else
		return 0;
}

void Room::arrow_shot(char choice, int p_row, int p_col)
{
	shot = w.shoot_arrow(choice, p_row, p_col);

	if (shot == 1)
	{
		w.row = 10;
		w.col = 10;
		print_map(p_row, p_col);
		return;
	}
	else if (shot == 2)
	{
		print_map(p_row, p_col);
		return;
	}
	else if (shot == 3)
	{
		print_map(p_row, p_col);
		w.rand_location();
	}
	else
	{
		print_map(p_row, p_col);
		return;
	}
}