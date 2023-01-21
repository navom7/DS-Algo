#include<iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T> * next;
    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

int main() {
    Node<int> * node = new Node<int>(10);
    // cout << node->data << endl;
    node->next = new Node<int>(11);
    // cout << node->next->data;
    
    while(node != NULL) {
        cout << node->data << "-->";
        node = node->next;
    }
    
    return 0;
}
