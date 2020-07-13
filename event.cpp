#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include "event.h"


using namespace std;

Event::Event()
{

}

void Event::rand_location()
{
	row = 1 + rand() % 5;
	col = 1 + rand() % 5;
}

bool operator== (const Event &e1, const Event &e2) 
{ 
	if (e1.row == e2.row && e1.col == e2.col)
	{
		return true;
	}
	else
		return false;
} 