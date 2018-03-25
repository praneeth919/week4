#include <iostream>

using namespace std;
  
struct node {
    int val;
    node *next;
};
  
void reverseList(node **head) {
    node *prev = NULL, *ptr = *head, *temp;
    while (ptr) {
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    *head = prev;
}
  
void printList(node *ptr) {
    while(ptr) {
        cout << ptr->val << ", ";
        ptr = ptr->next;
    }
    cout << endl;
}
  
int isPal(node* head) {
    if (head == NULL) {
        return 1;
    }
    node *p1, *p2; 
  
    node *mid = NULL;
    p1 = p2 = head;
    while (p2) {
        p2 = p2->next;
        if (p2) p2 = p2->next;
        if (p2) p1 = p1->next;
    }
    mid = p1;
  
    reverseList(&(mid->next)); 
  
    int ans = 1;
    p1 = head;
    p2 = mid->next;
    while (ans == 1 && p2) {
        if (p1->val != p2->val) ans = 0;
        p1 = p1->next;
        p2 = p2->next;
    }
  
    reverseList(&(mid->next)); 
  
    return ans;
}
  
node *createListFromArray(int arr[], int n) {
    node *head = new node;
    node *ptr = head;
    for (int i = 0; i < n; i++) {
        ptr->val = arr[i];
        ptr->next = (i == n-1 ? NULL : new node);
        ptr = ptr->next;
    }
    return head;
}
  
  
int main()
{
    int arr[] = {1, 2, 1};
    cout << "Result 1: " << isPal(createListFromArray(arr, 3)) << endl;
  
    int arr2[] =  {1, 2, 3};
    cout << "Result 2: " << isPal(createListFromArray(arr2, 3)) << endl;

    return 0;
}
