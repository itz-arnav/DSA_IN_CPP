// merging two sorted SLL using recursion

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};


struct Node *head1 = NULL;
struct Node *head2 = NULL;
struct Node *c = NULL;


void show(struct Node *n){
    struct Node *ptr = n;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}


void merge(struct Node *a, struct Node *b, struct Node *c){
        if(a == NULL){
            c->next = b;
            return;
        }
        else if(b == NULL){
            c->next = b;
            return;
        }
        else{
            if(a->data <= b->data){
                c->next = a;
                a = a->next;
                c = c->next;
                merge(a,b,c);
            }
            else{
                c->next = b;
                b = b->next;
                c = c->next;
                merge(a,b,c);
            }
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
    
    head1 = A;

    struct Node *P = new struct Node;
    struct Node *Q = new struct Node;
    struct Node *R = new struct Node;
    struct Node *S = new struct Node;
    struct Node *T = new struct Node;
    
    P->data = 1;
    P->next = Q;
    Q->data = 12;
    Q->next = R;
    R->data = 33;
    R->next = S;
    S->data = 44;
    S->next = T;
    T->data = 55;
    T->next = NULL;
    
    head2 = P;
    
            if(head1->data <= head2->data){
                c = head1;
                head1 = head1->next;
            }
            else{
                c = head2;
                head2 = head2->next;
            }
    
    struct Node *head3 = c;
    merge(head1, head2, c);
    
    cout<<"The New Linked List is : ";
    show(head3);
    return 0;
    
}
