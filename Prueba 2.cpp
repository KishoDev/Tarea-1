/*
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

int l;  //Una variable global para guardar el numero de personas a ingresar


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



void intercambiarTarjeta(Persona* p1, Persona* p2){  

    int* aux = new int[p1->tamanio_tarjeta];
    int* aux2 = new int[p2->tamanio_tarjeta];


cout<<"aux [";
    for (int i=0; i<p1->tamanio_tarjeta; i++){
        aux[i] = p1->tarjeta[i];
        cout<<aux[i]<<","; 
    }
    cout<<"]\n";

    cout<<"aux2 [";
    for (int j=0; j<p2->tamanio_tarjeta; j++){
        aux2[j] = p2->tarjeta[j];
        cout<<aux2[j]<<",";
    }

    cout<<"]\n"<<endl;

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

    cout<<"Nombre "<<p1->nombre<<endl;
    cout<<"[";
    for (int i=0; i<p1->tamanio_tarjeta; i++){
        cout<<p1->tarjeta[i]<<",";
        }
    cout<<"]\n";

        cout<<"Nombre "<<p2->nombre<<endl;
    cout<<"[";
    for (int i=0; i<p2->tamanio_tarjeta; i++){
        cout<<p2->tarjeta[i]<<",";
        }
    cout<<"]\n";

};


int puntaje(Persona* p1){
    int puntaje = 0, sum;

    cout<<"Nombre "<<p1->nombre<<endl;
    cout<<"[";
    for (int i=0; i<p1->tamanio_tarjeta; i++){
        cout<<p1->tarjeta[i]<<",";
        }
    cout<<"]\n";
    
    for (int z=0; z< (p1->tamanio_tarjeta); z++){
        sum = (p1->tarjeta[z])* p1->fecha[z%10];
        cout<<"Tar "<<p1->tarjeta[z]<<"   Fecha "<<p1->fecha[z%10]<<endl;
        puntaje += sum;
    }

    cout<<"Puntaje de "<<p1->nombre<<": "<<puntaje<<endl;

    return puntaje;
};



Persona* unDia(Persona* personas, int dia){ 
    cout<<"Dia "<<dia<<endl;
    cout<<endl;
    Persona *ganadorDia= &personas[0];
    int puntos= 0, puntosMax= -1;
    int size=l; 
    cout<<"punto 1"<< endl;
    if(dia==1){
        for(int k=0; k<size; k++){
            int m = personas[k].nombre.length();
            personas[k].tamanio_tarjeta = m;
            delete[] personas[k].tarjeta;
            personas[k].tarjeta = comprarTarjeta(personas[k].nombre, dia, m );
        }
    } else {
        for(int k = 0; k<size; k++){
            int m = personas[k].nombre.length();
            personas[k].tamanio_tarjeta = m;
            //delete[] personas[k].tarjeta;
            personas[k].tarjeta = comprarTarjeta(personas[k].nombre, dia, m );
        }
        cout<<endl;
    }
    
    for(int i = 0; i<size; i++){
        int h = 1;
        bool se_puede = false;
        while(personas[i].quiere_intercambiar==true && h<=size){
            if(personas[h].quiere_intercambiar==true && (h!=i)){
                for (int u=0; u<personas[i].tamanio_tarjeta ; u++){
                    for (int g=0; g<personas[h].tamanio_tarjeta; g++){
                        if (personas[i].tarjeta[u] == personas[h].tarjeta[g]){
                            se_puede = true;
                            break;
                        }
                    }
                }
            
            if (se_puede){
                cout<<"p1 "<<personas[i].nombre<<" y p2 "<<personas[h].nombre<<endl;
                intercambiarTarjeta(&personas[i], &personas[h]);
                personas[i].quiere_intercambiar = false;
            };
            };
            h++;
        };

        puntos= puntaje(&personas[i]);
        if(puntos>puntosMax){
            puntosMax=puntos;
            ganadorDia= &personas[i];
        }

    }
    return ganadorDia;
}



void variosDias(Persona* personas,int cant_dias ){

    Persona *ganador;
    for(int i=1; i<=cant_dias; i++){
        ganador = unDia(personas, i);

        cout<<ganador->nombre<<' '<<ganador->fecha<<' '<<puntaje(ganador)<<endl;
    }
}


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
        
        for (int v=0; v < f.length() ;v++){
            personas[i].fecha[v] = f[v];
        };

        j++;
    
        if(dato[j] == '0'){
            personas[i].quiere_intercambiar = false;
        }else{
            personas[i].quiere_intercambiar = true;
        }

        personas[i].nombre = nombre;
        personas[i].tamanio_tarjeta = 0;
        personas[i].tarjeta= NULL;
    }

    variosDias(personas, cant_dias);

    for (int i = 0; i < l; i++){
        delete[] personas[i].tarjeta;
    }

    delete[] listaPersonas;
    delete[] personas;
};


int main(){
    cin>>l;
    ListasDeLaSuerte(l);

    return 0;
};
*/



