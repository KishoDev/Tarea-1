#include<iostream>
#include<string>
#include "TDA_Login.cpp"

using namespace std;

void operaciones(){
    string operacion, usuario, clave;
    bool flag = true;
    Login login;

    while(flag){

        cin>>operacion>>usuario>>clave;

        if("FINALIZAR"== operacion){
            flag=false;
        }else if("INICIAR_SESION" == operacion){
            //login.iniciar_sesion(string usuario, string clave)
        }else if("REGISTRAR" == operacion){
            //login.crear_nuevo_usuario(string usuario, string clave);
        }else if("ACTUALIZAR" == operacion){
            //login.cambiar_clave(string usuario, string nueva_clave);
        }
    }
}


int main(){
    operaciones();

    return 0;
}