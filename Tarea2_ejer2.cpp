//Tarea2_ejer2

#include<iostream>
#include<string>
#include<cstring>
#include "TDA de ABB.hpp"



using namespace std;

void Encender(int i){

}

void CuantosEncender(int i){

}

void PararPrograma(){

}

void LucesporArreglar(){
	bool flag=true;
	while(flag){
		string entrada, orden;
		int espacio, pos, aux;

		getline(cin, entrada);

		if(entrada == "PARAR_PROGRAMA"){
			flag=false;
			PararPrograma();
		}

		espacio= entrada.find(' ');
		orden= entrada.substr(0,espacio);
		pos= stoi(entrada.substr(espacio+1, entrada.length()));
		//cout<<espacio<<'\n'<<orden<<'\n'<<pos<<endl;
		
		if(orden == "ENCENDER"){
			Encender(pos);
		}
		
		if(orden == "CUANTOS_ENCENDER"){
			CuantosEncender(pos);
		}
	}
}


int main(){
	LucesporArreglar();
	return 0;
}