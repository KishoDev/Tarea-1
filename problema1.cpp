#include<iostream>
#include<string>
#include "TDA_Login.cpp"

using namespace std;

void operaciones(){
    string operacion, usuario, clave;
    bool flag = true;
    while(flag){

        cin>>operacion>>usuario>>clave;

        if("FINALIZAR"== operacion){
            flag=false;
        }else if("INICIAR_SESION" == operacion){
            //nombreTDA.iniciar_sesion(string usuario, string clave)
        }else if("REGISTRAR" == operacion){
            //nombreTDA.crear_nuevo_usuario(string usuario, string clave);
        }else if("ACTUALIZAR" == operacion){
            //nombreTDA.cambiar_clave(string usuario, string nueva_clave);
        }
    }
}


int main(){
    operaciones();

    return 0;
}