//diameter of a tree
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


int diameter(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int D1 = heightOfTree(root->left) + heightOfTree(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));
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
    cout << diameter(root) << endl;
}