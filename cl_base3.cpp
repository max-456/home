#include "cl_base3.h"
void cl_base3::signal_2(string& t) {
	t = t.erase(0, t.find(':') + 2);
	t = t + ' ';
}; // выдача сигнала на формирование множества логических переменных
void cl_base3::signal_1(string& t) {
	t = "Polish Notation: " + t;
}; // выдача сигнала на считывание строки логической функции 
void cl_base3::hendler_1(string& t) {
	while (t.size() > 1)
	{
		if (t.size() > 2)
		{
			op.push_back(t.substr(0, t.find(' ')));
			t.erase(0, t.find(' ') + 1);
		}
		else
		{
			op.push_back(t);
			op[op.size() - 1].erase(1, 1);
			t.clear();
		}
	}
};
void cl_base3::hendler_2(string& t) {
	t = "";
	bool flag = 0;
	stack <string> operation;
	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == "AND")
		{
			while (operation.empty() == 0 && (operation.top() == "AND" || operation.top() == "NOT"))
			{
				t = t + operation.top() + ' ';
				operation.pop();
			}
			operation.push(op[i]);
			flag = 1;
		}
		if (op[i] == "OR" || op[i] == "XOR")
		{
			while (operation.empty() == 0 && (operation.top() == "AND" || operation.top() == "NOT" || operation.top() == "XOR" || operation.top() == "OR"))
			{
				t = t + operation.top() + ' ';
				operation.pop();
			}
			operation.push(op[i]);
			flag = 1;
		}
		if (op[i] == "NOT")
		{
			while (operation.empty() == 0 && operation.top() == "NOT")
			{
				t = t + operation.top() + ' ';
				operation.pop();
			}
			operation.push(op[i]);
			flag = 1;
		}
		if (op[i] == "=>")
		{
			while (operation.empty() == 0 && operation.top() != "(" && operation.top() != "<=>")
			{
				t = t + operation.top() + ' ';
				operation.pop();
			}
			operation.push(op[i]);
			flag = 1;
		}
		if (op[i] == "<=>")
		{
			while (operation.empty() == 0 && (operation.top() != "("))
			{
				t = t + operation.top() + ' ';
				operation.pop();
			}
			operation.push(op[i]);
			flag = 1;
		}
		if (op[i] == "(")
		{
			operation.push(op[i]);
			flag = 1;
		}
		if (op[i] == ")")
		{
			while (operation.top() != "(")
			{
				t = t + operation.top() + ' ';
				operation.pop();
			}
			operation.pop();
			flag = 1;
		}
		if (flag == 0)
		{
			t = t + op[i] + ' ';
		}
		flag = 0;
	}
	while (!operation.empty())
	{
		t = t + operation.top() + " ";
		operation.pop();
	}
	t.erase(t.size() - 1, 1);
	op.clear();
	this->emit_signal(SIGNAL_D(&cl_base3::signal_1), t);
	this->emit_signal(SIGNAL_D(&cl_base3::signal_2), t);
};