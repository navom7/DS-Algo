#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

bool isAdjacent(string a, string b) {
    int cnt = 0;
    if(a.length() != b.length())
        return false;
    
    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i])
            cnt++;
    }

    if(cnt == 1)
        return true;

    return false;
}

class Graph{
    unordered_map<string, vector<string>> l;
    int V;
public:
    Graph(int v) {
        V = v;
    }

    void addEdge(string a, string b, bool undir = true) {
        l[a].push_back(b);
        if(undir) {
            l[b].push_back(a);
        }
    }

    int bfs(string beginWord, string end) {
        unordered_map<string, bool> visited;
        unordered_map<string, int> dist;
        queue<string> q;

        dist[beginWord] = 1;
        visited[beginWord] = true;
        q.push(beginWord);


        while(!q.empty()) {
            string frnt = q.front();
            // cout << frnt << ": " << dist[frnt] << endl;
            q.pop();
            for(auto x: l[frnt]) {
                    // cout << x << " " << endl << endl;
                if(!visited[x]) {
                    visited[x] = true;
                    dist[x] = dist[frnt]+1;
                    q.push(x);
                }
            }


        }

        return dist[end];
    }

    void printAdjList() {
        for(auto x: l) {
            cout << x.first << ":---> ";
            for(auto y: x.second) {
                cout << y << ", ";
            }
            cout << endl;
        }
    }

};


int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    int n = wordList.size() + 1;
    Graph g(n);
    for(int i = 0; i < n; i++) {
        if(isAdjacent(beginWord, wordList[i])) {
            // cout << beginWord << "-> " << wordList[i] << endl;
            g.addEdge(beginWord, wordList[i]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(isAdjacent(wordList[i], wordList[j])) {

                // cout << wordList[i] << "-> " << wordList[j] << endl;
                g.addEdge(wordList[i], wordList[j]);
            }
        }
    }

    g.printAdjList();

    return g.bfs(beginWord, endWord);
}


int main() {

    string beginWord = "hit";
    string endWord = "cog";
    
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << ladderLength(beginWord, endWord, wordList) << endl;



    return 0;
}