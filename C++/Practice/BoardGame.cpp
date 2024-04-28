#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>

using namespace std;

class Node{
public:
    char ch;
    bool isTerminal;
    unordered_map<char, Node*> mps;
    string word;
    Node(char ch) {
        ch = ch;
        word = "";
        isTerminal = false;
    }
};

class Trie{
    Node* root;
public:
    Trie() {
        root = new Node('\0');
    }
    void addWords(vector<string> vec) {
        for(auto str: vec) {
            Node* temp = root;
            for(auto ch: str) {
                if(temp->mps[ch] != NULL) {
                    temp = temp->mps[ch];
                } else {
                    temp->mps[ch] = new Node(ch);
                    temp = temp->mps[ch];
                }
            }
            temp->isTerminal = true;
            temp->word = str;
        }
    }

    bool isPresent(string str) {
        Node* temp = root;
        for(char ch: str) {
            if(temp->mps[ch] == NULL) {
                return false;
            }
            temp = temp->mps[ch];
        }
        return temp->isTerminal;
    }

};

int main() {
    vector<string> vec = {"nanhe", "nandu", "pandey", "apple", "app", "appel"};
    Trie t;
    t.addWords(vec);
    if(t.isPresent("app")) {
        cout << " yes present\n";
    } else {
        cout << "not present\n";
    }

    if(t.isPresent("apple")) {
        cout << " yes present\n";
    } else {
        cout << "not present\n";
    }
    
    if(t.isPresent("applee")) {
        cout << " yes present\n";
    } else {
        cout << "not present\n";
    }

    if(t.isPresent("nande")) {
        cout << " yes present\n";
    } else {
        cout << "not present\n";
    }
    return 0;
}