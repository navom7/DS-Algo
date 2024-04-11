//sort every k set of values
//input 1-2-3-4-5-6-7-8, k = 3;
//output 3-2-1-6-5-4-8-7


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


node * kShort(node * head, int k){
    if(head == NULL || head->next == NULL)
        return head;
    node * prev = head;
    node * nxt = head->next;
    for(int i = 1; i < k; i++) {
        if(nxt == NULL){
            head->next = NULL;
            return prev;
        }
        // cout << nxt->data << " " << prev->data << endl;
        node * temp = nxt->next;
        nxt->next = prev;
        prev = nxt;
        nxt = temp;
    }
    // cout << head->data << endl;
    head->next = kShort(nxt, k);
    return prev;
}

int main() {
    node * head = new node(1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    insertAtHead(head, 8);
    printLinkedList(head);
    cout << endl;
    node* newHead = kShort(head, 3);
    printLinkedList(newHead);
    
    return 0;
}


