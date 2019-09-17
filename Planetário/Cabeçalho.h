#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

class Planeta {	
public:	

	double id ;
	double posicao[3];
	double velocidade[3];
	double raio;
	double massa;

	void Defpos(double pos[3]);		
	void Defvel(double vel[3]);	
	void Defdata(double idef, double raiodef, double massadef);
	void Print();	
};

class Time_Data {
public:
	double dt;
	double time_simulation;
	double print_step;

	void Def_Time_Data(double dt_def, double time_def, double print_step_def);
	void Print_time();
};

class Contato {
public:
	int n;
	vector<double> id_dem;
	vector<vector<int>> matr_dem;

	void print_dem();
};

class Data {
public:
	vector<Planeta> all_Planets;
	string integrator;
	Time_Data time;
	Contato constante;
	int num_planets;

	void Add_Planet(Planeta planeta);	
};

class Builder {
public:
	Data dados;	
	ifstream info;		

	void init_builder(string name);
	void tag_planet(string aux);
	void tag_time(string aux);
	void tag_dem(string aux);
	void tag_matrdem(string aux);
	void tag_integrator(string aux);
};

class Output {
public:
	ofstream output_file;
	string name;
	void output(string aux);
	void closefile();	
};

class Integrator {
public:
	vector<vector<double>> first_point;	
	Builder build;

	void integrator(string aux);
	void build_first_point();	
	void build_next_point();
	void calc_forces();
	void euler();
};

class Simulation {
public:
	Integrator integ;
	Output output;
	void simulation();
};