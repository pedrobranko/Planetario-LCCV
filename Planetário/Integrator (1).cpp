#include "Cabeçalho.h"

Integrator::Integrator(string aux) {	
	build.init_builder(aux);
	Integrator::build_first_point();
};

void Integrator::build_first_point() {	

	for (int i = 0; i < build.dados.num_planets; ++i) {
		vector<double> aux;
		aux.push_back(build.dados.all_Planets[i].id);
		for (int j = 0; j < build.dados.num_planets; ++j) {
			aux.push_back(build.dados.all_Planets[i].posicao[j]);
		};
		for (int j = 0; j < build.dados.num_planets; ++j) {
			aux.push_back(build.dados.all_Planets[i].velocidade[j]);
		};
		aux.push_back(build.dados.all_Planets[i].massa);
		aux.push_back(build.dados.all_Planets[i].raio);
		for (int i = 0; i < build.dados.num_planets; ++i) {
			aux.push_back(0);
		};
		Integrator::first_point.push_back(aux);
	};
};

void Integrator::calc_forces() {
	
	for (int i = 0; i < build.dados.num_planets; ++i){
		double aux_force[3] = { 0,0,0 };
		for (int j = 0; j < build.dados.num_planets; ++j) {			
			if (i != j) {
				double distance;
				distance = sqrt(pow(first_point[i][1] - first_point[j][1], 2) + pow(first_point[i][2] - first_point[j][2], 2) + pow(first_point[i][3] - first_point[j][3], 2)); //DISTÂNCIA ENTRE DOIS PLANETAS				
				for (int k = 0; k < 3; ++k) {
					aux_force[k] += (first_point[i][7] * first_point[j][7] * 10 );
				};
			};
		};
	};

};

void Integrator::print_point() {
	ofstream ofs;
	ofs.open("coisa.txt", ofstream::binary);
	for (int i = 0; i < build.dados.num_planets; ++i) {
		ofs << build.dados.all_Planets[i].id << " ";
		for (int j = 0; j < 3; ++j) {
			ofs << build.dados.all_Planets[i].posicao[j] << " ";
		};
		for (int j = 0; j < 3; ++j) {
			ofs << build.dados.all_Planets[i].velocidade[j] << " ";
		};
		ofs << build.dados.all_Planets[i].massa << " ";
		ofs << build.dados.all_Planets[i].raio << " ";
		ofs << endl;
	};
};