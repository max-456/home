#ifndef __CL_BASE2_H
#define __CL_BASE2_H
#include "cl_base.h"

#define SIGNAL_D    (void (cl_base::*)(string&)) // ������ ��� ����������� �������� ��������� �� ������ ������� 
#define HENDLER_D  (void (cl_base:: *)(string&))// ������ ��� ����������� �������� ��������� �� ������ �����������

class cl_base2 : public cl_base
{
public:
	using cl_base::cl_base;
	void signal_1(string& t);
	void hendler_1(string& t);
};
#endif
