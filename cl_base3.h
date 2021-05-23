#ifndef __CL_BASE3_H
#define __CL_BASE3_H
#include "cl_base.h"
#include <stack>

#define SIGNAL_D    (void (cl_base::*)(string&)) // макрос для упрощенного создания указателя на метода сигнала 
#define HENDLER_D  (void (cl_base:: *)(string&))// макрос для упрощенного создания указателя на метода обработчика

class cl_base3 : public cl_base
{
public:
	using cl_base::cl_base;
	vector <string> op;

	void signal_2(string& t);
	void signal_1(string& t);

	void hendler_1(string& t);
	void hendler_2(string& t);
};
#endif
