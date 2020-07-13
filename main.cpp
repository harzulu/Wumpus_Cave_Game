#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "event.h"
#include "room.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"

using namespace std;

int main(int argc, char* argv[])
{
	bool debug_mode;
	string cmd = argv[1];

	if (cmd == "True" || cmd == "true")
	{
		debug_mode = true;
	}
	else if (cmd == "False" || cmd == "false")
	{
		debug_mode = false;
	}
	else
	{
		cout << "Incorrect argument for debug mode. Remember 'True' or 'False'" << endl;
		return 1;
	}
	srand(time(NULL));
	Player p;
	p.menu(debug_mode);
}