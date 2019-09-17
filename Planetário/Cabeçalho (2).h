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
	double time_step;
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
	void Add_Planet(Planeta planeta);	
};

class Builder {
public:
	Data dados;	
	ifstream info;
	string name;		
	Builder(string);
	void init_builder();
	void tag_planet(string aux);
	void tag_time(string aux);
	void tag_dem(string aux);
	void tag_matrdem(string aux);
	void tag_integrator(string aux);
};

class Openfile {
public:
	ofstream output;
	Openfile();
	void closefile();
	
};

class Integrator {
public:
	Builder build;


};



