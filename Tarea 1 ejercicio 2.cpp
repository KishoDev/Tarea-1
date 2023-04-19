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

int l;  //Una variable global para guardar el numero de personas a ingresar

/*---------------------------------------------------------------------------------------*/

/*****
* int* comprarTarjeta
******
* Resumen:
* 	Crea las un arreglo de enteros para las personas, estos arreglos serán sus tarjetas
******
* Input:
* 	-string nombre; es el nombre de la persona
*   -int dia; es el numero de dia en que se encuentran 	
*   -int &m; es el tamaño del arreglo 
*   -int* arr; es el arreglo de enteros en donde se guardara para luego ser retornado
******
* Returns:
* 	Retrona arr; que es el arreglo de enteros que contiene la tarjeta de la persona
*****/

int* comprarTarjeta(string nombre, int dia, int &m){
    int* arr = new int[m]; 
    cout<<"Nombre "<<nombre<<endl;

    cout<<"tamanio "<<m<< endl ;
    cout<<"[";
    for(int j=0; j<m; j++){           
        arr[j] = nombre[j] % dia ;
        cout<<arr[j]<<",";
        }
    cout<<"]\n";
        return arr;

};

/*---------------------------------------------------------------------------------------*/
/*****
* bool elemento_comun
******
* Resumen:
* 	Comprueba si en las tarjetas (arreglo de enteros) de dos personas, existe un elemento en comun.
******
* Input:
*   -Persona* p1; es un arreglo de struct en donde se guarda los datos de una persona 
*   -Persona* p2; es un arreglo de struct en donde se guarda los datos de una persona
*   -int *aux; es un arreglo en donde se almacenara temporalmente la tarjeta de p1 (Ayuda a hacer el intercambio más facil)
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/

bool elemento_comun(Persona* p1, Persona* p2){
    bool se_puede = false;
    for (int u=0; u< p1->tamanio_tarjeta ; u++){
        for (int g=0; g< p2->tamanio_tarjeta; g++){
            if (p1->tarjeta[u] == p2->tarjeta[g]){
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
* 	Intercambia las tarjetas (arreglo de enteros) de dos personas.
******
* Input:
*   -Persona* p1; es un arreglo de struct en donde se guarda los datos de una persona 
*   -Persona* p2; es un arreglo de struct en donde se guarda los datos de una persona
*   -int *aux; es un arreglo en donde se almacenara temporalmente la tarjeta de p1 (Ayuda a hacer el intercambio más facil)
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/

void intercambiarTarjeta(Persona* p1, Persona* p2){  

    int* aux = new int[p1->tamanio_tarjeta];
    int* aux2 = new int[p2->tamanio_tarjeta];

    for (int i=0; i<p1->tamanio_tarjeta; i++){
        aux[i] = p1->tarjeta[i];
    }

    for (int j=0; j<p2->tamanio_tarjeta; j++){
        aux2[j] = p2->tarjeta[j];
    }

    delete[] p1->tarjeta;
    delete[] p2->tarjeta;

    for (int i=0; i<p2->tamanio_tarjeta; i++){
        p1->tarjeta[i] = aux2[i];
    }

    for (int j=0; j<p1->tamanio_tarjeta; j++){
        p2->tarjeta[j] = aux[j];
    }


    p1->tarjeta = aux2;
    p2->tarjeta = aux;

    int g = 0;
    g = p1->tamanio_tarjeta;
    p1->tamanio_tarjeta = p2->tamanio_tarjeta;
    p2->tamanio_tarjeta = g; 

};
/*---------------------------------------------------------------------------------------*/
/*****
* int puntaje
******
* Resumen:
* 	Calcula los puntos que tiene la persona, utilizando la tarjeta de enteros y su fecha
******
* Input:
*   -int puntaje; Es el puntaje total que obtuvo la persona y que va a retornar la funcion
*   -int suma; Es la suma que obtiene la persona en cada iteración de la suma
******
* Returns:
* 	Retornara el puntaje total que obtuvo la persona con su tarjeta de enteros y su fecha
*****/

