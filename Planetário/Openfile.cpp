#include"Cabe�alho.h"

void Openfile::closefile() {
	output.close();
};

Openfile::Openfile() {
	output.open("sa�da.txt", ofstream::binary);
};