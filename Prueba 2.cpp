//Listas de la suerte

#include <iostream>
using namespace std;

/*En el mundo Cplusplusiano, cada persona puede comprar una
 vez por día una tarjeta de la suerte, generada a base del
 nombre de la persona. Además, una persona puede 
 intercambiar las tarjetas de la suerte con otra persona.
 Luego, al final del día se utiliza la fecha de nacimiento
 y la tarjeta para calcular el puntaje de la suerte de una
 persona.*/
 
/*El struct Persona presentado a continuación que almacena:
- string nombre: corresponde al nombre de la persona
- char fecha[11]: corresponde a la fecha de nacimiento de la persona
- AAAA-MM-DD, por ejemplo 1999-01-10
- int tamanio_tarjeta: corresponde a la cantidad de 
  numeros en la tarjeta
- int* tarjeta: corresponde a un punteo a un arreglo de
  enteros
- bool quiere_intercambiar: corresponde a un booleano indicando si quiere 
  intercambiar o no la persona*/

struct Persona {
    string nombre ;
    char fecha [11];
    int tamanio_tarjeta ;
    int * tarjeta ;
    bool quiere_intercambiar ;
};


//Las personas serán ingresadas por entrada estándar con el siguiente formato:
/* p
nombre_1 fecha_1 quiere_intercambiar_1
nombre_2 fecha_2 quiere_intercambiar_2
.
.
.
nombre_p fecha_p quiere_intercambiar_p */

/*Las personas inicialmente no tienen tarjeta de la suerte. El nombre no 
puede contener espacios o caracteres especiales. quiere_intercambiar será 
0 o 1 (donde 0 es que no quiere y 1 es que si quiere).
Para que la persona en la posición i intercambie su tarjeta con otra persona
se debe cumplir que:
• La persona en la posición i debe querer intercambiar.
• Debe buscar una persona en otra posición que quiera intercambiar, además 
esa persona debe tener algún número en común con la persona en la posición i.
Si el intercambio se realiza, la persona en la posición i deja de querer 
intercambiar.*/

//En caso de empate, la persona en la menor posición se considera el ganador.

//Se debe implementar las siguientes funciones:

/* funcion int* comprarTarjeta(string nombre, int dia, 
int &m): recibe dos parámetros, el nombre de la persona que
quiere comprar, el día en que se compra la tarjeta y el 
tamaño del arreglo que se va a retornar. Debe retornar un 
arreglo de enteros de igual tamaño que el nombre, dónde 
en la posición i se encontrará el valor nombre[i] %dia.*/

/*//inicializar un arreglo en 0
int main(){
    int [10];
    
    for (int i=0; i<10; i++){
        n[i] = 0
    }
}*/
//comprat = comprarTarjeta(nombre,dia,nombre.length())


int* comprarTarjeta(string nombre, int dia, int &m){

    m = nombre.length(); //por si m no tiene valor
    int* arr = new int[m]; 

    //inicializar un arreglo
    for (int i = 0; i <m; i++){
        // cuando dia sea 1, el arreglo sera de 0
        arr[i] = nombre[i] % dia ; 
    }
    return arr;
}

/*funcion void intercambiarTarjeta(Persona* p1, Persona* p2)
: recibe dos personas como parámetro se debe intercambiar
las tarjetas entre las dos personas. */


void intercambiarTarjeta(Persona* p1, Persona* p2){
    int* aux = 0;
    aux = p1->tarjeta;
    p1->tarjeta = p2->tarjeta;
    p2->tarjeta = aux;
}
/*int puntaje(Persona* p1): recibe una persona y debe 
retornar un  entero correspondiente al puntaje de la 
persona, que corresponderá al siguiente valor:
tamanio
X_tarjeta−1
i=0
p1 → tarjeta[i] ∗ p1 → fecha[i %10]*/

int puntaje(Persona* p1){
    int n = p1->tamanio_tarjeta;

    int puntaje = 0;
    
    for (int i=0; i< n; i++){
        puntaje += (p1->tarjeta[i]) * (p1->fecha[i%10]);
    }
    return puntaje;

}

/*Persona* unDia(Persona* personas, int dia): recibe un arreglo de personas,
debe comprar una tarjeta a cada persona utilizando el parámetro dia, luego 
que cada persona intente intercambiar hasta que sea imposible seguir 
intercambiando tarjetas. Se debe partir siempre por la persona en la posición
0 hasta la persona en la posición p − 1. Finalmente, debe retornar la persona
que haya obtenido el mayor puntaje.*/

//Persona* unDia(Persona* personas, int dia){ Alvaro }
/*void variosDias(Persona* personas, int cant_dias): recibe un arreglo de personas y la cantidad
de dias en total a realizar. Debe llamar a la función unDia pasando por parámetro los días 1 hasta
cant_dias. Por cada día, debe mostrar por pantalla el nombre, fecha de nacimiento y puntaje de la
persona que obtuvo el mayor ese día.*/

//void variosDias(Persona* personas, int cant_dias){ Alvaro }



#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>

using namespace std;
    
struct Persona{
    string nombre;
    char fecha[11];
    int tamanio_tarjeta;
    int* tarjeta;
    bool quiere_intercambiar;
};

int l;


int* comprarTarjeta(string nombre, int dia, int &m){
    //Resumen: Crea las tarjetas de enteros para las personas
    int* arr = new int[m]; 
    cout<<nombre<<endl;

    cout<<"[";
    for(int j=0; j<m; j++){
        arr[j] = nombre[j] % dia ;

        cout<<arr[j]<<",";
    }
    cout<<"]\n";
    return arr;
};