int puntaje(Persona* p1){
    int puntaje = 0, sum;
    //cout<<endl<<p1->nombre<<" y fecha "<<p1->fecha<<endl;
    for (int z=0; z < (p1->tamanio_tarjeta); z++){
        sum = (p1->tarjeta[z])* p1->fecha[z%10];
        puntaje += sum;
    }

    //cout<<"El puntaje de "<<p1->nombre<<" es "<<puntaje<<endl;

    return puntaje;
};
/*---------------------------------------------------------------------------------------*/
/*****
* Persona* unDia
******
* Resumen:
* 	Se encarga de verificar que todas las personas tengan una tarjeta de la suerte, ayudar a filtrar quienes quieren hacer el intercambio de tarjetas de la suerte y por último determina que persona sacó el mayor puntaje.
******
* Input:
*   -Persona* personas; es un arreglo de struct que guarda toda la informacion de las personas
*   -int dia; es un entero que indica en que dia esta la funcion
*   -Persona* ganadorDia; es un arreglo que se encarga de almacenar los datos de la persona que saco más puntos y mostrarla en pantalla
*   -int puntos; guarda los puntos de cada persona
*   -int puntosMax; guarda los puntos de la persona que saco mayor puntaje y los almacena
*   -int size; una variable entero que guarda la cantidad de personas que hay en el arreglo Persona* personas
*   -int m; es un entero que guarda el largo del arreglo que se debe crear para la función comprarTarjeta
******
* Returns:
* 	Un arreglo de struct con los datos del ganador del dia
*****/
Persona* unDia(Persona* personas, int dia){ 

    cout<<"Dia "<<dia<<endl;
    Persona *ganadorDia= &personas[0];
    int puntos= 0, puntosMax= -1;
    int size=l; 
    
    if(dia==1){
        for(int k=0; k<size; k++){
            int m = personas[k].nombre.length();
            personas[k].tamanio_tarjeta = m;
            delete[] personas[k].tarjeta;
            personas[k].tarjeta = comprarTarjeta(personas[k].nombre, dia, m );
        }
    }


    for(int i = 0; i<size; i++){
        if(i!=0){
            int m = personas[i].tamanio_tarjeta;
            delete[] personas[i].tarjeta;
            personas[i].tarjeta= comprarTarjeta(personas[i].nombre, dia, m );
        }
    }
        //personas que quieren cambiar
    for(int i=0; i<size; i++){
        bool se_puede;
        if(personas[i].quiere_intercambiar==true){
            for(int j = 0; j<size; j++){
                if((i != j) && personas[j].quiere_intercambiar == true){
                    se_puede = elemento_comun(&personas[i], &personas[j]);
                    if (se_puede){
                        intercambiarTarjeta(&personas[i], &personas[j]);
                        personas[i].quiere_intercambiar = false;
                        j = size;
                    }
                }
            }
        }
    }

    for ( int i=0; i<size; i++){
        puntos= puntaje(&personas[i]);
        if(puntos>puntosMax){
            puntosMax=puntos;
            ganadorDia= &personas[i];
        }
    }

    return ganadorDia;
}
/*---------------------------------------------------------------------------------------*/
/*****
* void variosDias
******
* Resumen:
* 	Se dedica hacer repetir la funcion dia hasta que la cantidad de dias se lo indique, también imprime por pantalla los dato del ganador del dia
******
* Input:
*   -Persona* personas; es un arreglo de struct que guarda toda la informacion de las personas.
*   -int cant_dias; es un entero que indica la cantidad de veces que se debe repetir la funcion unDia.
*   -Persona *ganador; es un arreglo de struct que guarda la informacion de la persona que gano el dia.
******
* Returns:
* 	No retorna nada ya que es una funcion void.
*****/

