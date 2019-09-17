#include "Cabeçalho.h"

void Planeta::Defpos(double pos[3])
{
	for (int i = 0; i < 3; ++i) 
	{
		posicao[i] = pos[i];
	}		
};
	
void Planeta::Defvel(double vel[3])
{
	for (int i = 0; i < 3; ++i)
	{
		velocidade[i] = vel[i];
	}
};

void Planeta::Defdata(double idef, double raiodef, double massadef) {
	id = idef;
	raio = raiodef;
	massa = massadef;
};

void Planeta::Print() {
	cout << Planeta::id << endl;
	for (int i = 0; i < 3; ++i) {
		cout << Planeta::posicao[i] << ((i < 2) ? ", " : "\n");
	};
	for (int i = 0; i < 3; ++i) {
		cout << Planeta::velocidade[i] << ((i < 2) ? ", " : "\n");
	};
	cout << Planeta::massa << "\n" << Planeta::raio << "\n";	
};
