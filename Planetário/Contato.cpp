#include "Cabeçalho.h"

void Contato::print_dem() {
	cout << "Id : Constante de contato" << endl;
	for (int i = 0; i < n; ++i) {
		cout << Contato::id_dem[i] << endl;
	};
	cout << "Matriz de identificacao" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << Contato::matr_dem[i][j] << " ";
		};
		cout << endl;
	};
};