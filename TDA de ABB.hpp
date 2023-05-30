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
		void mostrarArbolHelp(tNodoArbolBin *nodo, int cont);

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
		void mostrarArbol();
};
//-----------------------------------------------------------------------
void tABB::clear(){

	clearHelp(raiz);
	raiz=NULL;
	nElems=0;
}

void tABB::clearHelp(tNodoArbolBin* nodo) {
	if (nodo != NULL) {
        clearHelp(nodo->izq);
        clearHelp(nodo->der);
        delete nodo;
    }
}

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

bool tABB::find(tipoElem item){
	return findHelp(raiz, item);
}

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

int tABB::lower_bound(tipoElem item){
	if(raiz== NULL)	return 0;
	return lower_boundHelp(raiz, item);
}

int tABB::lower_boundHelp(tNodoArbolBin *nodo, tipoElem item){
	if(nodo->info <= item) return nodo->info;
	if(nodo->izq != NULL) return lower_boundHelp(nodo->izq, item);

	return 0;
}

void tABB::mostrarArbol(){
	mostrarArbolHelp(raiz, 0);
}

void tABB::mostrarArbolHelp(tNodoArbolBin *nodo, int cont){
	if (nodo == NULL){
		return;
	}else{
		mostrarArbolHelp(nodo->der, cont+1);
		for (int i=0; i<cont; i++){
			cout<<"   ";
		}
		cout<<nodo->info<<endl;
		mostrarArbolHelp(nodo->izq, cont+1);
	}
}
