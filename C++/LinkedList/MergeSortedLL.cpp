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
        cout << head->data << "-->";
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

Node* getMid(Node *head){
    //Complete this function to return data middle node
    if(head == NULL)
        return head;
    if(head->next == NULL) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* mid = getMid(head);
    Node* a = head;
    Node* b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);
    return mergeSortedLinkedList(a, b);

}


int main() {
    Node * head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 2);
    insertAtHead(head, 34);
    insertAtHead(head, 26);
    insertAtHead(head, 18);

    printAll(head);

    Node* sortedHead =  mergeSort(head);

    printAll(sortedHead);

    return 0;
}