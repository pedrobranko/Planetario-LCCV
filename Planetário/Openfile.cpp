#include"Cabeçalho.h"

void Openfile::closefile() {
	output.close();
};

Openfile::Openfile() {
	output.open("saída.txt", ofstream::binary);
};