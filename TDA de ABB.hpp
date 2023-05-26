//TDA de ABB

#include<iostream>

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
		//Construtor y destructor
		tABB(){
			raiz=nullptr;
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
//-----------------------------------------------------------------------
void tABB::clear(){
	clearHelp(raiz);
	raiz=nullptr;
	nElems=0;
}

void tABB::clearHelp(tNodoArbolBin* nodo) {
    if (nodo != nullptr) {
        clearHelp(nodo->izq);
        clearHelp(nodo->der);
        delete nodo;
    }
}

void tABB::insert(tipoElem item){
	if(raiz==nullptr){
		//cout<<"Se creo una raiz"<<endl;
		raiz = new tNodoArbolBin;
		raiz->info= item;
		raiz->der= nullptr;
		raiz->izq= nullptr;

	}else{
		insertHelp(raiz, item);
	}

	nElems++;
};

void tABB::insertHelp(tNodoArbolBin *nodo, tipoElem item){
	if(item > nodo->info){
		if(nodo->der == nullptr){
			//cout<<"Se inserto en la derecha"<<endl;
			nodo->der = new tNodoArbolBin;
			nodo->der->info= item;
			nodo->der->der= nullptr;
			nodo->der->izq= nullptr;
		}else{
			insertHelp(nodo->der, item);
		}
	}

	if(item< nodo->info){
		if(nodo->izq == nullptr){
			//cout<<"Se inserto en la izquierda"<<endl;
            nodo->izq = new tNodoArbolBin;
            nodo->izq->info = item;
            nodo->izq->der = nullptr;
            nodo->izq->izq = nullptr;
		}else{
			insertHelp(nodo->izq, item);
		}
	}
};

bool tABB::find(tipoElem item){
	return findHelp(raiz, item);
};

bool tABB::findHelp(tNodoArbolBin *nodo, tipoElem item){
	if(nodo->info == item) return true;


	if(item > nodo->info && nodo->der != nullptr) findHelp(nodo->der, item);

	if(item < nodo->info && nodo->izq != nullptr) findHelp(nodo->izq, item);

	return false;
};

int tABB::lower_bound(tipoElem item){
	return lower_boundHelp(raiz, item);
};

int tABB::lower_boundHelp(tNodoArbolBin *nodo, tipoElem item){
	if(nodo->info <= item) return nodo->info;
	if(nodo->izq != nullptr) lower_boundHelp(nodo->izq, item);

	return -1;
};

//------------testeo--------------------------------
/*
int main(){
	tABB arbol;
	arbol.insert(28);
	arbol.insert(16);
	arbol.insert(30);
	arbol.insert(5);
	arbol.insert(19);
	arbol.insert(29);
	arbol.insert(32);
	arbol.insert(12);
	arbol.insert(17);
	arbol.insert(21);

	arbol.find(17);
	arbol.lower_bound(5);

	arbol.clear();
	//g++ -g 'TDA de ABB.cpp' -o alo
	//valgrind --leak-check=yes ./'TDA de ABB.cpp'
	
	return 0;
};
*/