/*
8) Elabore una función que reciba como parámetro una lista simple y un número entero.
Luego elimine de la lista todas las ocurrencias de ese número.
*/

#include <iostream> //Para operacion de entrada y salida cout y cin
#include <conio.h>  //Contiene prototipos de funciones como getche() y clrscr()
#include <stdlib.h> //Contiene prototipos de funciones como rand, malloc, exit, system
#include <chrono>   //Para eficiencia y control de procesos
#include <thread>   //Cuando un subproceso esta suspendido
using namespace std;

struct Number
{
    int dato;
    Number *sig;
};

Number *insertar_principio(Number *inicio, Number *nuevo)
{
    nuevo->sig = inicio;
    return nuevo;
}

Number *generar_nodo(Number *inicio, int dato)
{
    Number *nuevo;
    nuevo = new Number;
    nuevo->dato = dato;
    nuevo->sig = nullptr;
    inicio = insertar_principio(inicio, nuevo);
    return inicio;
}

void imprimir_lista(Number *inicio)
{
    for(Number *aux = inicio; aux != nullptr; aux=aux->sig)
    {
        cout << aux->dato << "" << endl;
    }
}

int eliminar_ocurrencias(Number *&inicio, int num)
{
    int cantidad = 0;
    Number *a_eliminar;
    Number *aux = inicio;

    while(aux != nullptr)
    {
        if(inicio->dato == num)
        {
            a_eliminar = inicio;
            inicio = inicio->sig;
            aux = inicio;
            delete a_eliminar;
            cantidad++;
        }
        else{
            if(aux->sig != nullptr && aux->sig->dato == num)
            {
                a_eliminar = aux->sig;
                aux->sig = a_eliminar->sig;
                delete a_eliminar;
                cantidad++;
            }
            else
            {
                aux = aux->sig;
            }
        }
    }
    return cantidad;
}

int main()
{
    Number *inicio = nullptr;

    inicio = generar_nodo(inicio, 7);
    inicio = generar_nodo(inicio, 9);
    inicio = generar_nodo(inicio, 12);
    inicio = generar_nodo(inicio, 16);
    inicio = generar_nodo(inicio, 21);
    inicio = generar_nodo(inicio, 7);

    imprimir_lista(inicio);

    cout << endl;

    cout << "Cantidad de ocurrencias eliminadas: " << eliminar_ocurrencias(inicio, 7);
    cout << endl;

    imprimir_lista(inicio);
}