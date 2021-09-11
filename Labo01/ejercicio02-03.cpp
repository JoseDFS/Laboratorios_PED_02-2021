#include <iostream>
#include <string>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class ListaSimple{
    private:
        nodo *pInicio;
    
    public:
        ListaSimple();
        ~ListaSimple();
        void mostrarListaSimple(void);
        void insFinal(int dato);
        
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

ListaSimple::~ListaSimple(void)
{
    nodo *p;

    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}


void ListaSimple::mostrarListaSimple(void)
{
    nodo *p;
    cout << "Los elementos de la lista son:" << endl;
    p = pInicio;
    while(p){
        cout << p->dato << endl;
        p = p->sig;
    }
    cout << "Fin de mostrar lista" << endl;
}

void ListaSimple::insFinal(int dato){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    if(!pInicio)
        pInicio = nuevo;
    else{
        nodo *s =pInicio;
        while(s->sig)
            s=s->sig;
        s->sig =nuevo;
    }
}

void ConverToBinario(int n,ListaSimple *binario){
    if(n/2 != 0){
        ConverToBinario(n/2,binario);
    }
    (*binario).insFinal(n%2);
}


int main(){
    ListaSimple binario;
    ConverToBinario(13,&binario);
    binario.mostrarListaSimple();
    return 0;
}