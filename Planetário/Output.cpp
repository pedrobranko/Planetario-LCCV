#include"Cabeçalho.h"

void Output::closefile() {
	output_file.close();
};

void Output::output(string aux) {
	name = aux;
	output_file.open(name, ofstream::binary);
};