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

void printInorder(Node* root) {
    if(root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
    return;
}


int main() {
    Node* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(auto s: arr) {
        root = insert(root, s);
    }

    printInorder(root);


    return 0;
}