#include<iostream>
#include<string>
#include<cstring>
#include "TDA de ABB.hpp"

using namespace std;

int main(){
    tABB arbol;
    int dato, opcion;

    do{
        cout<<"   - MENU -   "<<endl;
        cout<<"1. Insertar (insert)"<<endl;
        cout<<"2. Encontrar (find)"<<endl;
        cout<<"3. Busca el 1er valor que sea <= x (lower_bound)"<<endl;
        cout<<"4. Mostrar arbol (mostrarArbol)"<<endl;
        cout<<"5. Eliminar (clear)"<<endl;
        cout<<"6. Salir";
        cout<<"\nOpcion: ";
        cin>>opcion;

        switch(opcion){
            case 1: cout<<"\nInserte numero: ";
                    cin>>dato;
                    arbol.insert(dato);
                    cout<<endl;
                    break;

            case 2: cout<<"\nInserte numero: ";
                    cin>>dato;

                    if (arbol.find(dato)){
                        cout<<"Encontrado";
                    }else{
                        cout<<"No encontrado";
                    }
                    cout<<endl;
                    system("pause");
                    break;

            case 3: cout<<"\nInserte numero: ";
                    cin>>dato;
                    int i;
                    i = arbol.lower_bound(dato);
                    cout<<i<<" <= "<<dato;
                    cout<<endl;
                    system("pause");
                    break;

            case 4: cout<<"\nMostrando el Arbol"<<endl;
                    arbol.mostrarArbol();
                    cout<<endl;
                    system("pause");
                    break;

            case 5: cout<<"\nEliminando...";
                    arbol.clear();
                    cout<<"\nMostrando Arbol actual"<<endl;
                    arbol.mostrarArbol();
                    cout<<endl;
                    system("pause");
                    break;            
        }
        system("cls");
    }while(opcion != 6);

    return 0;
}