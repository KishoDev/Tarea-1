#include <iostream>

using namespace std;

typedef int tElemLista;

struct tNodo{
  tElemLista info;
  tNodo* sig;
};

class tLista{
  private:
    tNodo* head;
    tNodo* tail;
    tNodo* curr;
    unsigned int listSize;
    unsigned int pos;
  public:
    tLista();
    ~tLista();
    int insert(tElemLista item);
    void moveToPos(unsigned int posicion);
    void moveToStart();
    int erase();
    void clear();
    void exchange(tElemLista item);
    tElemLista getValue();
    int getSize();
    void next();
};

// constructor
tLista::tLista(){
  head = tail = curr = new tNodo;
  listSize = 0; pos = 0;
}

// destructor
tLista::~tLista(){ delete head; delete tail; delete curr; }

// inserta un elemento en la posición actual de la lista.
int tLista::insert(tElemLista item){
  tNodo* aux = curr -> sig;
  curr -> sig = new tNodo;
  curr -> sig -> info = item;
  curr -> sig -> sig = aux;
  if (curr == tail) tail = curr -> sig;
  return pos;
}

// mueve el cursor a la posición deseada
void tLista::moveToPos(unsigned int posicion){
  unsigned int i;
  if (posicion < 0 || posicion > listSize) return;
  curr = head;
  pos = 0;
  for (i = 0; i < posicion; i++) {
    curr = curr->sig;
    pos++;
  }
}

void tLista::moveToStart() { curr = head; pos = 0; }

int tLista::erase(){
  tNodo* aux = curr -> sig;
  if (curr == tail) return -1;
  curr -> sig = curr -> sig -> sig;
  delete aux;
  return pos;
}

void tLista::clear(){
  listSize = 0;
  head = tail = curr = NULL;
}

void tLista::exchange(tElemLista item){ curr -> sig -> info = item; }

int tLista::getSize(){ return listSize; }

tElemLista tLista::getValue() {
  tElemLista information = curr -> info;
  return information;
}

void tLista::next() { if (curr != tail) { curr = curr -> sig; pos++; } }
