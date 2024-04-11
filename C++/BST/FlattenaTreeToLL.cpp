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

pair<Node*, Node*> flattenTree(Node* root) {
    if(root==NULL || (root->left == NULL && root->right == NULL)) {
        return make_pair(root,root);
    }
    Node* newHead = root;
    Node* newTail = root;
    if(root->left != NULL) {
        pair<Node*, Node*> pl = flattenTree(root->left);
        pl.second->right = root;
        newHead = pl.first;
    }
    if(root->right != NULL) {
        pair<Node*, Node*> pr = flattenTree(root->right);
        root->right = pr.first;
        newTail = pr.second;
    }
    return make_pair(newHead, newTail);
}

void printFlattenTree(Node* root) {
    while(root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    return;
}


int main() {
    Node* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(auto s: arr) {
        root = insert(root, s);
    }

    pair<Node*, Node*> np = flattenTree(root);
    printFlattenTree(np.first);


    return 0;
}