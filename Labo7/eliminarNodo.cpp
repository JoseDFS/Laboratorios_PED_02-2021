#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *hijoizq;  // puntero al subarbol izquierdo
    nodo *hijodere; // puntero al subarbol derecho
};

class Abb
{
public:
    nodo *pAbb;
    Abb();
    ~Abb();
    void insertar(void);
    void insnodoAbb(nodo **, int);
    void mostrarPreorden(void);
    void mostrarpre(nodo *);
    void mostrarInorden(void);
    void mostrarIn(nodo *);
    void mostrarPostorden(void);
    void mostrarpost(nodo *);
};

Abb::Abb(void)
{
    pAbb = NULL;
}

Abb::~Abb(void)
{
    cout << "Destructor ejecutandose" << endl;
}

void Abb::insertar(void)
{
    int dato;
    char resp;

    do
    {
        cout << "Desea digitar un dato? ";
        cin >> resp;
        if (resp == 's')
        {
            cout << "Digite el dato: " << endl;
            cin >> dato;
            insnodoAbb(&pAbb, dato);
        }
    } while (resp == 's');
}

void Abb::insnodoAbb(nodo **p, int dato)
{
    if (!(*p))
    {
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->hijoizq = NULL;
        (*p)->hijodere = NULL;
    }
    else
    {
        if (dato < (*p)->dato)
        {
            insnodoAbb(&((*p)->hijoizq), dato);
        }
        else
        {
            if (dato > (*p)->dato)
            {
                insnodoAbb(&((*p)->hijodere), dato);
            }
            else
            {
                // se le llama llave a los datos de los arboles(como el dui, nit, etc)
                cout << "La llave ya esta en el arbol" << endl
                     << endl;
            }
        }
    }
}

void Abb::mostrarInorden(void)
{
    mostrarIn(pAbb);
}

void Abb::mostrarIn(nodo *p)
{
    if (p)
    {
        mostrarIn(p->hijoizq);
        cout << p->dato << "  ";
        mostrarIn(p->hijodere);
    }
}
void Abb::mostrarPreorden(void)
{
    mostrarpre(pAbb);
}

void Abb::mostrarpre(nodo *p)
{
    if (p)
    {
        cout << p->dato << "  ";
        mostrarpre(p->hijoizq);
        mostrarpre(p->hijodere);
    }
}

void Abb::mostrarPostorden(void)
{
    mostrarpost(pAbb);
}

/* Dado un arbol no vacio, retorna el nodo con el valor de llave minimo encontrado en ese arbol.
El arbol entero no necesita ser recorrido */
struct nodo *minValueNode(struct nodo *Nodo)
{
    struct nodo *current = Nodo;

    /* Recorre el arbol hasta encontrar la hoja mas a la izquierda (el dato mas pequeño) */
    while (current && current->hijoizq != NULL)
        current = current->hijoizq;

    return current;
}

nodo *borrarNodo(nodo *root, int key)
{
    // Caso base
    if (root == NULL)
        return root;
    // Si la llave a eliminar es mas pequeña que el root, entonces el valor esta en el sub arbol izquierdo
    if (key < root->dato)
        root->hijoizq = borrarNodo(root->hijoizq, key);
    // Si la llave a eliminar es mas grande que el root, entonces el valor esta en el sub arbol derecho
    else if (key > root->dato)
        root->hijodere = borrarNodo(root->hijodere, key);
    // Si la llave a eliminar es igual que el root, entonces el valor a eliminar es el root
    else
    {
        //Nodo con solamente un hijo, o ningun hijo
        if (root->hijoizq == NULL)
        {
            struct nodo *temp = root->hijodere;
            free(root);
            return temp;
        }
        else if (root->hijodere == NULL)
        {
            struct nodo *temp = root->hijoizq;
            free(root);
            return temp;
        }
        // Nodo con dos hijos: Obtener el sucesor en orden (el mas pequeño en el sub arbol derecho)
        struct nodo *temp = minValueNode(root->hijodere);
        // Copiar el contenido del sucesor en orden a este nodo
        root->dato = temp->dato;
        // Eliminar el nodo sucesor
        root->hijodere = borrarNodo(root->hijodere, temp->dato);
    }
    return root;
}

void Abb::mostrarpost(nodo *p)
{
    if (p)
    {
        cout << p->dato << "  ";
        mostrarpost(p->hijoizq);
        mostrarpost(p->hijodere);
    }
}

int main(void)
{
    cout << endl;
    cout << "ADMINISTRACION DE ARBOL BINARIO DE BUSQUEDA" << endl;

    //objeto de la clase Arbol
    Abb objAbb;

    cout << "Incertar datos en el arbol: " << endl
         << endl;
    objAbb.insertar();
    cout << endl
         << "Mostrando en inorden: " << endl;
    objAbb.mostrarPostorden();
/*     cout << endl
         << "Mostrando en preorden: " << endl;
    objAbb.mostrarPreorden();
    cout << endl
         << "Mostrando en postorden: " << endl;
    objAbb.mostrarPostorden(); */
    cout << endl;
    cout<<"Eliminar un valor"<<endl;
    objAbb.pAbb = borrarNodo(objAbb.pAbb, 21);

    cout << endl
         << "Mostrando en postordern: " << endl;
    objAbb.mostrarPostorden();
    cout<<endl;


    return 0;
}