void variosDias(Persona* personas,int cant_dias ){
    Persona *ganador;
    int tam=0, z=0;
    int puntajeGanador;


    for(int i=0; i<l; i++){
        if(personas[i].quiere_intercambiar==true) tam++;
    }
    int arr[tam];

    for(int i=0; i<l; i++){
        if(personas[i].quiere_intercambiar==true){
            arr[z]=i;
            z++;
        }
    }

    for(int i=1; i<=cant_dias; i++){
        ganador = unDia(personas, i);
        puntajeGanador = puntaje(ganador);

        cout<< ganador->nombre <<" "<< ganador->fecha <<" "<< puntajeGanador <<endl;

        for(int i=0; i<tam; i++){
            personas[arr[i]].quiere_intercambiar= true;
        }
    }
}

/*---------------------------------------------------------------------------------------*/
/*****
*   void ListasDeLaSuerte
******
* Resumen:
* 	Es una función que pide los datos de la personas que quieren registrar, pide la cantidad de dias para así ayuda a ordenar esos datos para prepararlas a las futuras funciones y despues elimina todas la memorias dinamicas que se usaron. 
******
* Input:
*   -int l; es un entero que indica la cantidad de datos de personas que hay
*   -Persona p; Es una variable struct que ayuda a guardar los datos de una persona
*   -Persona *personas; es un arreglo de struct que guarda toda la informacion de las personas de manera ordenada.
*   -string *listaPersonas; es un arreglo de string que guarda los datos de persona de entrada, los datos no estan ordenados.
*   -int cant_dias; es un entero que indica la cantidad de veces que se debe repetir la funcion unDia.
*   -string dato; es un string que almacena el dato de una persona del arreglo listasPersonas
*   -string nombre; es un string que guarda el nombre de una persona para despues ser almacenada en el struct
*   -int j; es un entero que ayuda a indicar la posicion del dato de entrada de la persona.
******
* Returns:
* 	No retorna nada ya que es una funcion void.
*****/

void ListasDeLaSuerte(int l){
    Persona p, *personas;
    int cant_dias;

    string *listaPersonas = new string[l];
    
    cin.ignore();
    for(int i=0; i<l; i++){
        getline(cin, p.nombre);
        listaPersonas[i]+=p.nombre;
    }
    cin>>cant_dias;

    personas = new Persona[l];
    for(int i=0; i<l; i++){
        string dato=listaPersonas[i];
        string nombre;
        int j=0;    
        
        while(dato[j] != ' '){
            nombre+=dato[j];
            j++;
        }

        j++;               
        string f = "";
    
        while(dato[j] != ' '){
            f += dato[j];
            j++;
        };
        
        int large = f.length();
        for (int v=0; v < large ;v++){
            personas[i].fecha[v] = f[v];
        };
        //personas[i].fecha[10]=' ';
        j++;
    
        if(dato[j] == '0'){
            personas[i].quiere_intercambiar = false;
        }else{
            personas[i].quiere_intercambiar = true;
        }

        personas[i].nombre=nombre;

        personas[i].tamanio_tarjeta=nombre.length();
        personas[i].tarjeta=NULL;
    }

    variosDias(personas, cant_dias);

    for (int i = 0; i < l; i++){
        delete[] personas[i].tarjeta;
    }

    delete[] listaPersonas;
    delete[] personas;
};
/*---------------------------------------------------------------------------------------*/
/***********
* Resumen:
* 	Pedir el dato de cuantas personas quiere registrar y ese dato lo va a recibir la funcion ListasDeLaSuerte
******
* Input:
*   -int l; es un entero de variable global que indica la cantidad de datos de personas que hay para entregarselo a la funcion ListasDeLaSuerte
******
* Returns:
* 	int, retorna 0 si se ejecuta de forma exitosa.
*****/
int main(){
    cin>>l;
    ListasDeLaSuerte(l);

    return 0;
}
