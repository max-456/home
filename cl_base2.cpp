#include "cl_base2.h"
void cl_base2::signal_1(string& t) {};
void cl_base2::hendler_1(string& t) {
	while ((t.find('=')) != -1)
	{
		t.erase(t.find('=') - 1, 3);
		if (t.find(' ') != -1)
			t.erase(t.find(' '), 1);
	}
	this->emit_signal(SIGNAL_D(&cl_base2::signal_1), t);
};