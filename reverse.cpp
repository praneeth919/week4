#include<iostream>

using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
};
 
void reverseNode(Node *curr, Node *prev, Node **head);
 
void reverse(Node **head)
{
    if (!head)
        return;
    reverseNode(*head, NULL, head);
}
 

void reverseNode(Node *curr, Node *prev, Node **head)
{
   
    if (!curr->next)
    {
        *head = curr;
 
  
        curr->next = prev;
        return;
    }
 
    Node *next = curr->next;
    curr->next = prev;
    reverseNode(next, curr, head);
}
 
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 

void printlist(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}
 
int main()
{
    Node *head1 = newNode(5);
    head1->next = newNode(10);
    head1->next->next = newNode(42);

    cout << "Given linked list\n";
    printlist(head1);
    reverse(&head1);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}
