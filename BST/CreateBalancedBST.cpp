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

Node* BalancedBST(int start, int end, int arr[]) {
    if(start > end)
        return NULL;
    int mid = start + (end-start)/2;
    Node* root = new Node(arr[mid]);
    root->left = BalancedBST(start, mid-1, arr);
    root->right = BalancedBST(mid+1, end, arr);
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
    int arr[] = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    
    root = BalancedBST(0, 8, arr);

    printInorder(root);


    return 0;
}