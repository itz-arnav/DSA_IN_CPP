// insert, delete, traverse in SLL

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
int size;

void insert(){
    if(head==NULL){
        struct Node *temp = new struct Node;
        cout<<"Enter data for the first node : ";
        cin>>temp->data;
        temp->next = 0;
        head = temp;
        size++;
    }
    else{
        cout<<"Do you want to enter at the end?"<<endl;
        char ch;
        cin>>ch;
        if(tolower(ch) == 'y'){
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
        else{
            cout<<"The current LinkedList has :"<<size<<" elements!"<<endl;
            cout<<"Enter the position you want to insert into : ";
            int pos;
            cin>>pos;
            struct Node *ptr = head;
            while(--pos > 0){
            ptr = ptr->next;
            }
            struct Node *temp = new struct Node;
            cout<<"Enter the data for the node : ";
            cin>>temp->data;
            temp->next = ptr->next;
            ptr->next = temp;
            size++;
        }
    }
}

void show(){
    struct Node *ptr = head;
    for(int i = 0; i<size; i++){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main(){
    
    do{
        cout<<endl;
        cout<<"Press 1 to insert an element in the Linked List"<<endl;
        cout<<"Press 2 to display the Linked List"<<endl;
        cout<<"Press 3 to quit"<<endl;
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
            insert();
            break;
            case 2:
            show();
            break;
            default:
            cout<<"Thank you!"<<endl;
            return 0;
        }
    }while(1);
    
    return 0;
    
}
