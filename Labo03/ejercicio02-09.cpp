#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//El programa estab bien pero por tener el teclado en otro idioma el Ctrl-D no terminaba de limpiar el buffer de cin
//Cualquier duda me pueden escribir :D
struct libro
{
    char titulo[35];
    int numPaginas;
    libro *sig;
};

class Pila
{
private:
    libro *pTope;

public:
    Pila();
    ~Pila();
    void mostrarPila(void);
    void insertarEnPila(void);
    void insertar(char *titulo,int numPaginas);
    string TopeTitulo(void);
    int TopeNumPag(void);
    void Pop(void);
    bool Vacio(void);
};

Pila::Pila(void)
{
    pTope = NULL;
}

Pila::~Pila(void)
{
    libro *p;

    while (pTope)
    {
        p = pTope;
        pTope = pTope->sig;
        delete p;
    }
}

void Pila::mostrarPila(void)
{
    libro *p;
    cout << "Los elementos de la pila son:" << endl;
    p = pTope;
    while (p)
    {
        cout << p->titulo<< " | " << p->numPaginas << endl;
        p = p->sig;
    }
    cout << "Fin de mostrar pila" << endl;
}
string Pila::TopeTitulo(void){

    return pTope->titulo;
}

int Pila::TopeNumPag(void){
    return pTope->numPaginas;
}

void Pila::insertarEnPila(void)
{
    int numPaginas;
    char titulo[35];
    char s;

    cout << "Digite titulo y numero de paginas o Ctrl-D para terminar: ";
    while(cin >> titulo>>numPaginas){
        insertar(titulo,numPaginas);
        cout << "Digite titulo y numero de paginas o Ctrl-D para terminar: ";
    }
    
}

void Pila::insertar(char titulo[35],int numPaginas)
{
    libro *nuevo;
    nuevo = new libro;
    nuevo->numPaginas = numPaginas;
    strcpy(nuevo->titulo,titulo);
    nuevo->sig = pTope;
    pTope = nuevo;

}
void Pila::Pop()
{
     libro *aux;
     aux = pTope;
     pTope = aux->sig ;
     delete(aux);
}

bool Pila::Vacio(){
    if(pTope == NULL)
        return true;
    else 
        return false;
}

int numPaginas(Pila *libros, string titulo){
    
    if((*libros).Vacio()){
        cout<<"No se encontro el libro";
        return 0;
    }
    if((*libros).TopeTitulo() == titulo){
        return (*libros).TopeNumPag();
    }
    (*libros).Pop();
    return numPaginas(libros,titulo);
    
}

main(){
    Pila libros;
    char titulo[35];
    libros.insertarEnPila();
    libros.mostrarPila();
    
    cout<<"Ingresar titulo del libro: ";
    cin.clear();
    cin.ignore();
    cin.sync();
    cin.getline(titulo,35,'\n');
    
    cout<<"Numero de paginas de "<<titulo<<": "<<numPaginas(&libros,titulo);
    return 0;
}
