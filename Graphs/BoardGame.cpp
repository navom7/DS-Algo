#include<iostream>
#include<list>
#include<unordered_map>
#include<unordered_set>

using namespace std;


#define M 3 
#define N 4 

class Node{
public:
    char data;
    unordered_map<char, Node*> children;
    bool isTerminal;
    string word;

    Node(char ch) {
        data = ch;
        isTerminal = false;
        word = "";
    }

};

class Trie{
public:
    Node* root;

    Trie() {
        root = new Node('\0');
    }

    void insert(string word) {
        Node* temp = root;

        for(auto x: word) {
            if(temp->children.count(x) == 0) {
                temp->children[x] = new Node(x);
            }
            temp = temp->children[x];
        }
        temp->isTerminal = true;
        temp->word = word;
        // cout << "word: ||" << temp->word << "||" << endl;
    }

    void dfs(Node* node, int i, int j, char board[M][N], bool visited[][N], unordered_set<string> &output) {
        char ch = board[i][j];
        if(node->children.count(ch) == 0) {
            // cout << "ch with no node: " << ch << endl;
            return;
        }

        visited[i][j] = true;
        node = node->children[ch];


        // cout << "word: |" << node->word << "|" << ch << "|" << node->isTerminal << endl;

        if(node->isTerminal) {
            // cout << "word: ||" << node->word << "||" << endl;
            output.insert(node->word);
        }

        int dx[] = {0, 1 , 1 ,1, 0, -1, -1,-1};
	    int dy[] = {-1,-1, 0, 1, 1, 1, 0, -1};

        for(int k = 0; k < 8; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni>=0 and nj>=0 and ni < M and nj < N and !visited[ni][nj]){
                dfs(node,ni,nj,board,visited,output);
            }
        }

        visited[i][j] = false;
        return;
    }



};


int main() {

    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO","TUNES","CAT"};
    
    char board[M][N] = { { 'S', 'E', 'R' ,'T'}, 
                          { 'U', 'N', 'K' ,'S'},
                          { 'T', 'C', 'A' ,'T'} };

    Trie t;
    for(auto w: words) {
        t.insert(w);
    }



    unordered_set<string> output;

    bool visited[M][N] = {0};

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            t.dfs(t.root, i, j, board, visited, output);
        }
    }

    for(auto word: output) {
        cout << "word: " << word << endl;
    }

    return 0;
}