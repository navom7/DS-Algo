#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if(root == NULL)
        return new Node(key);
    if(key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* InorderScuccessor(Node* root, Node* target) {
    if(target->right != NULL) {
        Node* temp = target->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    } else {
        Node* temp = root;
        Node* successor = NULL;
        while (temp != NULL){
            if(temp->data > target->data) {
                successor = temp;
                temp = temp->left;
            } else if(temp->data < target->data) {
                temp = temp->right;
            } else {
                break;
            }
        }
        return successor;
    }
    return NULL;
}


int main() {
    Node* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(auto s: arr) {
        root = insert(root, s);
    }
    Node* t1 = root->left->right->right;
    Node* t2 = root->right;
    Node* r1 = InorderScuccessor(root, t1);
    Node* r2 = InorderScuccessor(root, t2);
    cout << r1->data << " " << r2->data << endl;

    return 0;
}