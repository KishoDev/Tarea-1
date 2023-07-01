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
* int Login::p
******
* Resuelve las coliciones del hashing.
******
* Input:
* - tipoClave k; es la clave para acceder la elemento.
* - int i; 
* .......
******
* Returns:
* Retorna un entero de la nueva posición, la multiplicación de i por C.
*****/
int Login::p(tipoClave k, int i) {
	return i*C;
}


/*****
* int Login::hashInsert
******
* Inserta el elemento en el hashing, si la posición ya esta ocupada llama a la funcion p.
******
* Input:
* ranura HT[]; es el arreglo en donde se ubica el hashing.
* tipoClave k; es la clave para acceder al elemento.
* tipoInfo I; es la informacion del elemento.
* .......
******
* Returns:
*     Retorna 0 si ... y 1 si ... .
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
* tipoInfo Login::hashSearch
******
* Busca el elemento en el hashing y si lo encuentra se accede a él, en caso contrario retorna un valor invalido
******
* Input:
* - ranura HT[]; es el arreglo en donde se ubica el hashing.
* - tipoClave k; es la clave para acceder al elemento
* .......
******
* Returns:
* Retorna el elemento del hashing o puede retornar un valor invalido
*****/
tipoInfo Login::hashSearch(ranura HT[], tipoClave k) {
	int inicio, i;
	int pos = inicio;
	for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) pos = (inicio + p(k, i)) % M;
 
	if (HT[pos].clave == k) return HT[pos].info;
	else return VALORINVALIDO;
}

/*****
* bool Login::iniciar_sesion
******
* Dado el nombre usuario debe verificar si el usuario está registrado, en caso de no estarlo imprime
por pantalla “El usuario no se encuentra registrado” y retornar false
******
* Input:
*	string usuario; es el nombre del usuario
*	string clave; es la clave que esta asociada al usuario para iniciar sesión
* .......
******
* Returns:
* Si el usuario está registrado y la contraseña coincide imprime “Sesion iniciada con exito” y retornar
* true.
*****/
bool Login::iniciar_sesion(string usuario, string clave){
	//Por completar
	return true;
}

/*****
* bool Login::crear_nuevo_usuario
******
*  Crea un nuevo usuario y se inserta sus datos en el hashing,pero antes verifica si el
*   usuario ya se encuentra registrado 
******
* Input:
* 	string usuario; es el nombre del usuario
*	string clave; es la clave que esta asocida al usuario
******
* Returns:
*  retorna true y imprime “Usuario registrado con exito”, si se logra crear el ususario, en caso 
*  contrario retorna false y puede imprimir “La clave debe tener al menos 8 caracteres” o
*  “El usuario ya se encuentra registrado” 
*****/
bool Login::crear_nuevo_usuario(string usuario, string clave){
	//Por completar
	return true;
}

/*****
* bool Login::cambiar_clave
******
* Cambia la clave del usuario, pero antes verifica si el usuario se encuentra en el hashing
******
* Input:
*	string usuario; es el nombre del usuario
*	string nueva_clave; es la nueva clave que estará asociada al usuario
******
* Returns:
*   retorna true si la clave es actualizada con exito y imprime “Clave actualizada con exito”, 
*   retona false si el usuario no esta registrado e imprime “El usuario no se encuentra registrado” o
*   si no cumple con el minimo de caracters “La clave debe tener al menos 8 caracteres”
*****/
bool Login::cambiar_clave(string usuario, string nueva_clave){
	//Por completar
	return true;
}
