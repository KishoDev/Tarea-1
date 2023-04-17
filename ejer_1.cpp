#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;
/*-----------------------------------------------------------------------------------------------------*/
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
/*-----------------------------------------------------------------------------------------------------*/

/*****
* int consultaSaldo
******
* RESUMEN:
* 	Consulta en saldo.bin si el usuario introducido tiene saldo para el servicio seleccionado.
******
* Input:
* 	- char* inputRut : El rut del usuario a buscar.
* 	- int inputServicio : El servicio que se desea consultar el saldo.
******
* Returns:
* 	int, retorna el saldo almacenado en saldos.bin para el servicio y usuario introducido. En el caso de que el usuario no tenga saldo o no exista, retorna 0.
*****/

int consultaSaldo(char* inputRut, int inputServicio){
	ifstream fileBinary;
	int numberStructs;
	SaldoColaborador infoColaborador;

	fileBinary.open("saldos.bin", ios::binary);

	if (!fileBinary.is_open()){
		cerr << "Error al abrir el archivo binario." << endl;
		exit(1);
	}

	fileBinary.read((char*)&numberStructs, sizeof(int));

	for(int i = 0; i < numberStructs; i++) {
		fileBinary.read((char*)&infoColaborador, sizeof(SaldoColaborador));

		if (strcmp(inputRut, infoColaborador.rut) == 0) { 
			switch(inputServicio){
				case 0:
					return infoColaborador.saldo_desayuno;
				case 1:
					return infoColaborador.saldo_almuerzo;
				case 2:
					return infoColaborador.saldo_once;
				case 3:
					return infoColaborador.saldo_cena;
				default:
					return 0;
			}
		}
	}
	return 0;
}
/*-----------------------------------------------------------------------------------------------------*/

/*****
* TipoFunción NombreFunción
* bool puedeConsumir
******
* RESUMEN:
* 	hace algo.
******
* INPUT:
* tipoParámetro NombreParámetro : Descripción Parámetro
* 	- char* rut : rut del colaborador
* 	- int servicio : servicio que desea
* 	- string consumos_dia : 
* .......
******
* Returns:
* 	bool, retorna true si el usuario tiene saldo o falso si el usuario introducido no tiene saldo o no existe en saldos.bin.
*****/

bool puedeConsumir(char* rut, int servicio, string consumos_dia) {
	fstream file;
	int nLines = 0;
	int saldo = 0;
	struct colaboradorId{
		string 	rutColaborador;
		string 	diaServicio;
	};
	string lineStream;
	int idServicio;
	string textoServicio;


	file.open(consumos_dia, ios::in);

	if (!file.is_open()) {
		file.close();
		file.open(consumos_dia, ios::out);
		if (!file.is_open()){
			cerr << "Error al abrir el archivo en modo de escritura." << endl;
			exit(1);
		}
	} else {
		for (string temp; !file.eof(); getline(file, temp)){
				nLines++;
		}
		file.seekg(0);
		file.clear();
		
		getline(file, lineStream);
 		for (int i = 0; i < nLines; i++) {
 			string rutStream = lineStream.substr(0, 10);
 			char servicioStream = lineStream[11];

 			switch(servicioStream){
 				case 'D': 
 					idServicio = 0; //Desayuno
 					break; 
 				case 'A': 
 					idServicio = 1; //Almuerzo
 					break; 
 				case 'O': 
 					idServicio = 2; //Once
 					break; 
 				case 'C': 
 					idServicio = 3; //Cena
 					break;
 			}

 			if (strcmp(rutStream.c_str(), rut) == 0 && idServicio == servicio){
 				saldo -= 1;
 			}

 			getline(file, lineStream);
		}
		file.close();
		file.open(consumos_dia, ios::app);
		if (!file.is_open()){
			cerr << "error al abrir el archivo en modo de escritura." << endl;
			exit(1);	
		}
	}

	saldo += consultaSaldo(rut, servicio);

	if (saldo > 0){
		switch(servicio){
			case 0: textoServicio = "DESAYUNO"; break;
			case 1: textoServicio = "ALMUERZO"; break;
			case 2: textoServicio = "ONCE"; break;
			case 3: textoServicio = "CENA"; break;
		}

		if (file.tellg() != 0){
			file << endl;
		} 
		file << rut << " " << textoServicio;

		return true;
	}

	file.close();
	return false;
}
/*-----------------------------------------------------------------------------------------------------*/
int main() {
	return 0;
}
