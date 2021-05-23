#include "cl_application.h"
void cl_application::bild_tree()
{
	cl_base* two = new cl_base2(this, "to_shape_var");
	cl_base* three = new cl_base3(this, "to_shape_polish");
	cl_base* four = new cl_base4(this, "output");
	cl_base* five = new cl_base5(three, "count_val");
	set_connect(SIGNAL_D(&cl_application::signal_1), HENDLER_D(&cl_base3::hendler_1), three);

	set_connect(SIGNAL_D(&cl_application::signal_2), HENDLER_D(&cl_base2::hendler_1), two);
	two->set_connect(SIGNAL_D(&cl_base2::signal_1), HENDLER_D(&cl_base5::hendler_1), five);

	set_connect(SIGNAL_D(&cl_application::signal_3), HENDLER_D(&cl_base4::hendler_1), four);

	set_connect(SIGNAL_D(&cl_application::signal_4), HENDLER_D(&cl_base3::hendler_2), three);
	three->set_connect(SIGNAL_D(&cl_base3::signal_1), HENDLER_D(&cl_base4::hendler_1), four);
	three->set_connect(SIGNAL_D(&cl_base3::signal_2), HENDLER_D(&cl_base5::hendler_2), five);
	five->set_connect(SIGNAL_D(&cl_base5::signal_1), HENDLER_D(&cl_base4::hendler_1), four);
}
int cl_application::exec_app()
{
	cout << "OUT";
	string k;
	while (true)
	{
		this->emit_signal(SIGNAL_D(&cl_application::signal_1), k);
		if (k == ".")
			break;
		this->emit_signal(SIGNAL_D(&cl_application::signal_2), k);
		this->emit_signal(SIGNAL_D(&cl_application::signal_3), k);
		this->emit_signal(SIGNAL_D(&cl_application::signal_4), k);
	}
	return 0;
}
void cl_application::signal_4(string& t) {
	t = "";
}; // выдача сигнала на формирование польской нотации 
void cl_application::signal_3(string& t) {
	t = "Values: " + t;
}; // выдача сигнала на вывод значений переменных 
void cl_application::signal_2(string& t) {
	getline(cin, t);
}; // выдача сигнала на формирование множества логических переменных
void cl_application::signal_1(string& t) {
	getline(cin, t);
}; // выдача сигнала на считывание строки логической функции 

