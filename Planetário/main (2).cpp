#include "Cabe�alho.h"
inline void keep_windows_open() { char ch; cin >> ch; }
using namespace std;

int main() {
	string text = "Teste.txt";
	Builder teste(text);	
	teste.dados.all_Planets[0].Print();
	teste.dados.time.Print_time();
	teste.dados.constante.print_dem();	
	int a;
	cin >> a;
};