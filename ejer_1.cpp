#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;

struct SaldoColaborador{
	string rut;
	int saldo_desayuno;
	int saldo_almuerzo;
	int saldo_once;
	int saldo_cena;
};

//bool puedeConsumir(string rut, int servicio, string consumos_dia){
	
//}

int main(){
	ifstream file;
	string rut;
	string dia;
	file.open("entrada.txt");
	
//Verifica si se abrió la custion
	if (!file.is_open()){ 
		cout << "Error al abrir el archivo." << endl;
		exit(1);
	}

//Recorre el archivo y guarda cada string y díg. verificador en un uhhhhhhhhhhhhhh
	file >> rut;
	cout << rut << endl;
	file.close();
	return 0;
}
