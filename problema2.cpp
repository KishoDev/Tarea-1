#include<iostream>
#include<string>
#include "TDA_Heap.cpp"


using namespace std;

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