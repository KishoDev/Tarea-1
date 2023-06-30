#include<iostream>
#include<string>

using namespace std;

#define M 32
#define VACIA -1
#define C 2
#define VALORINVALIDO //Arreglar esto

typedef int tipoClave;

struct tipoInfo {
	string usuario;
	string password;
	bool registrado;
};

struct ranura {
 	tipoClave clave;
 	tipoInfo info;
};

class Login{
	private:
	tipoInfo datos;
	ranura HT[M];

	int tamaño = M;
	float factorCarga=0;

	//Hacer funciones de agrandar la tabla
	//Decidir la funcion del metodo de colisiones
	//Metodo de colisiones lineal

	int p(tipoClave k, int i);
	int hashInsert(ranura HT[], tipoClave k, tipoInfo I);
	tipoInfo hashSearch(ranura HT[], tipoClave k);

	public:
	Login(){
		ranura *HT = new ranura[M];
	}
	
	~Login(){
		delete[] HT;
	}
	
	bool iniciar_sesion(string usuario, string clave);
	bool crear_nuevo_usuario(string usuario, string clave);
	bool cambiar_clave(string usuario, string nueva_clave);

};


/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int Login::p(tipoClave k, int i) {
	return i*C;
}


/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int Login::hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
	int inicio, i;
	int pos = inicio;
	for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) pos = (inicio + p(k, i)) % M; 
	if (HT[pos].clave == k){	
		return 0;
	}else{
		HT[pos].clave = k;
		HT[pos].info = I;
		return 1;
	}
}

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
tipoInfo Login::hashSearch(ranura HT[], tipoClave k) {
	int inicio, i;
	int pos = inicio;
	for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) pos = (inicio + p(k, i)) % M;
 
	if (HT[pos].clave == k) return HT[pos].info;
	else return VALORINVALIDO;
}

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
bool Login::iniciar_sesion(string usuario, string clave){
	//Por completar
	return true;
}

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
bool Login::crear_nuevo_usuario(string usuario, string clave){
	//Por completar
	return true;
}

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
bool Login::cambiar_clave(string usuario, string nueva_clave){
	//Por completar
	return true;
}