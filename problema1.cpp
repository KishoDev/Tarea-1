#include <iostream>
#include <fstream>
#include <string>
#include "lista.hpp"

using namespace std;

/*****
* void secNucleotidos()
******
* RESUMEN:
*     Ejecución del programa principal. Se abre el archivo "secuencias-nucleotidos.txt" y recibe la información contenida. Se ejecutan las 
*     instrucciones de inserción, borrado y cambio de nucleótidos n veces para cada nucleótido a modificar a base del nucleótido base dado.
*     Tras realizar las instrucciones dadas en el archivo, lo cierra y abre el archivo de escritura "secuencias-reconstruidas.txt", en donde
*     se inserta los nucleótidos modificados.
******
*     No retorna nada ya que es una función void.
*****/
void secNucleotidos(){
  fstream fileStream;
  int largSecBase, cantSecs, cantMods;
  string secBase, mod;
  string stringNewNucl = "";
  unsigned int pos;
  char nucl;

  fileStream.open("secuencias-nucleotidos.txt", ios::in);
  
  // VERIFICA SI SE ABRIÓ EL ARCHIVO A LEER.
  if (!fileStream.is_open()){
    cout << "Error al abrir el archivo 'secuencias-nucleotidos.txt!'" << endl;
    exit(1);
  }

  fileStream >> largSecBase;
  fileStream >> secBase;
  fileStream >> cantSecs;

  // LISTA DE LISTAS ENLAZADAS
  tLista** newNucls = new tLista*[cantSecs];
  
  // A CADA LISTA ENLAZADA DE LA LISTA SE INSERTA EL NUCLEÓTIDO BASE
  for (int i = 0; i < cantSecs; i++){

    *(newNucls + i) = new tLista; // SE CREA UNA LISTA ENLAZADA PARA CADA ELEMENTO DE LA LISTA.
    newNucls[i] -> moveToStart();

    for (int j = 0; j < largSecBase; j++){
      newNucls[i] -> insert(secBase[j]);
      newNucls[i] -> next();
    }
  }
  
  // CICLO QUE SE EJECUTA PARA N SECUENCIAS
  for (int i = 0; i < cantSecs; i++){

    fileStream >> cantMods;
    
    // CICLO QUE SE EJECUTA PARA N CANTIDAD DE INSTRUCCIONES DE MODIFICACIONES DADAS
    for (int j = 0; j < cantMods; j++){

      fileStream >> mod;
      fileStream >> pos;
      newNucls[i] -> moveToPos(pos);

      if (mod == "INSERTAR"){
        
        fileStream >> nucl;
        newNucls[i] -> insert(nucl);
        
      } else if (mod == "BORRAR"){
        
        newNucls[i] -> erase();
        
      } else if (mod == "INTERCAMBIAR"){

        fileStream >> nucl;
        newNucls[i] -> exchange(nucl);
        
      }
    }
  }

  fileStream.close();
  fileStream.open("secuencias-reconstruidas.txt", ios::out);
  
  // VERIFICA SI EL ARCHIVO DE ESCRITURA SE ABRIÓ
  if (!fileStream.is_open()){
    cout << "Error al abrir el archivo 'secuencias-reconstruidas.txt'!" << endl;
    exit(1);
  }

  for (int i = 0; i < cantSecs; i++){
    fileStream << newNucls[i] -> listToString() << endl;
  }
  
  fileStream.close();
  
  // LIBERACIÓN DE MEMORIA DINÁMICA
  for (int i = 0; i < cantSecs; i++) { // LIBERA LA MEMORIA DINÁMICA DE CADA LISTA ENLAZADA CREADA EN LA LISTA. 
    delete *(newNucls + i); 
  } 
  delete[] newNucls; 
}

