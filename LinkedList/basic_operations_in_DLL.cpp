// insert, delete, traverse in DLL

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
int size;

void insert(){
    if(head==NULL){
        struct Node *temp = new struct Node;
        cout<<"Enter data for the first node : ";
        cin>>temp->data;
        temp->next = 0;
        temp->prev = 0;
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
            temp->prev = ptr;
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
            ptr->next->prev = temp;
            temp->prev = ptr;
            ptr->next = temp;
            size++;
        }
    }
}

void del(){
    cout<<"Enter the data you want to delete : ";
    int val;
    cin>>val;
    
    struct Node *ptr = head;
    if(val == head->data)
    {
        head = head->next;
        size--;
        return;
    }
    while(ptr->next && ptr->next->data != val)
    {
        ptr = ptr->next;
    }
    if(ptr){
        struct Node *temp;
        temp = ptr->next;
        temp->next->prev = ptr;
        ptr->next = ptr->next->next;
        size--;
        free(temp);
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
        cout<<"Press 3 to delete a value"<<endl;
        cout<<"Press 4 or any other value to quit"<<endl;
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
            insert();
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
