#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "pit.h"

using namespace std;

Pit::Pit()
{

}

void Pit::at_pit()
{
	cout << "You fell through a pit!" << endl;
	exit(0);
}