// adding numbers with SLL using recursion

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};


struct Node *head1 = NULL;
struct Node *head2 = NULL;


void show(struct Node *n){
    struct Node *ptr = n;
    while(ptr){
        cout<<ptr->data<<"";
        ptr = ptr->next;
    }
    cout<<endl;
}

int carry = 0;
int temp = 0;
void add(struct Node *a, struct Node *b, int asize, int bsize){
        if(asize > bsize){
            add(a->next, b,asize-1, bsize);
            int temp = a->data + carry;
            carry = temp/10;
            a->data = temp%10;
            if(a == head1 && carry > 0){
                struct Node *ptr = new struct Node;
                ptr->data = carry;
                ptr->next = head1;
                head1 = ptr;
            }
        }
        else{
            if(a->next == NULL){
                temp = a->data + b->data;
                carry = temp/10;
                a->data = temp%10;
            }
            else{
                add(a->next, b->next, asize-1, bsize-1);
                temp = a->data + b->data + carry;
                carry = temp/10;
                a->data = temp%10;
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
    
    A->data = 9;
    A->next = B;
    B->data = 4;
    B->next = C;
    C->data = 7;
    C->next = D;
    D->data = 3;
    D->next = E;
    E->data = 5;
    E->next = NULL;
    
    head1 = A;

    struct Node *P = new struct Node;
    struct Node *Q = new struct Node;
    struct Node *R = new struct Node;
    struct Node *S = new struct Node;
    struct Node *T = new struct Node;
    
    //P->data = 1;
    //P->next = Q;
    Q->data = 8;
    Q->next = R;
    R->data = 6;
    R->next = S;
    S->data = 4;
    S->next = T;
    T->data = 7;
    T->next = NULL;
    
    head2 = Q;
    
    add(head1, head2, 5,4);
    
    cout<<"The Sum of the two LL is : ";
    show(head1);
    return 0;
    
}
