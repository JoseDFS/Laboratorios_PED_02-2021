
#include <iostream>

using namespace std;

//Vi al final que utilizaban una clase así que lo hice con clase y traté de ir explicando con comentarios como se hace el insert de manera ascendente.
//Cualquier pregunta pueden escribirme
struct nodo{
    int dato;
    nodo *sig;
};

class lista_circular{

    private:
        nodo *pInicio;
    
    public:
        lista_circular();
        ~lista_circular();
        void insertaNodo();
        void insOrdenAscendente(int);
        void mostrarLista();
};

lista_circular::lista_circular()
{
    pInicio = NULL;
}

lista_circular::~lista_circular()
{
    if(pInicio){
        eliminarListaCircRec(pInicio);
        pInicio = NULL;
    }
}
void lista_circular::insertaNodo()
{
    int dato;
    cout << "Digite un entero o Ctrl-d para terminar: ";
    while(cin >> dato){
        insOrdenAscendente(dato);
        cout << "Digite un entero o Ctrl-d para terminar: ";
    }
    cout << endl;
}

void lista_circular::insOrdenAscendente(int dato)
{
    //Nuevo nodo a insertar y un nodo auxilar para recorrer la lista
    nodo *nuevo, *aux;

    nuevo = new nodo;
    nuevo->dato = dato;

    //Caso en donde la lista está vacía y lo único que se hace es 
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    //Si ya hay datos se tienen que tomar en cuenta 2 casos
    else{
        //Caso1:Si el dato es menor al dato del primer nodo, entonces este nuevo dato será el nuevo pInicio.
        if(dato < pInicio->dato){
            nuevo->sig = pInicio; //Entonces se hace el ligue de que el siguiente del nuevo será pInicio.
            aux = pInicio; //Utilizamos el aux para no perder la referencia de pInicio.
            while(aux->sig != pInicio) // Empezamos a recorrer la lista hasta el elemento final (uno antes de volver al inicio)
                aux = aux->sig;
            aux->sig = nuevo; // Y le decimos a este elemento final que su siguiente será el nuevo nodo
            pInicio = nuevo; //Terminamos diciendo que pInicio es el nuevo nodo.
        }
        //Caso 2: el dato es mayor que el dato del primer nodo.
        else{
            aux = pInicio; //Utilizamos el aux para no perder la referencia de pInicio.
            while(aux->sig != pInicio && aux->sig->dato < dato) //Recorremos la lista hasta llegar al final o hasta encontrar un nodo cuyo dato es mayor que el dato nuevo.
                aux = aux->sig;
            nuevo->sig = aux->sig; //Al encontrar el nodo con el dato mayor o llegado al final, hacemos las conexiones en donde el nuevo nodo se inserta antes de ese nodo con el dato mayor
            aux->sig = nuevo; 
        }
    }
}

void lista_circular::mostrarLista()
{
    nodo *aux;
    cout << endl;
    if(pInicio){
        aux = pInicio;
        do{
            cout << aux->dato << endl;
            aux = aux->sig;
        }while(aux != pInicio);
    }
}


main()
{
    lista_circular listaCircular;
    listaCircular.insertaNodo();
    listaCircular.mostrarLista();
    return 0;
}
