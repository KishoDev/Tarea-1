#include<iostream>
#include<string>

using namespace std;

#define M 32
#define VACIA -1

typedef int tipoClave;

struct tipoInfo {	
// información del registro a almacenar
	string nombre;
	string clave;
};

struct ranura {
	tipoClave clave;
 	tipoInfo info;
};

ranura HT[M];
