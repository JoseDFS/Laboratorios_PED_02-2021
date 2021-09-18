/* 7) Escriba una función que reciba un arreglo de números enteros y retorne el promedio. La
suma de los elementos debe realizarse por métodos recursivos. */

#include <iostream>
#include <conio.h>
using namespace std;

int sumar(int);

int main(){
    int numeroElementos;

    do{
        cout << "Digite el numero de elementos: ";
        cin >> numeroElementos;
    } while(numeroElementos <= 0); //Por ejemplo si el primer numero es menor a cero volvera a repetir, hasta que se digite un numero positivo

    //Para el promedio
    cout << "\nEl promedio es: " << sumar(numeroElementos)/numeroElementos<<endl;

    //Para la suma recursiva
    cout << "\nLa suma es: " << sumar(numeroElementos)<<endl;
    getch();
    return 0;
}

//Funcion recursiva
int sumar(int n) {
    int suma = 0;
    if(n==1){//caso base
        suma = 1;
    }
    else{//caso general
        suma = n+sumar(n-1);
    }
    return suma;
}