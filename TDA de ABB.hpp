//TDA de ABB
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

typedef int tipoElem;

struct tNodoArbolBin{
	tipoElem info;
	tNodoArbolBin* izq;
	tNodoArbolBin* der;
};

class tABB{
	private:
		tNodoArbolBin *raiz;
		int nElems;
		void clearHelp(tNodoArbolBin *nodo);
		void insertHelp(tNodoArbolBin *nodo, tipoElem item);
		bool findHelp(tNodoArbolBin *nodo, tipoElem item);
		int lower_boundHelp(tNodoArbolBin *nodo, tipoElem item);

	public:
		tABB(){
			raiz=NULL;
			nElems=0;
		}
		~tABB(){
			clear();
		}

		void insert(tipoElem item);
		bool find(tipoElem item);
		int lower_bound(tipoElem item);
		void clear();
};
/*---------------------------------------------------------------------------------------*/
/*****
* void tABB::clear
******
* Resumen:
* 	Se encarga de limpiar el arbol generado por el TDA, para eso llama una función auxiliar y reinicia los valores de la raiz y los nElemns
******
* Input:
*   Ninguno ya que usa las funciones del TDA ABB
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/

void tABB::clear(){

	clearHelp(raiz);
	raiz=NULL;
	nElems=0;
}

/*---------------------------------------------------------------------------------------*/
/*****
* void tABB::clearHelp
******
* Resumen:
* 	Ayuda a limpiar los hijos del arbol que se formo y elimina el nodo cuando ya no tiene elementos
******
* Input:
*   -tNodoArbolBin nodo; es un nodo cualquiera del árbol y que puede o no tener elementos en la izquierda o derecha
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/
void tABB::clearHelp(tNodoArbolBin* nodo) {
	if (nodo != NULL) {
        clearHelp(nodo->izq);
        clearHelp(nodo->der);
        delete nodo;
    }
}

/*---------------------------------------------------------------------------------------*/
/*****
* void tABB::insert
******
* Resumen:
* 	Inserta un elemento en el nodo, puede ser en la izquierda o en la derecha. Pero antes se asegura de exista una raiz en el arbol para crear un nodo
*	y después llama una función que lo ayuda
******
* Input:
*   -tipoElem item; es un elemento que representa un numero
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/
void tABB::insert(tipoElem item){
	if(raiz==NULL){
		raiz = new tNodoArbolBin;
		raiz->info= item;
		raiz->der= NULL;
		raiz->izq= NULL;

	}else{
		insertHelp(raiz, item);
	}

	nElems++;
}

/*---------------------------------------------------------------------------------------*/
/*****
* void tABB::insertHelp
******
* Resumen:
* 	Ayuda a
******
* Input:
*   -int i; es un entero que representa el número de poste que hay que encender, si no lo está.
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/
void tABB::insertHelp(tNodoArbolBin *nodo, tipoElem item){
	if(item > nodo->info){
		if(nodo->der == NULL){
			nodo->der = new tNodoArbolBin;
			nodo->der->info= item;
			nodo->der->der= NULL;
			nodo->der->izq= NULL;
		}else{
			insertHelp(nodo->der, item);
		}
	}

	if(item< nodo->info){
		if(nodo->izq == NULL){
            nodo->izq = new tNodoArbolBin;
            nodo->izq->info = item;
            nodo->izq->der = NULL;
            nodo->izq->izq = NULL;
		}else{
			insertHelp(nodo->izq, item);
		}
	}
}

/*---------------------------------------------------------------------------------------*/
/*****
* void AvenidaLuces::Encender
******
* Resumen:
* 	Si el poste numero i no esta encendido (no se encuentra en el ABB), se enciende (se inserta en el ABB).
******
* Input:
*   -int i; es un entero que representa el número de poste que hay que encender, si no lo está.
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/
bool tABB::find(tipoElem item){
	return findHelp(raiz, item);
}

/*---------------------------------------------------------------------------------------*/
/*****
* void AvenidaLuces::Encender
******
* Resumen:
* 	Si el poste numero i no esta encendido (no se encuentra en el ABB), se enciende (se inserta en el ABB).
******
* Input:
*   -int i; es un entero que representa el número de poste que hay que encender, si no lo está.
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/
bool tABB::findHelp(tNodoArbolBin *nodo, tipoElem item){
	if (nodo == NULL){ 
		return false;
	} else if (nodo->info == item){
		return true;
	} else if (item < nodo->info){
		return findHelp(nodo->izq, item);
	} else {
		return findHelp(nodo->der, item);
	}
}

/*---------------------------------------------------------------------------------------*/
/*****
* void tABB::lower_bound
******
* Resumen:
* 	busca el primer valor que sea menor o igual a item, antes se asegura de que la raiz exista antes
*	de llamar una función auxiliar.
******
* Input:
*   -tipoElem item; es un elemento que se utilizara para buscar si existe un elemento menor o igual 
******
* Returns:
* 	retorna el elemento que es menor o igual al tipoElem item
*****/
int tABB::lower_bound(tipoElem item){
	if(raiz== NULL)	return 0;
	return lower_boundHelp(raiz, item);
}

/*---------------------------------------------------------------------------------------*/
/*****
* void tABB::lower_boundHelp
******
* Resumen:
* 	Se encarga de buscar en los nodos del árbol y los compara con el tipoElem item para ver 
*	si se cumple que el valor sea menor o igual. Si no lo encuentra entonces avanzara al nodo
*	izquierdo y si no se encuentra un elemetno menor o igual, entonces retornara 0
******
* Input:
*   -tNodoArbolBin *nodo; Es el puntero en donde se almacena el nodo
*   -tipoElem item; Es el elemento en el que se debe comparar el valor
******
* Returns:
* 	retorna 0, esto pasará solo si no se encuentra el elemento en el árbol
*****/
int tABB::lower_boundHelp(tNodoArbolBin *nodo, tipoElem item){
	if(nodo->info <= item) return nodo->info;
	if(nodo->izq != NULL) return lower_boundHelp(nodo->izq, item);

	return 0;
}
