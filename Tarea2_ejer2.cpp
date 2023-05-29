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
		//Constructor
		AvenidaLuces(){
			PostesEncendidos = 0;
		}
		//Destructor
		~AvenidaLuces(){
		}

		void Encender(int i);
		void CuantosEncender(int i);
		void PararPrograma();
		int getPostesEncendidos();
		void mostrarArbolp();
};

void AvenidaLuces::mostrarArbolp(){
	postes.mostrarArbol();
}

int AvenidaLuces::getPostesEncendidos(){
	return PostesEncendidos;
}

void AvenidaLuces::Encender(int i){
	//Enciende el poste numero i, si el poste ya esta encendido entonces no ocurre nada
	if(postes.find(i) == false){
		postes.insert(i);
		PostesEncendidos++;
	}
}

void AvenidaLuces::CuantosEncender(int i){
	int postesApagados = 0;
	int x;

	x = postes.lower_bound(i);

	//Cuando no hay poste encendido
	if (x == 0 ){
		while (i >= x){
		postesApagados += 1;
		i--;
		}

	} else {
		//Cuando existe un poste encendido cercano
		while (i > x && postes.find(i) == false){
			postesApagados += 1;
			i--;
		}
	}

	cout<<postesApagados<<endl;
}

void AvenidaLuces::PararPrograma(){
	cout<<PostesEncendidos<<endl;
}


void LucesporArreglar(){
	bool flag=true;

	AvenidaLuces principal;

	while(flag){
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
			//cout<<"Postes encendidos "<<principal.getPostesEncendidos()<<endl;
		}
		
		if(orden == "CUANTOS_ENCENDER"){
			principal.CuantosEncender(pos);
		}

		//cout<<"Arbol"<<endl;
		//principal.mostrarArbolp();
	}
	
}


int main(){
	LucesporArreglar();
	return 0;
}

