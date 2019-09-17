#include "Cabeçalho.h"

void Simulation::simulation() {
	string enter;
	string out;
	double flag;
	double count;

	cout << "Insira o nome do arquivo de entrada: ";	
	cin >> enter;
	cout << "\n" << "Insira o nome do arquivo de saída: ";
	cin >> out;

	Simulation::output.output(out);
	Simulation::integ.integrator(enter);
	Simulation::output.output_file << "(id) (Px) (Py) (Pz) (Vx) (Vy) (Vz) (Massa) (Raio) (Fx) (Fy) (Fz) (Tempo)" << endl;	

	flag = Simulation::integ.build.dados.time.print_step;
	count = 0;

	while (Simulation::integ.first_point[1][12] <= Simulation::integ.build.dados.time.time_simulation + Simulation::integ.build.dados.time.dt) {
		integ.calc_forces();		
		if (count >= flag) {
			for (int i = 0; i < integ.build.dados.num_planets; ++i) {
				for (int j = 0; j < 13; ++j) {
					output.output_file << "| " << integ.first_point[i][j];
				};
				output.output_file << endl;
			};	
			count = 0;
		};
		count += integ.build.dados.time.dt;
		integ.build_next_point();		
	};
	output.closefile();
};