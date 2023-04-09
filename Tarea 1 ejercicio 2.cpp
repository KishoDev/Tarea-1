#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

struct Persona{
    string nombre;
    char fecha[11];
    int tamanio_tarjeta;
    int* tarjeta;
    bool quiere_intercambiar;
};

int* comprarTarjeta(string nombre, int dia, int &m){


    return 0;
};

void intercambiarTarjeta(Persona* p1, Persona* p2){



};

int puntaje(Persona* p1){



    return 0;
};

Persona* unDia(Persona* personas, int dia){

    return 0;
};

void variosDias(Persona* personas, int cant_dias){


};
void filtrardatos(dato){ //conectar las variables al codigo y a los structs, escribir bien las variables
    
    string nombre;
    char fecha[11];
    bool inter;
    
    int i=0;
    while(dato[i] != ' '){
        cout<<dato[i]<<endl;
        nombre+=dato[i];
        i++;
    };
    i++;
    
    for(int r=0 ;r<10; r++){
        rut[r]=dato[i];
        cout<<r<<"_"<<dato[i]<<endl;
        i++;
    };
    i++;
    
    if(dato[i] == '1'){
        inter=true;
    }else{
        inter=false;
    };
    
    
};

int main(){
    //Recibir los datos y guardarlos en un arreglo, para luego Separarlos en sus respectivas variales con ayuda del struct. Listo
    //Comprobar si los datos estan entregados correctamente (Ver si el nombre no tienen espacios o caracteres especiales)
    //Comprobar si la persona cuenta con tarjeta de la suerte, si no tiene hay que generarla
    //Usamos la funcion variosDias para ver por cuantos días repetir la generacion de puntajes

    //Ahora el codigo comienza a trabajar

    //Comienza un ciclo hasta que se terminen los días
    //Comprobar cuales personas quieren intercambiar su tarjeta de la suerte y aplicar la funcion Intercambiar tarjeta
    //Calcular el puntaje de cada persona y mostrar en pantalla al ganador del día

    //Una vez terminado el ciclo, se muestra en pantalla la persona que obtuvo un mayor puntaje
    Persona p;
    string *personas;
    int n;
    cin>>n;

    personas = new string[n]    
    cin.ignore();
    for(int i=0; i<n; i++){
        cout<<"escriba un nombre: \n";
        getline(cin, p.nombre);
        personas[i]+=p.nombre;

    };    
    
    delete[] personas;
    return 0;
}

//Dudas o cuestionaimentos
/*


*/
