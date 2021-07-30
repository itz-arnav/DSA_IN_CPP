// reverse DLL using recursion

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};


struct Node *head = NULL;


void show(){
    
    struct Node *ptr = head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    
}

void test(){
    struct Node *ptr = head;
    struct Node *tail = ptr;
    cout<<"Reversed LL : ";
    while(ptr){
        cout<<ptr->data<<" ";
        tail = ptr;
        ptr = ptr->next;
    }
    cout<<"Original LL by prev links : ";
    while(tail){
        cout<<tail->data<<" ";
        tail = tail->prev;
    }
}

void reverse(struct Node *ptr){
        if(ptr == head){
            reverse(ptr->next);
            ptr->next->next = ptr;
            ptr->prev = ptr->next;
            ptr->next = NULL;
        }
        
        else if(ptr->next->next == NULL){
            ptr->next->next = ptr;
            ptr->prev = ptr->next;
            ptr->prev->prev = NULL;
            head = ptr->next;
            return;
        }
        
        else{
            reverse(ptr->next);
            ptr->next->next=ptr;
            ptr->prev = ptr->next;
        }
}



int main()
{
    
    struct Node *A = new struct Node;
    struct Node *B = new struct Node;
    struct Node *C = new struct Node;
    struct Node *D = new struct Node;
    struct Node *E = new struct Node;
    
    A->data = 10;
    A->next = B;
    B->data = 20;
    B->next = C;
    C->data = 30;
    C->next = D;
    D->data = 40;
    D->next = E;
    E->data = 50;
    E->next = NULL;
    
    head = A;

    cout<<"The Linked List is : ";
    show();
    
    struct Node *ptr = head;
    reverse(ptr);

    test();
    
    return 0;
    
}
