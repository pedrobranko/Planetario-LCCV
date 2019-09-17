#include "Cabeçalho.h"

Builder::Builder(string name_text) {
	name = name_text;	
	Builder::init_builder();
};

void Builder::init_builder() {
	info.open(Builder::name, ios::binary);	
	string aux;
	while (info){
		info >> aux;
		if (aux == "#PLANETAS#") {
			Builder::tag_planet(aux);
		};
		if (aux == "#TEMPO#") {
			Builder::tag_time(aux);
		};
		if (aux == "#DEM#") {
			Builder::tag_dem(aux);
		};
		if (aux == "#ID_DEM#") {
			Builder::tag_matrdem(aux);
		};
	};	
	info.close();
};

void Builder::tag_planet(string aux){	
	int n;
	getline(info, aux);
	getline(info, aux);
	istringstream ler(aux);
	ler >> n;
	for (int i = 0; i < n; ++i) {
		getline(info, aux);
		istringstream ler(aux);
		double id, x, y, z, vx, vy, vz, mass, raio;
		ler >> id >> x >> y >> z >> vx >> vy >> vz >> mass >> raio;
		double pos[3] = { x,y,z };
		double vel[3] = { vx,vy,vz };
		Planeta planeta;
		planeta.Defdata(id, raio, mass);
		planeta.Defpos(pos);
		planeta.Defvel(vel);
		dados.Add_Planet(planeta);
	};
};	

void Builder::tag_time(string aux) {		
getline(info, aux);
getline(info, aux);
istringstream ler(aux);
double dt_def, time_def, print_step_def;
ler >> dt_def >> time_def >> print_step_def;
dados.time.Def_Time_Data(dt_def, time_def, print_step_def);		
};

void Builder::tag_dem(string aux) {		
	getline(info, aux);
	getline(info, aux);	
	istringstream ler(aux);		
	ler >> dados.constante.n;		
	vector<double> aux_list;
	for (int i = 0; i < dados.constante.n; ++i) {
		getline(info, aux);
		istringstream ler(aux);
		double id, k;
		ler >> id >> k;		
		aux_list.push_back(k);
	};
	dados.constante.id_dem = aux_list;
};

void Builder::tag_matrdem(string aux) {
	getline(info, aux);
	getline(info, aux);
	istringstream ler(aux);
	ler >> dados.constante.n;
	vector<int> aux_list1;
	vector<vector<int>> aux_list2;
	for (int i = 0; i < dados.constante.n; ++i) {
		getline(info, aux);
		istringstream ler(aux);
		for (int j = 0; j < dados.constante.n; ++j) {
			int id;
			ler >> id;
			aux_list1.push_back(id);
		};
		aux_list2.push_back(aux_list1);
	};
	dados.constante.matr_dem = aux_list2;
};