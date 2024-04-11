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

class TreeNode{
public:
    int inc;
    int exc;
    TreeNode(int a, int b) {
        inc = a;
        exc = b;
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


TreeNode subTreeSum(Node* &root) {
    TreeNode t(0,0);
    if(root == NULL) {
        return t;
    }
    TreeNode L = subTreeSum(root->left);
    TreeNode R = subTreeSum(root->right);
    //including root dataac
    int inc = root->data + L.exc + R.exc;
    //excluding root data
    int exc = max(L.inc, L.exc) + max(R.inc, R.exc);

    t.inc = inc;
    t.exc = exc;
    return t;

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
    TreeNode newRoot = subTreeSum(root);
    cout << endl << newRoot.inc << " " << newRoot.exc << endl;
}