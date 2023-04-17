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

    //inicializar un arreglo
    for (int i = 0; i <m; i++){
        // cuando dia sea 1, el arreglo sera de 0
        arr[i] = nombre[i] % dia ; 
    }
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
    int puntaje = 0, sum, n;
    int arr[9];
    int j = 0;

    for(int i=0; i<10; i++){
        if (n[i] == '-'){
            j += 1;
        }else{
            
            arr[i-j] = (n[i]);
        };
    };

    for (int z=0; z< (p1->tamanio_tarjeta); z++){
        sum = p1->tarjeta[z]*arr[z%10];
        puntaje += sum;
        cout<<puntaje<<endl;
        cout<<"-------------------------"<<endl;
    }

    return puntaje;
};

Persona* unDia(Persona* personas, int dia){ 
    //Resumen: Esta función se encarga de verificar que todas las personas tengan una tarjeta de la suerte, ayudar a filtrar quienes quieren hacer el intercambio de tarjetas de la suerte y ver que persona sacó el mayor puntaje.
    Persona *ganadorDia= &personas[0];//Un arreglo de struct que guarda los datos del ganador del dia.
    int puntos= 0, puntosMax= -1;//Dos variables tipo entero que se encargan de guardar los puntos y el que saco más puntos

    int size=l; //*Calcula el largo del arreglo personas.

    for(int i = 0; i<size; i++){
    

        int m = personas[i].nombre.length();//Variable entero que guarda la informacion del largo del arreglo de la funcion comprar tarjeta.
        personas[i].tamanio_tarjeta = m;
        comprarTarjeta(personas[i].nombre, dia, m );

        
        if(personas[i].quiere_intercambiar==true){
            for(int j=i; j<size; j++){
                j++;
                if(personas[j].quiere_intercambiar==true && j<size){
                    intercambiarTarjeta(&personas[i], &personas[j]);
                }
            }
        }

        puntos= puntaje(personas[i]);
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
        ganador=unDia(*personas, cant_dias);


        cout<<ganador->nombre<<'\0'<<ganador->fecha<<'\0'<<puntaje(ganador)<<endl;
    }
    delete[] ganador;
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
        };
        j++;
    
        for(int r=0 ;r<9; r++){
            strcpy(&personas[i].fecha[r],&dato[j]);
            j++;
        };
        j++;
    
        if(dato[j] == '1'){
            personas[i].quiere_intercambiar=true;
        }else{
            personas[i].quiere_intercambiar=false;
        };
        personas[i].nombre=nombre;
        personas[i].tamanio_tarjeta=0;
        personas[i].tarjeta=NULL;
    };


    //variosDias(personas, cant_dias);
    delete[] listaPersonas;
    delete[] personas;
};

int main(){
    cin>>l;
    ListasDeLaSuerte(l);

    return 0;
}
