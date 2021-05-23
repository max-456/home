#include "cl_base.h"
cl_base::cl_base(cl_base* p_parent, string name) // ������  ����� ������� �, ���� ���������� �������� ������, ���������� ���������� ������� � ������ ����������� ����� ������
{
	this->set_name(name); // ������������ ����� 
	this->p_parent = p_parent; // ������������ ��������� �������
	if (p_parent != 0) // �������� �� ������������� ��������� �������
		p_parent->add_child(this);// ���������� ��� ��������� ������� ������ ��������� �������
}
void cl_base::set_name(string object_name) // ������ ��� ��� ������� 
{
	this->object_name = object_name;
}
void cl_base::add_child(cl_base* p_child) // ���������� ��������� ������� ��� ������� ��������
{
	this->children.push_back(p_child); // � ������ ����������� ��������� �������(������ �� �������� ��� ������ �����) ���������� ��������� �������
}
string cl_base::get_name() // ��������� ����� �������
{
	return object_name;
}
cl_base* cl_base::get_pointer(string object_name) // ������ ��������� �� ������� �� ��� ����� 
{
	if (this->get_name() == object_name)
		return this;
	cl_base* ob = 0;
	it_child = children.begin(); // �������� �������� � ������ ������� �����������
	while (it_child != children.end()) // �������� �� ������  �� ����� ������� �����������
	{
		if ((*it_child)->get_name() == object_name) // ���� ���������� ������� �� ��� ����� 
		{
			ob = (*it_child);// ���� ����� ��������� �� ����� ����������� ob ��������� �� ���� ������
		}
		if (ob != 0) // ���� ����� ����� ������ ��������� 
			return ob;
		if ((*it_child)->children.size() != 0) // �������� �� �� ������� �������� ��������
			ob = (*it_child)->get_pointer(object_name); // ���� ���� ����������� ob �������� ������ get_pointer
		it_child++; // ���������� ��������
	}
	return ob;
}
cl_base* cl_base::get_parent() // ��������� ������ ��������� �������
{
	return p_parent;
}
cl_base ::~cl_base() // ����������
{
	for (int i = 0; i < this->children.size(); i++)
		delete this->children[i];
	for (int i = 0; i < this->connects.size(); i++)
		delete this->connects[i];
}
//void cl_base::show_tree() // ����� ������
//{
//	cout << endl;
//	cout << this->get_name(); // ����� ����� �������, �� �������� ������� ������ ����� 
//	for (int i = 0; i < this->children.size(); i++) // ������������� ���� ������ ����������� �������� ������� 
//		cout << "  " << this->children[i]->get_name(); // ����� ���� ���� �������� ��������
//	for (int i = 0; i < this->children.size(); i++) // ���� �������� ������� � ����������� �������� �������
//		if (this->children[i]->children.size() != 0) // �������� ������������� �������� �������� � ����������� �������� �������
//			this->children[i]->show_tree(); // ��� ������������� ��������� ������� ������� ���� �� ����� ��� ����� ��������� �������
//}
//void cl_base::set_parent(cl_base* n_parent) // �������������� ��������� �������
//{
//	if (p_parent) // �������� �� ��� �� ������, ��� �������� ���������� �����, ��������, �.�. � ��������� ������� ���� ��������� �������
//	{
//		for (int i = 0; i < p_parent->children.size(); i++) // // ������������� ���� ������ ����������� �������� ��������� ������� 
//			if (p_parent->children[i]->get_name() == object_name) // ���� � �������� ��������� ������� ��������� ������� �� �������� �������� �����
//				p_parent->children.erase(p_parent->children.begin() + i); // ������� ��� � ������� �� ������ ����������� �������� ��������� �������
//		p_parent = n_parent; // ������ ��� �������� ������� ����� �������� ������
//		n_parent->add_child(this); // ��� ������ ��������� ������� ��������� ������ � ������ �����������
//	}
//}
void cl_base::show_tree_probel(cl_base* parent, int i) // ����� � ��������� 
{
	string space;
	if (i > 0)
		space.append(4 * i, ' ');
	if (i != 0)
		cout << endl;
	cout << space << parent->get_name();
	if (parent->children.size() == 0)
		return;
	parent->it_child = parent->children.begin();
	while (parent->it_child != parent->children.end()) {
		show_tree_probel((cl_base*)(*(parent->it_child)), i + 1);
		parent->it_child++;
	}
}
//void cl_base::search() // ����������� �������������� ������� � ������������ ������ �������� 
//{
//	string s;
//	cin >> s;
//	cl_base* ob = 0;
//	s.erase(0, 1); //������ �������� ����
//	while (s != "//") // �������� ����, ���� ������� //
//	{
//		if (s[0] == '/') // ���� � ������ ������ ������ ����, ������ ������ ������ ���� //"������"
//		{
//			s = s.erase(0, 1);
//			if (get_place(s) != 0) // � ����������� ������� ������ ��� ��� �������
//				cout << endl << "/" << s << " Object name: " << get_place(s)->get_name();
//			else
//				cout << endl << "/" << s << " Object not found";
//		}
//		else
//		{
//
//			if (get_place(s) != 0) // � ����������� ������� ������ ��� ��� �������
//			{
//				cout << endl << '/' << s << " Object name: " << get_place(s)->get_name();
//			}
//			else
//				cout << endl << '/' << s << " Object not found";
//
//		}
//		cin >> s; // ����� ���� 
//	}
//}
//cl_base* cl_base::get_place(string s)
//{
//	if (s == this->get_name()) // ���� �������� ��� ��� ������, �� �������� �������� �����
//		return this; // ��������� ������ ������
//	string k;
//	cl_base* ob = this;
//	s.erase(0, s.find('/') + 1); // ������� �������� ����� "������" � ���� 
//	if (s.find('/') == -1) // ���� ���� ������ 
//	{
//		k = s; // ������ ��� ������ s ��� ��� �� �������� ����� ������ ��������� 
//		s.clear();
//	}
//	else
//	{
//		k.replace(0, 0, s, 0, s.find('/')); // ��������� � k ����� �� �����  
//		s.erase(0, s.find('/') + 1); // ������� ���� � �� ��� ����� ��� 
//	}
//	while (k != "") // ���� k ����, �������� � ��������� ������ ������ 
//	{
//		ob = ob->get_pointer(k);
//		if (ob == 0) return 0;
//		k.clear();
//		if (s != "")
//		{
//			if (s.find('/') == -1)
//			{
//				k = s;
//				s.clear();
//			}
//			else
//			{
//				k.replace(0, 0, s, 0, s.find('/'));
//				s.erase(0, s.find('/') + 1);
//			}
//		}
//	}
//	return ob;
//}
void cl_base::set_connect(void(cl_base::* signal)(string&), void(cl_base::* hendler)(string&), cl_base* p_hendler) //������������� ����� ������ �� ����� ������ ��������� � ����� ���������� ��� ���� ����������
{
	o_sh* p_value; //��������� �� ������ ���������
	p_value = new o_sh(p_hendler, hendler, signal); //����� ��������� (������ ��� ��������� ������)
	connects.push_back(p_value); // ��������� � ��������� ������
}
//void cl_base::delete_connect(void(cl_base::* p_signal)(string&), cl_base* p_ob_hendler)
//{
//	int i = 0;
//	while (i < connects.size()) // ���������� �� ����� ���������� ������ 
//	{
//		if (connects[i]->signal == p_signal && connects[i]->p_hendler == p_ob_hendler) // ���� ����� ���������� �� ������� � ������� ����������� 
//		{
//			connects.erase(connects.begin() + i); // ������� ��� �����
//			return;
//		}
//		i++;
//	}
//}
int cl_base::emit_signal(void(cl_base::* p_signal)(string&), string& s_command) //�������� ���������� �� ����������
{
	(this->*p_signal)(s_command); // ����� ������-�������  ����� ��������� � ���������� s_command
	int i = 0;
	while (i < connects.size()) // ��������� �� ������� ������ 
	{
		if (connects[i]->signal == p_signal) {
			((connects[i]->p_hendler)->*(connects[i]->hendler))(s_command); // ����� �����-���������� �� ������� � ��������� s_command
		}
		i++;
	}
	return 0; 
}
//void cl_base::print_connect()
//{
//	cout << "Set connects";
//	for (int i = 0; i < connects.size(); i++) // ����� ������������ ������
//		cout << endl << connects[i]->num << " " << connects[i]->c_signal->get_name() << " " << connects[i]->p_hendler->get_name();
//	string ob_s, text;
//	cin >> ob_s;
//	cl_base* ob = get_pointer(ob_s); // �� ����� ������ ��������� �� �������� ������ ������
//	cout << "\nEmit signals";
//	while (ob_s != "endsignals")
//	{
//		
//		cout << typeid(*ob).name() << endl;
//		string k = typeid(*ob).name();
//		cout << k << endl;
//		k.erase(0, 6);
//		cin >> text; // ������ ��� ����� �������� 
//		switch (ob->get_t()) // � ����������� �� ������ ������� �������� ������ �����-������
//		{
//		case 1:
//			ob->emit_signal(SIGNAL_D(&cl_application::signal), text);
//			break;
//		case 2:
//			ob->emit_signal(SIGNAL_D(&cl_base2::signal), text);
//			break;
//		case 3:
//			ob->emit_signal(SIGNAL_D(&cl_base3::signal), text);
//			break;
//		};
//		cin >> ob_s;
//		ob = get_pointer(ob_s);
//	}
//}
//int cl_base::get_t() // ��������� ���� 
//{
//	return this->type;
//}
//cl_base* cl_base::g_root() //�������� ��������� �� �������� ������
//{
//	cl_base* p = this; // ���� �� �������� �������  
//	while (p->p_parent) //���� �� ����� �� ���������
//		p = p->p_parent; //��������� ����
//	return p;
//}