#include "cl_base.h"
cl_base::cl_base(cl_base* p_parent, string name) // запись  имени объекта и, если существует головной объект, добавления головоному объекту в список наследников новый объект
{
	this->set_name(name); // присваивание имени 
	this->p_parent = p_parent; // присваивание головного объекта
	if (p_parent != 0) // проверка на существование головного объекта
		p_parent->add_child(this);// добавление для головного объекта нового дочернего объекта
}
void cl_base::set_name(string object_name) // задаем имя для объекта 
{
	this->object_name = object_name;
}
void cl_base::add_child(cl_base* p_child) // добавление дочернего объекта для объекта родителя
{
	this->children.push_back(p_child); // в список наследников головного объекта(объект от которого был вызван метод) добавление дочернего объекта
}
string cl_base::get_name() // получение имени объекта
{
	return object_name;
}
cl_base* cl_base::get_pointer(string object_name) // выдаем указатель на объекта по его имени 
{
	if (this->get_name() == object_name)
		return this;
	cl_base* ob = 0;
	it_child = children.begin(); // начинаем проверку с начала вектора наследников
	while (it_child != children.end()) // работаем от начала  до конца вектора наследников
	{
		if ((*it_child)->get_name() == object_name) // ищем наследника объекта по его имени 
		{
			ob = (*it_child);// если нашли совпадние по имени присваиваем ob указатель на этот объект
		}
		if (ob != 0) // если нашли какой нибудь указатель 
			return ob;
		if ((*it_child)->children.size() != 0) // проверка на на наличие дочерних объектов
			ob = (*it_child)->get_pointer(object_name); // если есть присваиваем ob значение метода get_pointer
		it_child++; // наращиваем итератор
	}
	return ob;
}
cl_base* cl_base::get_parent() // получение адреса головного объекта
{
	return p_parent;
}
cl_base ::~cl_base() // деструктор
{
	for (int i = 0; i < this->children.size(); i++)
		delete this->children[i];
	for (int i = 0; i < this->connects.size(); i++)
		delete this->connects[i];
}
//void cl_base::show_tree() // вывод дерева
//{
//	cout << endl;
//	cout << this->get_name(); // вывод имени объекта, от которого запущен данный метод 
//	for (int i = 0; i < this->children.size(); i++) // просматриваем весь вектор наследников текущего объекта 
//		cout << "  " << this->children[i]->get_name(); // вывод имен всех дочерних объектов
//	for (int i = 0; i < this->children.size(); i++) // ищем дочерние объекты у наследников текущего объекта
//		if (this->children[i]->children.size() != 0) // провеяем существование дочерних объектов у наследников текущего объекта
//			this->children[i]->show_tree(); // при существовании дочернего объекта вызваем этот же метод для этого дочернего объекта
//}
//void cl_base::set_parent(cl_base* n_parent) // переименование головного объекта
//{
//	if (p_parent) // проверка не был ли объект, для которого вызывается метод, корневым, т.к. у корневого объекта нету головного объекта
//	{
//		for (int i = 0; i < p_parent->children.size(); i++) // // просматриваем весь вектор наследников текущего головного объекта 
//			if (p_parent->children[i]->get_name() == object_name) // ищем у текущего головного объекта дочернего объекта от которого вызвался метод
//				p_parent->children.erase(p_parent->children.begin() + i); // находим его и удаляем из списка наследников текущего головного объекта
//		p_parent = n_parent; // задаем для текущего объекта новый головной объект
//		n_parent->add_child(this); // для нового головного объекта добавляем объект в список наследников
//	}
//}
void cl_base::show_tree_probel(cl_base* parent, int i) // вывод с пробелами 
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
//void cl_base::search() // определения принадлежности объекта к построенному дереву иерархии 
//{
//	string s;
//	cin >> s;
//	cl_base* ob = 0;
//	s.erase(0, 1); //удалим ненужный слеш
//	while (s != "//") // закончен ввод, если введено //
//	{
//		if (s[0] == '/') // если в строке первый символ слеш, значит введен объект вида //"объект"
//		{
//			s = s.erase(0, 1);
//			if (get_place(s) != 0) // в зависимости нашелся объект или нет выводим
//				cout << endl << "/" << s << " Object name: " << get_place(s)->get_name();
//			else
//				cout << endl << "/" << s << " Object not found";
//		}
//		else
//		{
//
//			if (get_place(s) != 0) // в зависимости нашелся объект или нет выводим
//			{
//				cout << endl << '/' << s << " Object name: " << get_place(s)->get_name();
//			}
//			else
//				cout << endl << '/' << s << " Object not found";
//
//		}
//		cin >> s; // новый путь 
//	}
//}
//cl_base* cl_base::get_place(string s)
//{
//	if (s == this->get_name()) // если введеное имя это объект, от которого вызвался метод
//		return this; // возращаем данный объект
//	string k;
//	cl_base* ob = this;
//	s.erase(0, s.find('/') + 1); // удаляем ненужную часть "корень" и слеш 
//	if (s.find('/') == -1) // если нету слешов 
//	{
//		k = s; // значит вся строка s это имя по которому нужно искать указатель 
//		s.clear();
//	}
//	else
//	{
//		k.replace(0, 0, s, 0, s.find('/')); // добавляем в k часть до слеша  
//		s.erase(0, s.find('/') + 1); // удаляем слеш и то что перед ним 
//	}
//	while (k != "") // пока k есть, работаем с остальной частью строки 
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
void cl_base::set_connect(void(cl_base::* signal)(string&), void(cl_base::* hendler)(string&), cl_base* p_hendler) //устанавливает какой объект на какой сигнал реагирует и какой обработчик при этом вызывается
{
	o_sh* p_value; //указатель на объект структуры
	p_value = new o_sh(p_hendler, hendler, signal); //новый экземпляр (первый раз заполняем сигнал)
	connects.push_back(p_value); // добавляем в контейнер связей
}
//void cl_base::delete_connect(void(cl_base::* p_signal)(string&), cl_base* p_ob_hendler)
//{
//	int i = 0;
//	while (i < connects.size()) // проходимся по всему контейнеру связей 
//	{
//		if (connects[i]->signal == p_signal && connects[i]->p_hendler == p_ob_hendler) // если нашли совпадение по сигналу и объекту обработчику 
//		{
//			connects.erase(connects.begin() + i); // удаляем эту связь
//			return;
//		}
//		i++;
//	}
//}
int cl_base::emit_signal(void(cl_base::* p_signal)(string&), string& s_command) //вызывает обработчик на выполнение
{
	(this->*p_signal)(s_command); // вызов метода-сигнала  через указатель с параметром s_command
	int i = 0;
	while (i < connects.size()) // проходися по вектору связей 
	{
		if (connects[i]->signal == p_signal) {
			((connects[i]->p_hendler)->*(connects[i]->hendler))(s_command); // вызов метод-обработчик из вектора с параетром s_command
		}
		i++;
	}
	return 0; 
}
//void cl_base::print_connect()
//{
//	cout << "Set connects";
//	for (int i = 0; i < connects.size(); i++) // вывод существующиъ связей
//		cout << endl << connects[i]->num << " " << connects[i]->c_signal->get_name() << " " << connects[i]->p_hendler->get_name();
//	string ob_s, text;
//	cin >> ob_s;
//	cl_base* ob = get_pointer(ob_s); // по имени найдем указатель на выдающий сигнал объект
//	cout << "\nEmit signals";
//	while (ob_s != "endsignals")
//	{
//		
//		cout << typeid(*ob).name() << endl;
//		string k = typeid(*ob).name();
//		cout << k << endl;
//		k.erase(0, 6);
//		cin >> text; // вводим что будет выдывать 
//		switch (ob->get_t()) // в зависимости от класса объекта передаем нужный метод-сигнал
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
//int cl_base::get_t() // получение типа 
//{
//	return this->type;
//}
//cl_base* cl_base::g_root() //получить указатель на корневой объект
//{
//	cl_base* p = this; // идем от текущего объекта  
//	while (p->p_parent) //пока не дошли до головного
//		p = p->p_parent; //двигаемся выше
//	return p;
//}