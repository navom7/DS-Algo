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

class SuffixTrie{
    Node* root;
public:
    SuffixTrie() {
        root = new Node('\0');
    }

    void insert_helper(string str) {
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

    bool search(string word) {
        Node* temp = root;
        for(char x: word) {
            if(temp->mp.count(x) == 0) {
                return false;
            }
            temp = temp->mp[x];
        }
        return temp->isTerminal;
    }

    void insert(string word) {
        for(int i = 0; word[i] != '\0'; i++) {
            insert_helper(word.substr(i));
        }
    }
};


int main() {
    string input = "hello";
	string suffixes[] = {"lo","ell","hello"};
    SuffixTrie t;
    t.insert(input);

    for(auto x: suffixes) {
        if(t.search(x)) {
            cout << "\nYES\n";
        } else {
            cout << "\nNO\n";
        }
    }

    return 0;
}