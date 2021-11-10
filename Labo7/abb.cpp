// ADMINISTRACIÓN DE UN ARBOL BINARIO
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *hijoIzq;//puntero al sub-arbol izq.
    nodo *hijoDer;//puntero al sub-arbol der.
};

class ABB{

    private:
        nodo *pAbb;
    
    public:
        ABB();
        ~ABB();
        void insertar(void);
        void insNodoAbb(nodo **,int);

        void mostrarEnPeorden(void);
        void mostrarPre(nodo *);

        void mostrarEnInOrden(void);
        void mostrarIn(nodo *);
        
        void mostrarEnPosOrden(void);
        void mostrarPos(nodo *);

        bool buscarNodo(nodo *,int);
        void buscar(int);
        
        
};

ABB::ABB(void)
{
    pAbb = NULL;
}

ABB::~ABB()
{
    cout << "Destructor ejecutándose" << endl;
}

void ABB::insertar(void)
{
    int dato;
    char resp;

    do{
        cout<<"deasea digitar un dato ";
        cin>>resp;
         if(resp == 's'){
            cout<<"digite el dato";
            cin>>dato;
            insNodoAbb(&pAbb,dato);
        }
    }while(resp =='s');
}

void ABB::insNodoAbb(nodo **p,int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->hijoIzq=NULL;
        (*p)-> hijoDer=NULL;
    }
    else 
        if(dato < (*p)->dato)
            insNodoAbb(&((*p)->hijoIzq),dato);
        else 
            if( dato >  (*p)->dato)
                insNodoAbb(&((*p)->hijoDer),dato);
            else
                cout<<"La llave ya esta en el arbol ";

}
//in orden 
void ABB::mostrarEnInOrden(void)
{
    mostrarIn(pAbb);
    
}


void ABB::mostrarIn(nodo *p)
{
    if(p){
        mostrarIn(p->hijoIzq);
        cout<< p->dato<<"  ";
        mostrarIn(p->hijoDer);
    }
}



bool ABB::buscarNodo(nodo *p,int n)
{
    if(p == NULL)
        return false;
    else if(p->dato == n)
        return true;
    else if(p->dato > n)
        return buscarNodo(p->hijoIzq,n);
    else if(p->dato < n)
        return buscarNodo(p->hijoDer,n);
}
void ABB::buscar(int n)
{
    if(buscarNodo(pAbb,n))
        cout << "Dato encontrado";
    else
        cout<<"Dato no encontrado";   
    
}
//pre orden
void ABB::mostrarEnPeorden(void)
{
    mostrarPre(pAbb);
    
}

void ABB::mostrarPre(nodo *p)
{
    if(p){
        mostrarPre(p->hijoIzq);
        cout<< p->dato<<"  ";
        mostrarPre(p->hijoDer);
    }
}
//pos orden
void ABB::mostrarEnPosOrden(void)
{
    mostrarPos(pAbb);
    
}


void ABB::mostrarPos(nodo *p)
{
    if(p){
        mostrarIn(p->hijoIzq);
        cout<< p->dato<<"  ";
        mostrarIn(p->hijoDer);
    }
}

//
int main(void)
{
    cout << endl;
    cout << "ADMINISTRACIÓN DE UN ARBOL BINARIO DE BUSQUEDA" << endl << endl;

    ABB objABB;

    cout << "Insertar datos en el arbol:" << endl;
    objABB.insertar();

    cout<<"mostrar en in-orden";
    objABB.mostrarEnInOrden();

    cout<<" \n Buscar Dato: \n";
    objABB.buscar(4);

    cout << endl;
    return 0;
}

