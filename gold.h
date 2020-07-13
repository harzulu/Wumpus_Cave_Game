#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include "event.h"

using namespace std;

class Gold : public Event
{
	private:

	public:

		Gold();

		void at_gold();
};
#endif