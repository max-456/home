#ifndef __CL_BASE_H
#define __CL_BASE_H
#include <iostream> 
#include <vector>
#include <string>
using namespace std;

#define SIGNAL_D    (void (cl_base::*)(string&))
#define HENDLER_D  (void (cl_base:: *)(string&))

class cl_base {
private:

	struct o_sh // структура для хранения связей сигнал-обработчик
	{
		cl_base* p_hendler; //указатель на объкт, принимающий сигнал
		void (cl_base::* hendler) (string&); //указатель на метод-обработчик
		void (cl_base::* signal)(string&); //указатель на метод-сигнал
		o_sh( cl_base* p_hendler, void (cl_base::* hendler) (string&), void (cl_base::* signal)(string&)) // конструктор
		{
			this->p_hendler = p_hendler;
			this->hendler = hendler;
			this->signal = signal;
		};
	};

	string object_name; // имя объекта
	cl_base* p_parent; // указатель на головной объект 

public:
	cl_base(cl_base* p_parent, string name); // конструктор для задания имени и готовности объекта
	~cl_base(); // декструктор

	void set_name(string object_name); //  метод определения имени объекта
	string get_name(); // метод получения имени объекта
	cl_base* get_pointer(string object_name); //  метод получения указателя по имени объекта
	cl_base* get_parent(); //  метод получения указателя головного объекта
	void add_child(cl_base* p_child); // метод добавления в список наследников текущего объекта, новый объект, который записан в параметр данного метода
	

	vector <cl_base*> children; // список указателей на объекты подчиненных к текущему объекту в дереве иерархии.
	vector <cl_base*>::iterator it_child;
	vector <o_sh* > connects; // вектор связей сигнал-обработчик

	//void print_connect(); // вывод связей и выдача строк для сигналов
	//void state(); // вывод готовностей объектов
	void show_tree_probel(cl_base* parent, int i);
	//cl_base* get_place(string s);
	//void search();
	//cl_base* g_root(); // метод выдающий указатель на корневой объект
	//int get_t();
	//void show_tree(); // метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз
	//void set_parent(cl_base* n_parent); //  метод переопределения головного объекта для текущего в дереве иерархии
	//void delete_connect(void(cl_base::* p_signal)(string&), cl_base* p_ob_hendler); // удаляет связь между выбранными сигналами и обработчиками 

	void set_connect(void(cl_base::* signal)(string&), void(cl_base::* hendler)(string&), cl_base* p_hendler); //устанавливает какой объект на какой сигнал реагирует и какой обработчик при этом вызывается
	int emit_signal(void(cl_base::* p_signal)(string&), string& s_command); //вызов сигнала на выполнение 
};
#endif