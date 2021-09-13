#include <iostream>

using namespace std;

struct nodo 
{
    int dato;
    nodo *sig;
};

class ListaSimple
{
    private:
        nodo *pInicio;

    public:
        ListaSimple();
        ~ListaSimple();

        void insertarEnLista(void);

        void insInicio(int);

        void mostrarListaSimple(void);
        void mostrarListaPares(void);
        void mostrarListaImpares(void);

        void mostrarListaInversa(void);
        void mostrarListaInversaAux(nodo *);
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

ListaSimple::~ListaSimple(void)
{
    nodo *p;

    while(pInicio)
    {
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaSimple::insInicio(int dato)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    pInicio=nuevo;
}

void ListaSimple::insertarEnLista(void){
    int i;
    int n;
    cout << "Cuantos numeros deseas generar o Ctrl-D para terminar" << endl;
    cin >> n;
    for(i = 1; i <= n; i++)
        insInicio((rand()%99)+1);
};

void ListaSimple::mostrarListaSimple(void){
    nodo *p;
    cout << "Los elementos de la lista son:" << endl;

    p=pInicio;
    while(p){
        cout << p->dato << endl;
        p = p->sig;
    }

    cout << "Fin de mostrar lista..." << endl;
}

void ListaSimple::mostrarListaPares(void){
    nodo *p;
    cout << "Los elementos PARES son:" << endl;
    p = pInicio;

    while(p){
        if(p->dato%2==0){
            cout << p->dato << endl;
        }    
        p = p->sig;    
    }
    cout << "Fin de mostrar lista de datos pares" << endl;
}

void ListaSimple::mostrarListaImpares(void){
    nodo *p;
    cout << "Los elementos IMPARES son:" << endl;
    p = pInicio;

    while(p){
        if(p->dato%2!=0){
            cout << p->dato << endl;
        }    
        p = p->sig;    
    }
    cout << "Fin de mostrar lista de datos impares" << endl;
}

void ListaSimple::mostrarListaInversa(void){
    mostrarListaInversaAux(pInicio);
    cout << "Fin de mostrar lista de datos inversos" << endl;
}

void ListaSimple::mostrarListaInversaAux(nodo *p){
    if(p){
        mostrarListaInversaAux(p->sig);
        cout << p->dato << endl;
    }
}


int main(void)
{
    ListaSimple objListaSimple;

    cout << endl;

    cout << "Programa de Lista Simple" << endl;

    cout << "Insercion de datos" << endl;
    objListaSimple.insertarEnLista();
    cin.clear();

    cout << "Datos de la lista:" << endl;
    objListaSimple.mostrarListaSimple();
    cin.clear();

    cout << "Datos de la lista PARES:" << endl;
    objListaSimple.mostrarListaPares();
    cin.clear();

    cout << "Datos de la lista IMPARES:" << endl;
    objListaSimple.mostrarListaImpares();
    cin.clear();

    cout << "Datos de la lista INVERSA:" << endl;
    objListaSimple.mostrarListaInversa();
    cin.clear();

    cout << endl;

    return 0;
}