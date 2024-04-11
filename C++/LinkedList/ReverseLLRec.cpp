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
pair<Node*, Node*> reverseLLRec(Node * head) {
    Node * temp = NULL;
    if(head == NULL) {
        return make_pair(head, head);
    }
    if(head->next == NULL) {
        return make_pair(head, head);
    }
    Node * prev = head;
    pair<Node*, Node*> res = reverseLLRec(head->next);
    Node* newHead = res.first;
    Node* tail = res.second;
    cout << newHead->data << " --- " << tail->data << endl;
    tail->next = prev;
    tail = tail->next;
    tail->next = NULL;
    return make_pair(newHead, tail);
}

Node* reverseLLRecShort(Node * head) {
    Node * temp = NULL;
    if(head == NULL) {
        return head;
    }
    if(head->next == NULL) {
        return head;
    }
    Node* res = reverseLLRecShort(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
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

    Node* newRes = reverseLLRecShort(head);
    printAll(newRes);
    pair<Node*, Node*> res = reverseLLRec(head);

    Node* newHead = res.first;
    Node* tail = res.second;
    cout << endl << endl;
    cout << newHead->data << " --- " << tail->data << endl;
    printAll(res.first);
    return 0;
}