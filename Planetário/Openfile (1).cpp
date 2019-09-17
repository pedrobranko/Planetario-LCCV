#include"Cabeçalho.h"

void Openfile::closefile() {

};

Openfile::Openfile() {
	output.open("saída.txt", ofstream::binary);
};