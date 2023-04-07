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
	//bool ticket = true;
	//leer el archivo consumos del dia
    	//verificar el dato del rut si es que esta en el archivo de consumos del dia
    	//Comparar si tiene saldo disponible o no
    	//En el caso de que el saldo sea 0, cambiar el valor del ticket False
    	//En caso de que si tenga saldo, mantener el valor del ticket y escribir su rut y servicio en el archivo de consumos del dia
    	//Cerrar archivo de consumos del dia

    	//Duda existencial que tipo de dato es el saldo?

	//return ticket; //true == Ticket;
//}

int main(){
	ifstream file;
	string rut;
	string dia;
	string runFile = " ";

	file.open("entrada.txt");
	
//Verifica si se abrió la custion
	if (!file.is_open()){ 
		cout << "Error al abrir el archivo." << endl;
		exit(1);
	}

//Recorre el archivo y guarda cada string y díg. verificador en un uhhhhhhhhhhhhhh
	file >> runFile;
while (runFile != " ") {
	string rutNumeros = runFile.substr(0,8); //Obtiene los primeros dígitos del rut.
	string digVerificador = runFile.substr(9,1); //Obtiene el dígito verificador.
	file >> runFile;
	dia = runFile;	//Obtiene el día
	file >> runFile;

	//cout << rutNumeros << " " << digVerificador << " " <<  dia << endl;
	cout << runFile << endl;
	}

	file.close();
	return 0;
}
