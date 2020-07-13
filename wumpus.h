#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include "event.h"

using namespace std;

class Wumpus : public Event
{
	private:

	public:

		Wumpus();

		int shoot_arrow(int direction, int p_row, int p_col);

		void at_wumpus();
};
#endif