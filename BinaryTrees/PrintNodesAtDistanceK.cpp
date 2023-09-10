// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1


#include<iostream>
#include<queue>


using namespace std;


class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }

};

void printAtLevelK(Node* root, int k) {
    if(root == NULL){
        return;
    }
    if(k == 0) {
        cout << root->data << " ";
        return;
    }
    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
    return;
}

int printNodesAtDistanceK(Node* root, Node* target, int k) {
    if(root == NULL)
        return -1;

    if(root == target){
        printAtLevelK(root, k);
        return 0;
    }

    int DL = printNodesAtDistanceK(root->left, target, k);
    if(DL != -1){
        if(DL+1 == k){
            cout << root->data << " ";
        } else
            printAtLevelK(root->right, k-2-DL);
        return DL + 1;
    }

    int DR = printNodesAtDistanceK(root->right, target, k);
    if(DR != -1){
        if(DR+1 == k){
            cout << root->data << " ";
        } else
            printAtLevelK(root->left, k-2-DR);
        return DR + 1;
    }
    return -1;
}



void levelOrderPrint(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        if(node == NULL) {
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        } else {
            cout << node->data << " ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

    }
}



int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->left->right->right = new Node(9);
    root->right->right->right = new Node(10);
    root->right->right->right->right = new Node(10);

    Node* target = root->left->right;
    // levelOrderPrint(root);
    printNodesAtDistanceK(root, target, 2);
    
}