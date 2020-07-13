#ifndef PIT_H
#define PIT_H

#include <iostream>
#include "event.h"

using namespace std;

class Pit : public Event
{
	private:

	public:

		Pit();

		void at_pit();
};
#endif