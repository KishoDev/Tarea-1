#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;

struct SaldoColaborador{
	char rut[11];
	int saldo_desayuno;
	int saldo_almuerzo;
	int saldo_once;
	int saldo_cena;
};

//bool puedeConsumir(string rut, int servicio, string consumos_dia){
	
//}

int readFileAscii(string fileIn){
	ifstream file;
	string	rut;
	string 	servicio;
	string 	runFile = "";
	string	dato = "";
	int servicio;

	file.open(fileIn);

//Verifica si se abrió la custion
	if (!file.is_open()){
		cerr << "Error al abrir el archivo." << endl;
		return 1;
	}

	
	while(!file.eof()) {
		getline(file, dato);
		rut = dato.substr(0,9);
		dia = dato.substr(9,dato.length() - 1);

		if (dia == "DESAYUNO"){
			servicio = 0
		} else if ()



		if (puedeConsumir(rut, servicio, colaborador)) {
			cout << ":)" << endl;
		} else {
			cout << ":(" << endl;
		}

	} 

	file.close();
	return 0; 
}


int readFileBinary(string archivo) {
	int rDatos;
	ifstream file;
	file.open(archivo, ios::binary);
	
	//Si ocurre algún error al abrir el archivo
	if (!file.is_open()){
		cerr << "Error al abrir el archivo." << endl;
		return 1;
	}

	file.read((char*)&rDatos, sizeof(int));
	int numStruct = rDatos;
	SaldoColaborador colaborador[numStruct];

	for (int i = 0; i < numStruct; ++i) {
		file.read((char*)&colaborador[i], sizeof(SaldoColaborador));
	}

	file.close();
	return 0;
}


bool puedeConsumir (char* rut, int servicio, string consumos_dia) {
	
	return false
}



int main() {
	readFileBinary("saldos.bin");
	readFileAscii("entrada.txt");
	return 0;
}
