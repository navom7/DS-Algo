#include<iostream>
using namespace std;


int a = 10;

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
    if(head == NULL || a <= 0) {
        head = new Node(data);
        return;
    }

    Node * newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    a--;
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



Node* kReverseLL(Node* head, int k) {
    if(head == NULL)
        return head;
    Node* prev = NULL;
    int cnt = k;
    Node* curr = head;
    while(curr != NULL && cnt-- > 0) {
        Node* temp = curr->next;

        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head->next = kReverseLL(curr, k);
    return prev;
}

int main() {
    Node * head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 11);
    insertAtHead(head, 14);
    insertAtHead(head, 3);
    insertAtHead(head, 15);
    
    printAll(head);

    Node* newRes = kReverseLL(head, 3);

    printAll(newRes);



    return 0;
}