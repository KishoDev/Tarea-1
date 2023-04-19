#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>

using namespace std;
/*---------------------------------------------------------------------------------------*/    
struct Persona{
    string nombre;
    char fecha[11];
    int tamanio_tarjeta;
    int* tarjeta;
    bool quiere_intercambiar;
};

int numPersonas;  //Una variable global para guardar el numero de personas a ingresar

/*---------------------------------------------------------------------------------------*/

/*****
* int* comprarTarjeta
******
* Resumen:
*   Crea las un arreglo de enteros para las personas, estos arreglos serán sus tarjetas
******
* Input:
*   -string nombre; es el nombre de la persona
*   -int dia; es el numero de dia en que se encuentran  
*   -int &m; es el tamaño del arreglo 
******
* Returns:
*   Retrona arr; que es el arreglo de enteros que contiene la tarjeta de la persona
*****/

int* comprarTarjeta(string nombre, int dia, int &m){
    m = nombre.length();
    int* arr = new int[m]; 

    for (int j = 0; j < m; j++){           
        arr[j] = nombre[j] % dia ;
    }

    return arr;

}

/*---------------------------------------------------------------------------------------*/
/*****
* bool elemento_comun
******
* Resumen:
*   Comprueba si en las tarjetas (arreglo de enteros) de dos personas, existe un elemento en comun.
******
* Input:
*   -Persona* p1; es un arreglo de struct en donde se guarda los datos de una persona 
*   -Persona* p2; es un arreglo de struct en donde se guarda los datos de una persona
******
* Returns:
*   bool, retorna un valor booleano. true si tienen un elemento en común o false si no lo tienen.
*****/

bool elemento_comun(Persona* p1, Persona* p2){
    bool se_puede = false;
    for (int u=0; u < p1->tamanio_tarjeta ; u++){
        for (int g=0; g < p2->tamanio_tarjeta; g++){
            if (p1 -> tarjeta[u] == p2 -> tarjeta[g]){
                se_puede = true;
                return se_puede;
            }}}
    return se_puede;
}

/*---------------------------------------------------------------------------------------*/

/*****
* void intercambiarTarjeta
******
* Resumen:
*   Intercambia las tarjetas (arreglo de enteros) de dos personas.
******
* Input:
*   -Persona* p1; es un arreglo de struct en donde se guarda los datos de una persona 
*   -Persona* p2; es un arreglo de struct en donde se guarda los datos de una persona
******
* Returns:
*   No retorna nada ya que es una funcion void
*****/

void intercambiarTarjeta(Persona* p1, Persona* p2){  
    int aux = p1 -> tamanio_tarjeta;

    p1 -> tamanio_tarjeta = p2 -> tamanio_tarjeta;
    p2 -> tamanio_tarjeta = aux;

    int *aux2 = p1 -> tarjeta;

    p1 -> tarjeta = p2 -> tarjeta;
    p2 -> tarjeta = aux2;
}
/*---------------------------------------------------------------------------------------*/

/*****
* int puntaje
******
* Resumen:
*   Calcula los puntos que tiene la persona, utilizando la tarjeta de enteros y su fecha.
******
* Input:
*   - Persona *p1: Un puntero apuntando a la persona a la que se le va a calcular el puntaje.
******
* Returns:
*   int, Retornara el puntaje total que obtuvo la persona.
*****/

int puntaje(Persona* p1){
    int puntaje = 0, sum;

    for (int z = 0; z < ( p1 -> tamanio_tarjeta); z++) {
        sum = (p1 -> tarjeta[z]) * p1 -> fecha[z%10];
        puntaje += sum;
    }

    return puntaje;
};
/*---------------------------------------------------------------------------------------*/

/*****
* Persona* unDia
******
* Resumen:
*   Se encarga de verificar que todas las personas tengan una tarjeta de la suerte, ayudar a filtrar quienes quieren hacer el 
*   intercambio de tarjetas de la suerte y por último determina que persona sacó el mayor puntaje.
******
* Input:
*   -Persona* personas; es un arreglo de struct que guarda toda la informacion de las personas
*   -int dia; es un entero que indica en que dia esta la funcion
******
* Returns:
*   Retorna la dirección de memoria del struct del ganador.
*****/

