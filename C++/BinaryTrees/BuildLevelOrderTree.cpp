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

Node* buildTree(vector<int> &vec) {
    Node* root = new Node(vec[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < vec.size()) {
        Node* frnt = q.front();
        q.pop();
        int a = vec[i++];
        int b = vec[i++];
        if(a != -1) {
            Node* temp = new Node(a);
            frnt->left = temp;
            q.push(temp);
        }
        if(b != -1) {
            Node* temp = new Node(b);
            frnt->right = temp;
            q.push(temp);
        } 
    }
    return root;
}

Node* buildTreeWithInput() {
    int n; cin >> n;
    Node* root = new Node(n);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* frnt = q.front();
        q.pop();
        int a, b; 
        cin >> a >> b;
        if(a != -1) {
            Node* temp = new Node(a);
            frnt->left = temp;
            q.push(temp);
        }
        if(b != -1) {
            Node* temp = new Node(b);
            frnt->right = temp;
            q.push(temp);
        } 
    }
    return root;
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
    vector<int> vec = {1,2,3,4,5,-1,6, -1, -1, 7, -1, -1, -1, -1,};
    // Node* root = buildTree(vec);
    Node* root = buildTreeWithInput();
    levelOrderPrint(root);
}