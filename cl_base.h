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

	struct o_sh // ��������� ��� �������� ������ ������-����������
	{
		cl_base* p_hendler; //��������� �� �����, ����������� ������
		void (cl_base::* hendler) (string&); //��������� �� �����-����������
		void (cl_base::* signal)(string&); //��������� �� �����-������
		o_sh( cl_base* p_hendler, void (cl_base::* hendler) (string&), void (cl_base::* signal)(string&)) // �����������
		{
			this->p_hendler = p_hendler;
			this->hendler = hendler;
			this->signal = signal;
		};
	};

	string object_name; // ��� �������
	cl_base* p_parent; // ��������� �� �������� ������ 

public:
	cl_base(cl_base* p_parent, string name); // ����������� ��� ������� ����� � ���������� �������
	~cl_base(); // �����������

	void set_name(string object_name); //  ����� ����������� ����� �������
	string get_name(); // ����� ��������� ����� �������
	cl_base* get_pointer(string object_name); //  ����� ��������� ��������� �� ����� �������
	cl_base* get_parent(); //  ����� ��������� ��������� ��������� �������
	void add_child(cl_base* p_child); // ����� ���������� � ������ ����������� �������� �������, ����� ������, ������� ������� � �������� ������� ������
	

	vector <cl_base*> children; // ������ ���������� �� ������� ����������� � �������� ������� � ������ ��������.
	vector <cl_base*>::iterator it_child;
	vector <o_sh* > connects; // ������ ������ ������-����������

	//void print_connect(); // ����� ������ � ������ ����� ��� ��������
	//void state(); // ����� ����������� ��������
	void show_tree_probel(cl_base* parent, int i);
	//cl_base* get_place(string s);
	//void search();
	//cl_base* g_root(); // ����� �������� ��������� �� �������� ������
	//int get_t();
	//void show_tree(); // ����� ������ ������������ �������� � ������ �������� ����� ������� � ������ ����
	//void set_parent(cl_base* n_parent); //  ����� ��������������� ��������� ������� ��� �������� � ������ ��������
	//void delete_connect(void(cl_base::* p_signal)(string&), cl_base* p_ob_hendler); // ������� ����� ����� ���������� ��������� � ������������� 

	void set_connect(void(cl_base::* signal)(string&), void(cl_base::* hendler)(string&), cl_base* p_hendler); //������������� ����� ������ �� ����� ������ ��������� � ����� ���������� ��� ���� ����������
	int emit_signal(void(cl_base::* p_signal)(string&), string& s_command); //����� ������� �� ���������� 
};
#endif