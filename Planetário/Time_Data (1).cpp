#include "Cabeçalho.h"

void Time_Data::Def_Time_Data(double dt_def, double time_def, double print_step_def) {
	dt = dt_def;
	time_step = time_def;
	print_step = print_step_def;
};
void Time_Data::Print_time() {
	cout << "Passo de Impressao: " << print_step << endl << "Variacao de Tempo: " << dt << endl << "Tempo de Calculo: " << time_step << endl;
};