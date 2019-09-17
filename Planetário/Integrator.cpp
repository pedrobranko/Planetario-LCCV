#include "Cabeçalho.h"

void Integrator::integrator(string aux) {	

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
		for (int i = 0; i < 4; ++i) {
			aux.push_back(0);
		};
		Integrator::first_point.push_back(aux);
	};
};

void Integrator::calc_forces() {
	
	for (int i = 0; i < build.dados.num_planets; ++i){		
		for (int j = 0; j < build.dados.num_planets; ++j) {			
			if (i != j) {
				double distance; //DISTÂNCIA ENTRE DOIS PLANETAS	
				distance = sqrt(pow(first_point[i][1] - first_point[j][1], 2) + pow(first_point[i][2] - first_point[j][2], 2) + pow(first_point[i][3] - first_point[j][3], 2)); 			
				for (int k = 0; k < 3; ++k) { //FORÇA ENTRE OS PLANETAS I E J, COM K VARIANDO EM X,Y,Z
					first_point[i][9+k] += (first_point[i][7] * first_point[j][7] * 6,674184E-11 *(first_point[j][k+1]-first_point[i][k+1]))/pow(distance,3);
					if (first_point[i][8] < distance || first_point[j][8] < distance) {
						first_point[i][9 + k] += Integrator::build.dados.constante.id_dem [Integrator::build.dados.constante.matr_dem[i][j]] * (first_point[i][k + 1] - first_point[j][k + 1]) / distance;
					};
				};
			};
		};
	};
};

void Integrator::build_next_point() {	
	if (build.dados.integrator == "EULER") {
		Integrator::euler();
	};
};

void Integrator::euler() {
	for (int i = 0; i < build.dados.num_planets; ++i) {
		for (int j = 0; j < 3; ++j) {
			first_point[i][j + 4] += build.dados.time.dt*first_point[i][j + 9]; //CALCULA NOVA VELOCIDADE
			first_point[i][j + 1] += build.dados.time.dt*first_point[i][j + 4]; // CALCULA NOVA POSIÇÃO
		};
		first_point[i][12] += build.dados.time.dt;
	};
};