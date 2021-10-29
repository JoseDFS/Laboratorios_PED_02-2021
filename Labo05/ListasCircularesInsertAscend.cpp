#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
} *first, *last;

void insertNode();
void showNode();

int main()
{
    insertNode();
    insertNode();
    insertNode();
    insertNode();
    insertNode();
    cout << "~~ Listas Circulares ~~"<< endl;
    showNode();
    return 0;
}

void insertNode()
{
    Node* nuevo = new Node();
    cout << "Ingrese un elemento: ";
    cin >> nuevo->data;

    if(first==NULL)
    {
        first = nuevo;
        first->next = first;
        last = first;
    }
    else 
    {
        last->next = nuevo;
        nuevo->next = first;
        last = nuevo;
    }
    cout << "Se ha insertado un nuevo elemento! :D" << endl;
}

void showNode(){
    Node* actual = new Node();
    actual = first;
    if(first!=NULL)
    {
        do
        {
            cout << "\n" << actual->data << endl;
            actual = actual->next;
        }
        while(actual!=first);
    }
    else
    {
        cout << "La lista circulara no tiene datos :/" << endl;
    }
}



