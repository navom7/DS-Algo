#include<iostream>
#include<unordered_map>

using namespace std;

class Node{
public:
    char data;
    unordered_map<char, Node*> mp;
    bool isTerminal;

    Node(char ch) {
        data = ch;
        isTerminal = false;
    }
};

class Trie{
    Node* root;
public:
    Trie() {
        root = new Node('\0');
    }

    void insert(string str) {
        Node* temp = root;
        for(char x: str) {
            if(temp->mp.count(x) == 0) {
                Node* newNode = new Node(x);
                temp->mp[x] = newNode;
            }
            temp = temp->mp[x];
        }
        temp->isTerminal = true;
    }

    void searchHelper(){

    }

    bool documentSearch(string document, string[] words) {
        Trie t;
        for(auto x: words) {
            t.insert(x);
        }
        
    }

};



int main() {
    string words[] = {"apple", "ape", "no", "news", "not", "never"};
    Trie t;
    for(auto w: words) {
        t.insert(w);
    }

    int q; cin >> q;
    while(q--) {
        string query; cin >> query;
        if(t.search(query)) {
            cout << "\nYES\n";
        } else {
            cout << "\nNO\n";
        }
    }


    return 0;
}