//Tarea2_ejer2

#include<iostream>
#include<string>
#include<cstring>
#include "TDA de ABB.hpp"

using namespace std;

class AvenidaLuces{
	private:
		int PostesEncendidos;
		tABB postes;	//En el ABB vamos a guardar todos los postes que están encendidos
	public:
		AvenidaLuces(){
			int PostesEncendidos=0;
		}
		~AvenidaLuces(){
			int PostesEncendidos=NULL;
		}

		void Encender(int i);
		void CuantosEncender(int i);
		void PararPrograma();

};

void AvenidaLuces::Encender(int i){
	//Enciende el poste numero i, si el poste ya esta encendido entonces no ocurre nada
	if(postes.find(i) == false){
		postes.insert(i);
		PostesEncendidos++;
	}

}

void AvenidaLuces::CuantosEncender(int i){


}

void AvenidaLuces::PararPrograma(){
	cout<<PostesEncendidos<<endl;
}


void LucesporArreglar(){
	bool flag=true;

	while(flag){
		AvenidaLuces principal;
		string entrada, orden;
		int espacio, pos;

		getline(cin, entrada);

		if(entrada == "PARAR_PROGRAMA"){
			flag=false;
			principal.PararPrograma();
		}else{
			espacio= entrada.find(' ');
			orden= entrada.substr(0,espacio);
			pos= stoi(entrada.substr(espacio+1, entrada.length()));
			//cout<<espacio<<'\n'<<orden<<'\n'<<pos<<endl;	
		}
		
		if(orden == "ENCENDER"){
			principal.Encender(pos);
		}
		
		if(orden == "CUANTOS_ENCENDER"){
			principal.CuantosEncender(pos);
		}
	}
}


int main(){
	LucesporArreglar();
	return 0;
}
