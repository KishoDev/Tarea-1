#include<iostream>
#include<string>

using namespace std;

#define M 32
#define VACIA -1

//Definiciones del TDA
#define C 2
#define VALORINVALIDO //Arreglar esto

typedef int tipoClave;

struct tipoInfo {
 	// información del registro a almacenar
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
	int p(tipoClave k, int i) {
 		return i*C;
	}



	int hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
		int inicio, i;
		int pos = inicio;
		for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++)
			pos = (inicio + p(k, i)) % M; // próxima ranura en la secuencia
		if (HT[pos].clave == k)	return 0; // inserción no exitosa: clave repetida
		else {
			HT[pos].clave = k;
			HT[pos].info = I;
			return 1; // inserción exitosa
			}
	}

	tipoInfo hashSearch(ranura HT[], tipoClave k) {
 		int inicio, i;
 		int pos = inicio;
		for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) pos = (inicio + p(k, i)) % M; // próxima ranura en la secuencia
 
 		if (HT[pos].clave == k) return HT[pos].info; // registro encontrado, búsqueda exitosa
 		else return VALORINVALIDO;
	}


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