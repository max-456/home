#include "cl_base5.h"
void cl_base5::signal_1(string& t) {
	t = "Result: " + t;
}; 
void cl_base5::hendler_1(string& t) {
	string k = "";
	for (int i = 0; i < t.size() - 1; i += 2)
	{
		if (t[i + 1] == '0')
			bool_per.insert(p(t[i], 0));
		else
			bool_per.insert(p(t[i], 1));
	}
	it = bool_per.begin();
	while (it != bool_per.end())
	{
		k = k + it->first;
		if (it->second == 0)
		{
			k = k + " = false ";
		}
		else
			k = k + " = true ";
		it++;
	}
	t = k;
	t.erase(t.size() - 1);
};
void cl_base5::hendler_2(string& t) {
	stack <int> znachenie;
	bool flag = 0;
	bool a;
	bool b;
	while (t.size() > 0)
	{
		if (t.substr(0, t.find(' ')) == "NOT")
		{
			a = znachenie.top();
			znachenie.pop();
			znachenie.push(!a);
			flag = 1;
		}
		else
		{
			if (t[1] != ' ')
			{
				a = znachenie.top();
				znachenie.pop();
				b = znachenie.top();
				znachenie.pop();
				if (t.substr(0, t.find(' ')) == "XOR")
					znachenie.push(a && !b || !a && b);
				if (t.substr(0, t.find(' ')) == "AND")
					znachenie.push(a && b);
				if (t.substr(0, t.find(' ')) == "OR")
					znachenie.push(a || b);
				if (t.substr(0, t.find(' ')) == "=>")
					znachenie.push(!b || a);
				if (t.substr(0, t.find(' ')) == "<=>")
					znachenie.push(a && b || !a && !b);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			znachenie.push(bool_per.find(t[0])->second);
		}
		t.erase(0, t.find(' ') + 1);
		flag = 0;
	}
	if (znachenie.top() == 0)
		t = "false";
	else
		t = "true";
	bool_per.clear();
	this->emit_signal(SIGNAL_D(&cl_base5::signal_1), t);
};