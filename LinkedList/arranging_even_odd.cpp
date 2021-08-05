// arranging even odd with SLL

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};


struct Node *head1 = NULL;


void show(struct Node *n){
    struct Node *ptr = n;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void evenodd(struct Node *p){
     struct Node *temp=NULL, *ptr=NULL;
     struct Node *second = ptr;
     bool flag = false;
     bool odd = false;
    while(p){
        cout<<"Now p->data : "<<p->data<<endl;
        if(p->data%2==0 && !flag){
            flag = true;
            temp = p;
            p = p->next;
            temp->next = NULL;
            head1 = temp;
        }
        else if(p->data%2 == 0){
            temp->next = p;
            p = p->next;
            temp = temp->next;
            temp->next = NULL;
        }
        else{
            if(!odd){
                odd = true;
                ptr = p;
                p = p->next;
                ptr->next = NULL;
                second = ptr;
            }
            else{
                ptr->next = p;
                p = p->next;
                ptr = ptr->next;
                ptr->next = NULL;
            }
        }
    }
    temp->next = second;
}

int main()
{
    
    struct Node *A = new struct Node;
    struct Node *B = new struct Node;
    struct Node *C = new struct Node;
    struct Node *D = new struct Node;
    struct Node *E = new struct Node;
    struct Node *P = new struct Node;
    struct Node *Q = new struct Node;
    struct Node *R = new struct Node;
    struct Node *S = new struct Node;
    struct Node *T = new struct Node;
    
    A->data = 9;
    A->next = B;
    B->data = 4;
    B->next = C;
    C->data = 8;
    C->next = D;
    D->data = 3;
    D->next = E;
    E->data = 5;
    E->next = P;
    
    head1 = A;

    P->data = 1;
    P->next = Q;
    Q->data = 8;
    Q->next = R;
    R->data = 6;
    R->next = S;
    S->data = 4;
    S->next = T;
    T->data = 7;
    T->next = NULL;
    
    evenodd(head1);
    
    cout<<"The sorted LL is : ";
    show(head1);
    return 0;
    
}
