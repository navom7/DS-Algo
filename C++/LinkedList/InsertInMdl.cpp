// insert in the middle
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node * &head, int data) {
    if(head == NULL) {
        head = new Node(data);
        return;
    }

    Node * newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void printAll(Node * head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
    return;
}

void insertInMiddle(Node * &head, int pos, int num) {
    if(pos == 0) {
        insertAtHead(head, num);
        return;
    }
    Node * temp = head;
    for(int k = 1; k < pos; k++) {
        temp = temp->next;
    }
    Node* newNode = new Node(num);
    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    Node * head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 11);
    insertAtHead(head, 14);
    insertAtHead(head, 3);
    insertAtHead(head, 15);
    insertInMiddle(head, 3, 334);
    printAll(head);
    return 0;
}