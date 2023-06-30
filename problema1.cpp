#include<iostream>
#include<string>
#include "TDA_Login.hpp"

using namespace std;

/*****
* void operaciones
******
* Es una función que se dedica a recibir los datos de entrada y obtener la operacion, el usuario y la clave. Para después usar las operaciones del TDA Login
******
* Input:
* No recibe ningún parametro ya que es una función void
*
******
* Returns:
* no retorna nada ya que es una funcion void
*****/




void operaciones(){
    string operacion, usuario, clave;
    bool flag = true;
    //Login login;

    while(flag){

        cin>>operacion>>usuario>>clave;

        if("FINALIZAR"== operacion){
            flag=false;
        }else if("INICIAR_SESION" == operacion){
            //login.iniciar_sesion(string usuario, string clave)
        }else if("REGISTRAR" == operacion){
            //login.crear_nuevo_usuario(string usuario, string clave);
        }else if("ACTUALIZAR" == operacion){
            //login.cambiar_clave(string usuario, string clave);
        }
    }
}


int main(){
    operaciones();

    return 0;
}