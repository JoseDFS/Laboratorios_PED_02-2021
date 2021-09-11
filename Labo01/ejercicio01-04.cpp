#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void Encriptar(char *cadena,string clave,string codigo,int n,int m){
    if(n<sizeof(cadena)){
        if(m<clave.length()){
            if(cadena[n] == clave[m]){
                cadena[n] = codigo[m];
                Encriptar(cadena,clave,codigo,n+1,0);
            }
            else{
            Encriptar(cadena,clave,codigo,n,m+1);
            }
        }
        else{
           Encriptar(cadena,clave,codigo,n+1,0); 
        }
        
    }
    return;
}

int main(){
    char cadena[50];
    cin>>cadena;
    string clave= "murcielago";
    string codigo ="0123456789";

    Encriptar(cadena,clave,codigo,0,0);

    cout<<cadena;
    return 0;
}