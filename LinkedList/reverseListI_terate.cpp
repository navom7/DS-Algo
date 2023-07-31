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


node * reverseListIterate(node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node * front = head->next;
    head->next = NULL;
    while(front != NULL){
        node * nxt = front->next;
        front->next = head;
        if(nxt == NULL){
            return front;
        }
        head = front;
        front = nxt;
    }
    return front;
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

