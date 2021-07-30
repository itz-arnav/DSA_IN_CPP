// Delete Total SLL

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
int size;

void fast_insert(){
    if(head==NULL){
        struct Node *temp = new struct Node;
        cout<<"Enter data for the first node : ";
        cin>>temp->data;
        temp->next = 0;
        head = temp;
        size++;
    }
    else{
            struct Node *ptr = head;
            while(ptr->next!= NULL)
            ptr = ptr->next;
            
            struct Node *temp = new struct Node;
            cout<<"Enter the data for the last node : ";
            cin>>temp->data;
            temp->next = NULL;
            ptr->next = temp;
            size++;
        }
    }

void del(){
    struct Node *temp = head;
    struct Node *ptr = NULL;
    while(temp){
        ptr = temp;
        temp = temp->next;
        free(ptr);
    }
    size = 0;
}
void show(){
    struct Node *ptr = head;
    for(int i = 0; i<size; i++){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    if(size == 0)
    cout<<"NULL\n";
}

int main(){
    
    do{
        cout<<endl;
        cout<<"Press 1 to insert an element in the Linked List"<<endl;
        cout<<"Press 2 to display the Linked List"<<endl;
        cout<<"Press 3 to delete a value"<<endl;
        cout<<"Press 4 or any other value to quit"<<endl;
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
            fast_insert();
            break;
            case 2:
            show();
            break;
            case 3:
            del();
            break;
            default:
            cout<<"Thank you!"<<endl;
            return 0;
        }
    }while(1);
    
    return 0;
    
}
