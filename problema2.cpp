//Tarea2_ejer2

#include<iostream>
#include<string>
#include<cstring>
#include "TDA de ABB.hpp"

using namespace std;

class AvenidaLuces{
	private:
		int PostesEncendidos;
		tABB postes;
	public:
		AvenidaLuces(){
			PostesEncendidos = 0;
		}
		~AvenidaLuces(){
		}

		void Encender(int i);
		int CuantosEncender(int i);
		void PararPrograma();
};

/*---------------------------------------------------------------------------------------*/
/*****
* void AvenidaLuces::Encender
******
* Resumen:
* 	Si el poste numero i no esta encendido (no se encuentra en el ABB), se enciende (se inserta en el ABB).
******
* Input:
*   -int i; es un entero que representa el número de poste que hay que encender, si no lo está.
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/

void AvenidaLuces::Encender(int i){
	if(postes.find(i) == false){
		postes.insert(i);
		PostesEncendidos++;
	}
}


/*---------------------------------------------------------------------------------------*/
/*****
* int AvenidaLuces::CuantosEncender
******
* Resumen:
* 	Entrega la cantidad de postes que están apagados entre la posición i y la posición del 
*   poste encendido más cercano en una posición menor o igual a i. Si no existe tal poste,
*   entrega la cantidad de postes apagados entre las posiciones 0 e i. Y luego muestra por 
*   pantalla el resultado.
******
* Input:
*   -int i; es un entero que representa la posición del poste a evaluar.
******
* Returns:
* 	Retorna la cantidad de postes apagados.
*****/


int AvenidaLuces::CuantosEncender(int i){
	int postesApagados = 0;
	int x;
	x = postes.lower_bound(i);

	if (x == 0 ){
		while (i >= x){
		postesApagados += 1;
		i--;
		}

	} else { 
		while (postes.find(i) == false){
			postesApagados += 1;
			i--;
		}
	}

	cout<<postesApagados<<endl;

	return postesApagados;
}

/*---------------------------------------------------------------------------------------*/
/*****
* void AvenidaLuces::PararPrograma
******
* Resumen:
* 	Entrega la cantidad total de postes encendidos y muestra el resultado por pantalla.
******
* Input:
*   No recibe ningún parámetro.
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/

void AvenidaLuces::PararPrograma(){
	cout<<PostesEncendidos<<endl;
}

/*---------------------------------------------------------------------------------------*/
/*****
* void LucesporArreglar
******
* Resumen:
* 	Inicializa la clase AvenidaLuces, si se ingrese el string "PARAR_PROGRAMA" ejecuta la
*   función PararPrograma y termina, si no, se recibe otro string. Si se ingresa "ENCENDER", 
*   se ejecuta la función Encender, y si se ingresa "CUANTOS_ENCENDER", se ejecuta la 
*   función CuantosEncender.
******
* Input:
*   No recibe ningun parámetro.
******
* Returns:
* 	No retorna nada ya que es una funcion void
*****/

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