void intercambiarTarjeta(Persona* p1, Persona* p2){
    //Resumen: Intercambia las tarjetas de las dos personas.
    int* aux = 0;
    aux = p1->tarjeta;
    p1->tarjeta = p2->tarjeta;
    p2->tarjeta = aux;
};

int puntaje(Persona* p1){
    int puntaje = 0, sum;
    int arg[11];

    for (int i=0; i<p1->tamanio_tarjeta; i++){
        arg[i] = p1->fecha[i];
        cout<<p1->fecha[i];
    }
    cout<<endl;

    for (int z=0; z< (p1->tamanio_tarjeta); z++){
        sum = (p1->tarjeta[z])* arg[z%10];
        puntaje += sum;
    }
    cout<<"nombre "<<p1->nombre<<endl;
    cout<<"puntaje "<<puntaje<<endl;

    delete[] p1 -> tarjeta; 
    return puntaje;
};

Persona* unDia(Persona* personas, int dia){ 
    //Resumen: Esta función se encarga de verificar que todas las personas tengan una tarjeta de la suerte, ayudar a filtrar quienes quieren hacer el intercambio de tarjetas de la suerte y ver que persona sacó el mayor puntaje.
    Persona *ganadorDia= &personas[0];//Un arreglo de struct que guarda los datos del ganador del dia.
    int puntos= 0, puntosMax= -1;//Dos variables tipo entero que se encargan de guardar los puntos y el que saco más puntos

    int size=l; //*Calcula el largo del arreglo personas.
    
    if(dia==1){
        for(int k=0; k<size; k++){
            int m = personas[k].nombre.length();//Variable entero que guarda la informacion del largo del arreglo de la funcion comprar tarjeta.
            personas[k].tamanio_tarjeta = m;
            cout<<"tamanio tarjeta "<< m <<endl;
            delete[] personas[k].tarjeta;
            personas[k].tarjeta=comprarTarjeta(personas[k].nombre, dia, m );
        }
    }


    for(int i = 0; i<size; i++){
        if(i!=0){
            int m = personas[i].nombre.length();//Variable entero que guarda la informacion del largo del arreglo de la funcion comprar tarjeta.
            personas[i].tamanio_tarjeta = m;
            delete[] personas[i].tarjeta;
            personas[i].tarjeta=comprarTarjeta(personas[i].nombre, dia, m );
        }
    
        if(personas[i].quiere_intercambiar==true){
            for(int j=i; j<size; j++){
                j++;
                if(personas[j].quiere_intercambiar==true && j<size){
                    intercambiarTarjeta(&personas[i], &personas[j]);
                }
            }
        }

        puntos= puntaje(&personas[i]);
        if(puntos>puntosMax){
            puntosMax=puntos;
            ganadorDia= &personas[i];
        }

    } 

    return ganadorDia;// retorna los datos del ganador del dia
}

void variosDias(Persona* personas,int cant_dias ){
    //Resumen: Se encaraga en mostrar por pantalla los resultados de los ganadores de los dias.
    Persona *ganador= new Persona[1];//Es un arreglo de struct que se encarga de guardar los datos del ganador para mostrarlos en pantalla.

    for(int i=1; i<=cant_dias; i++){
        cout<<"Dia "<<i<<endl;
        ganador=unDia(personas, i);


        cout<<ganador->nombre<<' '<<ganador->fecha<<' '<<puntaje(ganador)<<endl;
    }

    
    delete[] ganador -> tarjeta;
    delete[] personas;
};



void ListasDeLaSuerte(int l){
    //Resumen: Recibe todos los parametros necesarios y los trabaja para que después esten listos para ser usados en las otras funciones
    Persona p, *personas; //Se crean dos variables, p para recibir los datos y aprovechar las virtudes del struct y personas el arreglo donde se guardaran los datos de entrada
    int cant_dias;//se declara una variable para las cantidades de dias

    string *listaPersonas = new string[l];//Se crea un arreglo de string para guardar los datos de las diferentes personas
    
    cin.ignore();
    for(int i=0; i<l; i++){
        cout<<"escriba un nombre: \n";
        getline(cin, p.nombre);
        listaPersonas[i]+=p.nombre;
    }

    cout<<"Ingrese las cantidad de dias: ";
    cin>>cant_dias;

    personas= new Persona[l]; //Se crea un arreglo de struct para que después puedan ser usados en las futuras funciones.
    for(int i=0; i<l; i++){
        string dato=listaPersonas[i];//Guarda el dato de una persona como un string.
        string nombre;//Un string para guardar el nombre de la persona.
        int j=0;    //Es un indice que ayuda para recorrer cada caracter del dato.

        while(dato[j] != ' '){
            nombre+=dato[j];
            j++;
        }

        j++;
    
        for(int r=0 ;r<9; r++){
            strcpy(&personas[i].fecha[r],&dato[j]);
            cout<<personas[i].fecha[r]<<endl;

            j++;
        }

        j++;
    
        if(dato[j] == '1'){
            personas[i].quiere_intercambiar='1';
        }else{
            personas[i].quiere_intercambiar='0';
        }

        personas[i].nombre=nombre;
        personas[i].tamanio_tarjeta=0;
        personas[i].tarjeta=NULL;

        cout<<"nombre "<<personas[i].nombre<<endl;
        cout<<"persona quiere intercambiar "<<personas[i].quiere_intercambiar<<endl;
    }


    variosDias(personas, cant_dias);

    delete[] p.tarjeta;
    delete[] listaPersonas;
    delete[] personas;
};

int main(){
    cin>>l;
    ListasDeLaSuerte(l);

    return 0;
}
