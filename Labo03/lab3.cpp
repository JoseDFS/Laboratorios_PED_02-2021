#include<bits/stdc++.h>
using namespace std;
/*  
Given two lists sorted in increasing order, create and return a new list
 representing the intersection of the two lists. 
 The new list should be made with its own memory — 
 the original lists should not be changed.  */

/* Link list node */
struct Node {
    int data;
    Node* next;
};
 
void push(Node** head_ref, int new_data);
 
/*This solution uses the temporary
 dummy to build up the result list */
Node* sortedIntersect(Node* a, Node* b)
{
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
 
    /* Once one or the other
    list runs out -- we're done */
    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            push((&tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        /* advance the smaller list */
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return (dummy.next);
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at
the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = (Node*)malloc(
        sizeof(Node));
 
    /* put in the data  */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Function to print nodes in
   a given linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data <<" ";
        node = node->next;
    }
}
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty lists */
    Node* a = NULL;
    Node* b = NULL;
    Node* intersect = NULL;
 

    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);
 
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);
 
    
    intersect = sortedIntersect(a, b);
 
    cout<<"Linked list containing common items of a & b \n";
    printList(intersect);
}