Persona* unDia(Persona* personas, int dia){ 
    for (int i = 0; i < numPersonas; i++) {
        personas[i].tarjeta = comprarTarjeta(personas[i].nombre, dia, personas[i].tamanio_tarjeta);
    }

    for (int i = 0; i < numPersonas - 1;  i++) {
        for (int j = i + 1; j < numPersonas; j++) {
            if (personas[i].quiere_intercambiar == 1 && personas[j].quiere_intercambiar == 1 && elemento_comun(&personas[i], &personas[j])){
                intercambiarTarjeta(&personas[i], &personas[j]);
            }
        }
    }

    int puntajeGanador = -1;
    int posGanador;
    for (int i = 0; i < numPersonas; i++) {
        if (puntajeGanador < puntaje(&personas[i])){
            puntajeGanador = puntaje(&personas[i]);
            posGanador = i;
        }
    }

    return &personas[posGanador];
}
/*---------------------------------------------------------------------------------------*/
/*****
* void variosDias
******
* Resumen:
*   Se dedica hacer repetir la funcion dia hasta que la cantidad de dias se lo indique, también imprime por pantalla los dato del ganador del dia
******
* Input:
*   -Persona* personas; es un arreglo de struct que guarda toda la informacion de las personas.
*   -int cant_dias; es un entero que indica la cantidad de veces que se debe repetir la funcion unDia.
******
* Returns:
*   No retorna nada ya que es una funcion void.
*****/

void variosDias(Persona* personas,int cant_dias ){
    Persona *ganador;
    for (int i = 1; i <= cant_dias; i++){
        cout << "Dia: " << i << endl;

        ganador = unDia(personas, i);

        cout << ganador -> nombre << ' ' << ganador -> fecha << ' ' << puntaje(ganador) << endl;

        for (int i = 0; i < numPersonas; i++){
            delete[] personas[i].tarjeta;
        }
    }
}

/*---------------------------------------------------------------------------------------*/
/*****
*   void ListasDeLaSuerte
******
* Resumen:
*   -Es una función que recive los parametros necesario para después ejecutarlos en las futuras funciones, su principal rol es de organizar los datos y armar el
*    struct Personas y por ultimo libera las memorias dinamicas que se usaron. 
******
* Returns:
*   No retorna nada ya que es una funcion void.
*****/

void ListasDeLaSuerte(){
    Persona p, *personas;
    int cant_dias = 2;

    string *listaPersonas = new string[numPersonas];
    
    cin.ignore();
    for(int i = 0; i < numPersonas; i++){
        getline(cin, p.nombre);
        listaPersonas[i] += p.nombre;
    }

    personas = new Persona[numPersonas];
    for(int i = 0; i < numPersonas; i++){
        string dato = listaPersonas[i];
        string nombrePersona, fechaPersona;
        int j = 0;    
        
        while(dato[j] != ' '){
            nombrePersona += dato[j];
            j++;
        }

        j++;               
    
        fechaPersona = dato.substr(j, j + 11);

        j += 11;
        
        if(dato[j] == '0'){
            personas[i].quiere_intercambiar = false;
        }else{
            personas[i].quiere_intercambiar = true;
        }


        personas[i].nombre = nombrePersona;
        strcpy(personas[i].fecha, fechaPersona.c_str());
        personas[i].tamanio_tarjeta = sizeof(personas[i].nombre);
    }

    variosDias(personas, cant_dias);
    
    delete[] listaPersonas;
    delete[] personas;
};
/*---------------------------------------------------------------------------------------*/
/***********
* Resumen:
*   Pedir el dato de cuantas personas quiere registrar y ese dato lo va a recibir la funcion ListasDeLaSuerte
******
* Input:
*   -int l; es un entero de variable global que indica la cantidad de datos de personas que hay para entregarselo a la funcion ListasDeLaSuerte
******
* Returns:
*   int, retorna 0 si se ejecuta de forma exitosa.
*****/

int main(){
    cin>>numPersonas;
    ListasDeLaSuerte();

    return 0;
}
