#ifndef __CL_APPLICATION_H
#define __CL_APPLICATION_H
#include "cl_base.h"
#include "cl_base2.h"
#include "cl_base3.h"
#include "cl_base4.h"
#include "cl_base5.h"

#define SIGNAL_D    (void (cl_base::*)(string&)) // макрос для упрощенного создания указателя на метода сигнала 
#define HENDLER_D  (void (cl_base:: *)(string&))// макрос для упрощенного создания указателя на метода обработчика

class cl_application : public cl_base // наследование от класса cl_base
{
public:
	cl_application(cl_base* p_parent) : cl_base(p_parent, "input") {};

	void bild_tree(); // построение дерева иерархии
	int exec_app(); // запуск \приложения 

	void signal_4(string& t);
	void signal_3(string& t);
	void signal_2(string& t);
	void signal_1(string& t);
};
#endif