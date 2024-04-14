#include <iostream>
#include <unordered_map>
using namespace std;

// TrieNode class representing a node in the Trie
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() {
        isEnd = false;
    }
};

// Trie class to represent the Trie data structure
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    // Time Complexity: O(L), where L is the length of the word
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }

    // Search if a word exists in the Trie
    // Time Complexity: O(L), where L is the length of the word
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEnd;
    }

    // Check if any word starts with the given prefix
    // Time Complexity: O(P), where P is the length of the prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }

    // Delete a word from the Trie
    // Time Complexity: O(L), where L is the length of the word
    void erase(string word) {
        TrieNode* curr = root;
        eraseHelper(curr, word, 0);
    }

private:
    bool eraseHelper(TrieNode* node, string& word, int depth) {
        if (depth == word.length()) {
            if (!node->isEnd) {
                return false; // Word not found
            }
            node->isEnd = false;
            return node->children.empty(); // Check if node has no children
        }

        char c = word[depth];
        if (node->children.find(c) == node->children.end()) {
            return false; // Word not found
        }

        bool shouldDeleteCurrentNode = eraseHelper(node->children[c], word, depth + 1);

        if (shouldDeleteCurrentNode) {
            delete node->children[c];
            node->children.erase(c);
            return node->children.empty();
        }

        return false;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;

    trie.insert("app");
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;

    trie.erase("apple");
    cout << "Search 'apple' after deletion: " << (trie.search("apple") ? "Found" : "Not Found") << endl;

    return 0;
}
