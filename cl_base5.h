#ifndef __CL_BASE5_H
#define __CL_BASE5_H
#include "cl_base.h"
#include <map>
#include <stack>

#define SIGNAL_D    (void (cl_base::*)(string&)) // макрос для упрощенного создания указателя на метода сигнала 
#define HENDLER_D  (void (cl_base:: *)(string&))// макрос для упрощенного создания указателя на метода обработчика

class cl_base5 : public cl_base
{
public:
	using cl_base::cl_base;
	void signal_1(string& t);
	void hendler_1(string& t);
	void hendler_2(string& t);

	multimap<char, bool> bool_per;	
	multimap<char, bool> ::iterator it;
	typedef pair <char, bool> p;
};
#endif

