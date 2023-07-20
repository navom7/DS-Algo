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


Node* mergeSortedLinkedList(Node* head1, Node* head2) {
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    cout << head1->data << " " << head2->data << endl;
    Node* res = NULL;
    Node* resHead = NULL;
    if(head1->data > head2->data) {
        resHead = head1;
        head1 = head1->next;
    } else {
        resHead = head2;
        head2 = head2->next;
    }

    res = resHead;
    cout << res->data << endl;

    while(head1 != NULL && head2 != NULL){
        if(head1->data > head2->data) {
            resHead->next = head1;
            head1 = head1->next;
        } else {
            resHead->next = head2;
            head2 = head2->next;
        }
        resHead = resHead->next;
    }
    if(head1 != NULL) {
        resHead->next = head1;
        head1 = head1->next;
        resHead = resHead->next;
    } 
    while(head2 != NULL){
        resHead->next = head2;
        head2 = head2->next;
        resHead = resHead->next;
    }
    return res;

}

int main() {
    Node * head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtHead(head, 16);
    insertAtHead(head, 18);
    printAll(head);

    Node * head1 = NULL;
    insertAtHead(head1, 11);
    insertAtHead(head1, 13);
    insertAtHead(head1, 17);
    insertAtHead(head1, 19);
    printAll(head1);

    Node* newRes = mergeSortedLinkedList(head, head1);

    printAll(newRes);



    return 0;
}