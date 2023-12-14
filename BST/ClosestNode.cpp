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

int findClosestInBST(Node* root, int target) {
    Node* temp = root;
    int diff = INT_MAX;
    int closest;

    while(temp != NULL) {
        int curr_diff = abs(target-temp->data);
        if(curr_diff == 0) {
            return temp->data;
        }
        if(curr_diff < diff) {
            closest = temp->data;
            diff = curr_diff;
        }

        if(target > temp->data) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return closest;
}


int main() {
    Node* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(auto s: arr) {
        root = insert(root, s);
    }

    cout << findClosestInBST(root, 12);


    return 0;
}