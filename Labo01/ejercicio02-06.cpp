#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    Node *reverse(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        /* 
        Reverse the rest list and put
        the first element at the end 
        */
        Node *rest = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return rest;
    }

    
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    void append(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;
        if (this->head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *jmp = head; //We do this, because we dont want to lose our head pointer.
            while (jmp->next != nullptr)
            {
                jmp = jmp->next;
            }
            jmp->next = newNode;
        }
    }

};


int main()
{
    
    LinkedList L;
    L.append(1);
    L.append(2);
    L.append(3);
    L.append(4);
    L.append(5);

    L.print();//Original List;

    L.head = L.reverse(L.head);

    L.print();//List after reverse operation
    return 0;
}