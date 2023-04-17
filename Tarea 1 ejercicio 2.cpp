#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstring>

using namespace std;

struct Persona{
    string nombre;
    char fecha[11];
    int tamanio_tarjeta;
    int* tarjeta;
    bool quiere_intercambiar;
};

int* comprarTarjeta(string nombre, int dia, int &m){
    //Resumen: Crea las tarjetas de la suerte de las personas

    return 0; //Retorna un arreglo de enteros
};

void intercambiarTarjeta(Persona* p1, Persona* p2){
    //Resumen: 



};

int puntaje(Persona* p1){
    //Resumen: 


    return 0;
};


Persona* unDia(Persona personas, int dia){ 
    //Resumen: 
    Persona *ganadorDia= &personas[0];
    int puntos= 0, puntosMax= -1;

    int size=sizeof(personas)/sizeof(personas[0]); //verificar de que funcione

    for(int i = 0; i<size; i++){
    
        if(dia == 1){
            for(int j=0; j<size; j++){
                int m=personas.nombre.length();
                comprarTarjeta(personas.nombre, dia,m )
            }
        }
        
        if(personas[i].quiere_intercambiar==true){
            for(int j=i; j<size; j++){
                j++;
                if(personas[j].quiere_intercambiar==true && j<size){
                    intercambiarTarjetas(personas[i], personas[j]);
                }
            }
        }

        puntos= puntaje(personas[i]);
        if(puntos>puntosMax){
            puntosMax=puntos;
            ganadorDia= &personas[i];
        }

    }

    return ganadorDia;
};

void variosDias(Persona* personas,int cant_dias ){
    //Resumen: 
    Persona *ganador= new Persona[1];

    for(int i=1; i<=cant_dias; i++){
        ganador=unDia(*personas, cant_dias);


        cout<<ganador.nombre<<'\0'<<ganador.fecha<<'\0'<<puntaje(ganador)<<endl;
    }
    delete[] ganador;
};


void ListasDeLaSuerte(int &m){
    //Resumen:
    Persona p, *personas; //
    int cant_dias;  //

    string *listaPersonas = new string[m];//
    
    cin.ignore();
    for(int i=0; i<m; i++){
        cout<<"escriba un nombre: \n";
        getline(cin, p.nombre);
        listaPersonas[i]+=p.nombre;
    }

    cout<<"Ingrese las cantidad de dias: ";
    cin>>cant_dias;

    personas= new Persona[m];//
    for(int i=0; i<m; i++){
        string dato=listaPersonas[i];
        string nombre;
        int j=0;

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

    variosDias(personas, cant_dias);
    
    delete[] listaPersonas;
    delete[] personas;
};

int main(){
    cin>>m;
    ListasDeLaSuerte(m);

    return 0;
}

//Dudas o cuestionaimentos
/*


*/
