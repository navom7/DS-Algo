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


node * reverseLinkedList(node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node * temp = reverseLinkedList(head->next);
    // cout << head->data << " " << temp->data << endl;
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main() {
    node * head = new node(1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    
    node* newHead = reverseLinkedList(head);
    printLinkedList(newHead);
    
    return 0;
}
