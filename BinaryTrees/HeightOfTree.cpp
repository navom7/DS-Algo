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
        right = NULL;;

        []=-

    }

};

Node* buildTree() {
    int d;
    cin >> d;
    if(d == -1)
        return NULL;
    Node* node = new Node(d);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

int heightOfTree(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int l = heightOfTree(root->left);
    int r = heightOfTree(root->right);
    return 1 + max(l, r);
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
    Node* root = buildTree();
    cout << endl << heightOfTree(root) << endl;
}