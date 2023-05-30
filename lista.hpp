#include <iostream>
#include <string>

using namespace std;



struct tNodo{
  char info;
  tNodo* sig;
};

class tLista {
  private:
    tNodo* head;
    tNodo* tail;
    tNodo* curr;
    unsigned int listSize;
    unsigned int pos;
  public:


    /*****
    * tLista()
    ******
    * Constructor de la clase.
    *****/
    tLista(){
      head = tail = curr = new tNodo;
      listSize = 0; pos = 0;
    };


    /*****
    * ~tLista()
    ******
    * Destructor de la clase. Llama a la función clear().
    *****/
    ~tLista(){ clear(); };


    /*****
    * void clear()
    ******
    * Libera toda la memoria asociada con la lista, reiniciándola como vacía.
    ******
    * No retorna nada ya que es una función void.
    *****/
    void clear(){
      curr = head;
      while(curr != tail){
        curr = curr -> sig;
        delete head;
        head = curr;
      }
      delete curr;
    };


    /*****
    * int insert(char item)
    ******
    * Se le inserta un item a la lista en la posición actual del cursor.
    ******
    * Input:
    *     char item: item a introducir.
    ******
    * Return:
    *     int, retorna un integer indicando la posición en donde se insertó.
    *****/
    int insert(char item){
      tNodo* aux = curr -> sig;
      curr -> sig = new tNodo;
      curr -> sig -> info = item;
      curr -> sig -> sig = aux;
      if (curr == tail) tail = curr -> sig;
      listSize++;
      return pos;
    };


    /*****
    * void moveToStart()
    ******
    * Mueve el cursor al principio de la lista.
    ******
    * No retorna nada ya que es una función void.
    *****/
    void moveToStart(){ 
      curr = head; pos = 0;
    };

    
    /*****
    * void moveToEnd()
    ******
    * Mueve el cursor al final de la lista.
    ******
    * No retorna nada ya que es una función void.
    *****/
    void moveToEnd() { 
      curr = tail; pos = listSize; 
    };


    /*****
    * void prev()
    ******
    * Mueve el cursor al nodo anterior del nodo que se encuentra actualmente.
    ******
    * No retorna nada uya que ess una función void.
    *****/
    void prev(){
      tNodo* temp;
      if (curr == head) return;
      temp = head;
      while (temp -> sig != curr) temp = temp -> sig;
      curr = temp;
      pos--;
    };
    

    /*****
    * void next()
    ******
    * Mueve el cursor al nodo siguiende que se encuenta actualmente.
    ******
    * No retorna nada ya que es una función void.
    *****/
    void next(){ 
      if (curr != tail) { 
        curr = curr -> sig; 
        pos++;
      } 
    };


    /*****
    * void moveToPos(unsigned int posicion)
    ******
    * Mueve el cursor a una posición dada.
    ******
    * Input:
    *     unsigned int posicion : Un entero que indica a qué posición se quiere ir.
    ******
    * No retorna nada ya que es una función void.
    *****/
    void moveToPos(unsigned int posicion) {
      unsigned int i;
      if (posicion < 0 || posicion > listSize) return;
      curr = head;
      pos = 0;
      for (i = 0; i < posicion; i++){
        curr = curr -> sig;
        pos++;
      }
    };


    /*****
    * char getValue()
    ******
    * Entrega el valor del nodo que el cursor está apuntando actualmente.
    ******
    * Return:
    *     char, retorna el valor del nodo que el cursor está apuntando actualmente.
    *****/
    char getValue(){
      return curr -> info;
    };


    /*****
    * void exchange()
    ******
    * Cambia el valor del nodo el cual el cursor está apuntando.
    ******
    * Input:
    *     char item : El nuevo valor que se quiere sobreescribir.
    ******
    * No retorna nada ya que es una función void.
    *****/
    void exchange(char item){
      curr -> sig -> info = item;
    };

    /*****
    * TipoFunción NombreFunción
    ******
    * Elimina el nodo que está apuntando el cursor.
    ******
    * No retorna nada ya que es una función void.
    *****/
    void erase(){
      tNodo* aux = curr -> sig;
      curr -> sig = curr -> sig -> sig;
      delete aux;
      listSize--;
    };

    /*****
    * string listToString()
    ******
    * Convierte la lista en un string.
    ******
    * Return:
    *     string, retorna la lista convertida en un string.
    *****/
    string listToString(){
      string lString = "";
      curr = head; pos = 0;
      while(pos <= listSize){
        lString += curr -> info;
        curr = curr -> sig;
        pos++;
      }
      return lString;
    };
};
