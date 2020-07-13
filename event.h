#ifndef EVENT_H
#define EVENT_H

#include <iostream>

using namespace std;

class Event
{
	private:

	public:
		int row;
		int col;

		Event();

		void rand_location();

		friend bool operator== (const Event &e1, const Event &e2);

};
#endif