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
//---------------------------------------------------------------------------------------/
/***
* void tABB::clear
**
* Resumen:
*   Se encarga de limpiar el árbol, llama a la función clearHelp y reinicializa los atributos
*   raiz y nElems a NULL y 0 respectivamente.
**
* Input:
*   No recibe nada.
**
* Returns:
*   No retorna nada ya que es una funcion void.
***/

void tABB::clear(){

	clearHelp(raiz);
	raiz=NULL;
	nElems=0;
}

//---------------------------------------------------------------------------------------/
/***
* void tABB::clearHelp
**
* Resumen:
*   Si el nodo no esta vacío, entonces elimina los hijos del nodo y luego elimina el nodo
**
* Input:
*   - tNodoArbolBin* nodo; es un arreglo de struct en el que se almacena el nodo.
**
* Returns:
*   No retorna nada ya que es una funcion void.
***/
void tABB::clearHelp(tNodoArbolBin* nodo) {
	if (nodo != NULL) {
        clearHelp(nodo->izq);
        clearHelp(nodo->der);
        delete nodo;
    }
}

//---------------------------------------------------------------------------------------/
/***
* void tABB::insert
**
* Resumen:
* 	Si la raiz es NULL crea el nodo y asigna el elemento al nodo->info; si no llama a la 
*   función insertHelp, con la raiz y el elemento item como parámetros. 
*   Al final nElems aumenta en uno (se le suma 1 a nElems).
**
* Input:
*   - tipoElem item; el elemento que se quiere agregar al ABB.
**
* Returns:
* 	No retorna nada ya que es una funcion void.
***/
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

//---------------------------------------------------------------------------------------/
/***
* void tABB::insertHelp
**
* Resumen:
*   Si el elemento es mayor al nodo, crea el nodo->der y asigna el valor, o llama a la 
*   función insert Help, lo mismo si el elemento es menor, con el nodo->izq.
**
* Input:
*   - tNodoArbolBin* nodo; es un arreglo de struct en el que se almacena el nodo.
*   - tipoElem item; el elemento que se quiere agregar al ABB.
**
* Returns:
* 	No retorna nada ya que es una funcion void.
***/
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
//---------------------------------------------------------------------------------------/
/***
* bool tABB::find
**
* Resumen: 
*   Busca al elemento, llama a la función findHelp.
**
* Input:
*   - tipoElem item; el elemento que se quiere encontrar.
**
* Returns:
*   Retorna un booleano, true si se encontró el elemento y false si no lo hizo.
***/

bool tABB::find(tipoElem item){
	return findHelp(raiz, item);
}

//---------------------------------------------------------------------------------------/
/***
* bool tABB::findHelp
**
* Resumen: 
*   Verifica si el nodo es NULL o si el elemento se encontró (es igual al nodo) y si el 
*   nodo es mayor o menor al elemento se llama a la función findHelp. 
**
* Input:
*   - tNodoArbolBin* nodo; es un arreglo de struct en el que se almacena el nodo.
*   - tipoElem item; el elemento que se quiere encontrar.
**
* Returns:
*   Retorna un booleano, true si se encontro, false si no lo encontró.
***/
	
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
*   -tNodoArbolBin *nodo; es un arreglo de struct en el que se almacena el nodo
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