//trabajando
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

int* comprarTarjeta(string nombre, int dia, int &m){
    cout<<"holaa"<<endl;
    int* arr = new int[m]; 
    cout<<"Nombre "<<nombre<<endl;

    cout<<"tamanio "<<m<< endl ;
    cout<<"[";
    for(int j=0; j<m; j++){           
        arr[j] = (nombre[j] % dia) ;
        cout<<arr[j]<<",";
        }
    cout<<"]\n"<<endl;
        return arr;

};

/*---------------------------------------------------------------------------------------*/

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

int puntaje(Persona* p1){
    int puntaje = 0, sum;
    for (int z=0; z< (p1->tamanio_tarjeta); z++){
        sum = (p1->tarjeta[z])* p1->fecha[z%10];
        puntaje += sum;
    }

    cout<<"El puntaje de "<<p1->nombre<<" es "<<puntaje<<endl;

    return puntaje;
};
/*---------------------------------------------------------------------------------------*/

Persona* unDia(Persona* personas, int dia){ 

    cout<<"Dia "<<dia<<endl;
    Persona *ganadorDia= &personas[0];
    int puntos= 0, puntosMax= -1;
    int size=l;
    
    if(dia==1){
        for(int k=0; k<size; k++){
            int m = personas[k].tamanio_tarjeta;
            delete[] personas[k].tarjeta;
            personas[k].tarjeta = comprarTarjeta(personas[k].nombre, dia, m );
        }
    } 
    if(dia== 2){
        for(int i = 0; i<size; i++){
            //imprimir la tarjeta
            cout<<"si se puede"<<endl;
            cout<<personas[i].nombre<<endl;
            cout<<"antes [";           
            for(int j=0; j<personas[i].tamanio_tarjeta; j++){
                cout<<personas[i].tarjeta[j]<<",";
            } cout<<"]\n"<<endl;
            //fin
            int m = personas[i].tamanio_tarjeta;
            delete[] personas[i].tarjeta;
            //imprimir la tarjeta
            cout<<"despues [";
            for(int j=0; j<personas[i].tamanio_tarjeta; j++){
                cout<<personas[i].tarjeta[j]<<",";
            } cout<<"]\n"<<endl;
            //fin
            personas[i].tarjeta = comprarTarjeta(personas[i].nombre, dia, m);
        }
    }

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

void variosDias(Persona* personas,int cant_dias ){
    Persona *ganador;
    int tam=0, z=0;

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
        cout<<"otra iteracion"<<endl;
        ganador = unDia(personas, i);
        cout<<"ganador "<<ganador->nombre<<endl;

        //cout<<ganador->nombre<<' '<<ganador->fecha<<' '<<puntaje(ganador)<<endl;

        for(int i=0; i<tam; i++){
            personas[arr[i]].quiere_intercambiar= true;
        }
    }
}

/*---------------------------------------------------------------------------------------*/

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

        personas[i].fecha[10]= ' ';
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

int main(){
    cin>>l;
    ListasDeLaSuerte(l);

    return 0;
}
