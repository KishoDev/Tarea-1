#include<iostream>
#include<string>
#include "TDA_Heap.hpp"


using namespace std;


/*****
* Void comandos
******
* Recibe los datos de entrada y los clasifica como: string comando;la acción a realizar en el programa, int n; es el numero del usuario o identificadores, string id; es el identificador o usuario, int importancia; es la prioridad del usuario   , string instrucciones; es la instrucción que deberá ejecutarse.
******
* Input:
*  No usa ningún input ya que los datos lo recibe de entrada.
******
* Returns:
* No retorna nada ya que es una función void
*****/

void comandos(){


    bool flag=true;
    string entrada, comando;
    
    while(flag){
        getline(cin, entrada);
        comando = entrada.substr(0,entrada.find(' '));

        if(comando == "TERMINATE"){
            flag= false;
            //Algo de comando
            }

        if(comando == "GET"){
            int n = stoi(entrada.substr(entrada.find(' ') + 1));
            //Algo de comando
        }else if(comando == "PUSHCOMMAND"){
            string id, instrucciones;
            int importancia;
            for(int i =0; i<3; i++){
                entrada= entrada.substr(entrada.find(' ')+1);
                if(i == 0){
                    id= entrada.substr(0, entrada.find(' '));
                }else if(i == 1){ 
                    importancia= stoi(entrada.substr(0, entrada.find(' ') ));
                }else if(i==2){
                    instrucciones= entrada;
                }
            }
            //Algo de comando
        }

    }

}






int main(){
    comandos();
    
    return 0;
}