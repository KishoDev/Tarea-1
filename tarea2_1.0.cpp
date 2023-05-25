#include <iostream>
#include <fstream>
#include <string>
#include "lista.hpp"

using namespace std;

tLista* insertar(tLista* modNucleotido, int pos, tElemLista nucl){
  modNucleotido -> moveToPos(pos);
  modNucleotido -> insert(nucl);
  return modNucleotido;
}

tLista* borrar(tLista* modNucleotido, int pos){
  modNucleotido -> moveToPos(pos);
  modNucleotido -> erase();
  return modNucleotido;
}

tLista* intercambiar(tLista* modNucleotido, int pos, tElemLista nucl){
  modNucleotido -> moveToPos(pos);
  modNucleotido -> exchange(nucl);
  return modNucleotido;
}

void secNucleotidos(){
  fstream fileStream;
  int largSecBase, cantSecuencias, cantModificaciones, pos;
  string secBase, parametro;
  tElemLista nucl, nuclBase;


  fileStream.open("secuencias-nucleotidos.txt", ios::in);

  fileStream >> largSecBase;

  tLista* originNucelotido = new tLista[largSecBase];
  tLista* modNucleotido = new tLista[largSecBase];
  
  nuclBase = fileStream.get();
  for (int i = 0; i < largSecBase; i++){
    nuclBase = fileStream.get();
    cout << nuclBase << endl;
    originNucelotido -> insert(nuclBase);
  }

  fileStream >> cantSecuencias;

  tLista** newNucleotidos = new tLista*[cantSecuencias];

  for (int i = 0; i < cantSecuencias; i++){
    modNucleotido = originNucelotido;
    fileStream >> cantModificaciones;
    for (int j = 0; j < cantModificaciones; j++){
      fileStream >> parametro;
      if (parametro == "INSERTAR"){
        fileStream >> pos;
        fileStream >> nucl;
        modNucleotido = insertar(modNucleotido, pos, nucl);
      } else if (parametro == "BORRAR"){
        fileStream >> pos;
        modNucleotido = borrar(modNucleotido, pos);
      } else if (parametro == "INTERCAMBIAR") {
        fileStream >> pos;
        fileStream >> nucl;
        modNucleotido = intercambiar(modNucleotido, pos, nucl);
      }
    }
    newNucleotidos[i] = modNucleotido;
  }

  fileStream.close();

  fileStream.open("secuecias-reconstruidas.txt", ios::out);

  for (int i = 0; i < cantSecuencias; i++){
    newNucleotidos[i] -> moveToStart();
    for (int j = 0; j < newNucleotidos[i] -> getSize(); j++){
      cout << newNucleotidos[i] -> getValue() << endl;
      fileStream << newNucleotidos[i] -> getValue();
      newNucleotidos[i] -> next();
    }
    fileStream << endl;
  }

  fileStream.close();
  delete[] newNucleotidos;
}

int main(){
  secNucleotidos();
  return 0;
}
