#include <iostream>
using namespace std;

//Implementacion de la lista 

class Node 
{
    //interfaz privada
    private:
        int data;
        // Tendra un nodo anterior
        Node *previous;
        // Tendra un nodo siguiente
        Node *next;

        //Como las variables son privadas debemos 
        // compartirlas con las funciones
        friend class LinkedList;
};

class LinkedList
{
    //Para los elementos de nuestra lista
    //El constructor
    public:
        // constructor
        LinkedList();
        // el destructor
        ~LinkedList();
        // Asigna memoria dinamicamente, el destructor libera memoria

        // funcion que devuelve el numero entero del primer nodo de
        // la lista HEAD
        int getFront() const;

        // funcion que nos va a devolver el numero del ultimo nodo 
        //de la lista TAIL
        int getBack() const;

        // Funcion para el nuevo nodo, que pasa el valor a la 
        //funcion
        void addFront(int dt);

        // Funcion para el nuevo nodo, que pasa el valor a la funcion
        void addBack(int dt);

        //Funcion para eliminar al primer Nodo
        void removeFront();

        //Funcion para eliminar al ultimo Nodo
        void removeBack();

        // Funcion para imprimir la informacion de forma inversa
        void printReverse();

        //Funcion para imprimir la lista del principio al final 
        // Mostrar de forma normal
        void printForward();
    
    private:
        //Declarar los punteros que apuntan a los nodos centinela
        Node *header;
        Node *trailer;
};

int main()
{
    //crear un objeto de la lista una instancia
    LinkedList ll;
    // Añadir datos a la lista
    ll.addFront(7);
    ll.addFront(2);
    ll.addFront(1);
    ll.addFront(5);
    ll.addFront(9);
    ll.addFront(8);
    ll.addFront(3);
    ll.addFront(4);

    //  Anadir al final
    ll.addBack(13);
    ll.addBack(16);
    ll.addBack(18);
    ll.addBack(12);
    ll.addBack(19);
    ll.addBack(10);

    // Para imprimir
    cout << "Imprimir los datos:" << endl;
    ll.printForward();

    cout << "Imprimir datos alreves:" << endl;
    ll.printReverse();   

    // Eliminar HEAD
    ll.removeFront();

    // Eliminar TAIL
    ll.removeBack();

    //Obtener HEAD
    cout << "El valor de HEAD es: " << ll.getFront() << endl;

    // Obtener TAIL
    cout << "El valor de TAIL es: " << ll.getBack() << endl;

    return 0;
};

LinkedList::LinkedList(){
    // Se define dinamicamente la memoria 
    header = new Node;
    // creamos el trailer (que es el centinela final)
    trailer = new Node;
    //Tenemos que hacer que el header apunte al trailer, 
    // y el trailer al header
    header->next = trailer;
    trailer->previous = header;
    //Como la lista esta vacia se igual a NULL
    header->previous = NULL;
    trailer->next = NULL;
}

//Al final si se puede
LinkedList::~LinkedList(){
    // llama a la funcion removeFront
    //para cuando elimine el elemento de la lista que no este vacia
    //Sera cuando ambos nodos centinela se apunten, es decir no hay head ni tail
    while(header->next!=trailer){
        removeFront();
    }
    //eliminar individualmente
    delete header;
    delete trailer;
}
int LinkedList::getFront() const{
    // Devuelve el primer valor
    //acceder al header
    //accedemos a su dato
    return header->next->data;
}
int LinkedList::getBack() const{
    //Devuelve el ultimo nodo
    return trailer->previous->data;
}
void LinkedList::addFront(int dt){
    // anadir un nuevo nodo a la memoria que se pasa por valor
    Node *nd = new Node;
    //al nodo que tenemos le ponemos el dato
    nd->data = dt;
    nd->previous = header;
    // es decir que ahora esta apuntando al nodo head
    nd->next = header->next; 

    // cambiar los punteros del header, y del nodo head
    // su puntero anterior es el nuevo nodo
    // acceder al nodo head, su puntero previous es 
    // el nuevo nodo anadido a la lista
    header->next->previous = nd;

    // el puntero head 
    header->next = nd;

}
void LinkedList::addBack(int dt){
    Node *nd = new Node;
    nd->data = dt;
    nd->previous=trailer->previous;
    nd->next=trailer;

    //actualizar trailer
    // a traves de trailer accedemos a su nodo previo apunta al nuevo nodo
    trailer->previous->next = nd;
    trailer->previous = nd;
}
void LinkedList::removeFront(){
    // Eliminar el nodo del principio
    // Accedemos al nodo siguiente de head
    Node *nd=header->next->next;
    delete header->next;

    // actualizar los punteros del header y del nodo anterior
    header->next=nd;
    nd->previous=header;
}
void LinkedList::removeBack(){
    // Eliminar a final
    // tomar una referencia al nodo anterior al nodo tail
    Node *nd = trailer->previous->previous;

    delete trailer->previous;

    //actualizar el puntero apuntara al 
    //nodo anterior al nodo tail que se elimino
    trailer->previous=nd;
    nd->next=trailer;
}
void LinkedList::printReverse(){
    // Vamos a imprimirlos 
    // Va del final al principio
    //referencia a tail
    Node *nd=trailer->previous;

    //Si el nodo es diferente al centinela inicial
    while (nd!=header)
    {
        // se imprime el nodo
        cout << nd->data<< endl;
        //actualizar el nodo anterior
        nd=nd->previous;
    }    

}
void LinkedList::printForward(){
    // Vamos a imprimirlos 
    // Va del principio al final
    //referencia a head
    Node *nd=header->next;

    //Si el nodo es diferente al centinela final
    while (nd!=trailer)
    {
        // se imprime el nodo
        cout << nd->data<< endl;
        //actualizar el nodo al siguiente
        nd=nd->next;
    }    
}