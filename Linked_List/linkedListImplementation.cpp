#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int data){
        this->data = data;
    }
};

//passing head as reference so that changes reflect everywhere
void insertAtHead(node* &head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node * temp = new node(data);
    temp->next = head;
    head = temp;
}

void printLinkedList(node* head){
    while(head != NULL) {
        cout << head->data << "-->";
        head = head-> next;
    }
    return;
}

void insertInMiddle(node* head, int data, int pos) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    while(pos > 0 && head != NULL){
        head = head->next;
        pos--;
    }
    node * temp = new node(data);
    temp->next = head->next;
    head->next = temp;
    return;
}

int main() {
    node * head = new node(1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    
    insertInMiddle(head, 5, 2);
    printLinkedList(head);
    
    return 0;
}
