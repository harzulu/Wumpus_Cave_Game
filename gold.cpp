#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "gold.h"

using namespace std;

Gold::Gold()
{

}

void Gold::at_gold()
{
	cout << "You found the gold and didn't get eaten by the Wumpus!" << endl;
	exit(0);
}