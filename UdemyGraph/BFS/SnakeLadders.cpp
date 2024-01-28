/*
Snakes and Ladder Game
You are playing a snakes & ladder game which is a famous ancient Indian game played on board with dice. Given a Snakes & Ladders board of size N, which contains multiple Snakes & Ladders. You are also given starting & ending point of each snake & ladder in a vector<pair<int,int> >. As per the rules -

If you are bitten by snake (by standing at cell having snake head), you will reach the position where tail of the snake ends.

If you reach a cell, which is also starting point of a ladder, then you will climb that ladder.

Give the board configuration, compute the minimum number of dice throws needed to reach the end of the game starting from cell 1. In each turn you can throw any number from 1 to 6 on the dice to move ahead in the board.
*/



#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V+1];
    }
    
    void addEdge(int i, int j) {
        l[i].push_back(j);
    }
    
    int snakeLadder(int source, int dest) {
        // cout << source << " " << dest << endl << endl;
        queue<int> q;
        vector<bool> visited(V+1, false);
        vector<int> dist(V+1, 0);
        
        
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            cout << front << " " << dist[front] << endl;
            
            for(auto x: l[front]) {
                if(!visited[x]) {
                    visited[x] = true;
                    dist[x] = dist[front] + 1;
                    q.push(x);
                }
            }
            // cout << "-->here ----> " << endl;
            
        }
        for(int i = 0; i <= V; i++) {
            cout << i << " " << dist[i] << endl;
        }
        return dist[dest];
    }
    
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    cout << n << " " << endl;

    vector<int> board(n+1, 0);
    for(auto pr: snakes) {
        int st = pr.first;
        int end = pr.second;
        
        cout << st << "->" << end << " | ";
        
        board[st] = (end-st);
    }
    cout << endl;
    for(auto pr: ladders) {
        int st = pr.first;
        int end = pr.second;
        
        cout << st << "->" << end << " | ";

        board[st] = (end-st);
    }
    cout << endl;
    
    Graph g(n);
    
    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= 6; k++) {
            if((i+k) <= n) {
                // cout << i << " " << k << " " << board[i+k] << endl;
                g.addEdge(i, i + k + board[i+k]);
                cout << i << " ---> " << i + k + board[i+k] << endl;
            }
        }
    }
    
    return g.snakeLadder(1, n);
    
}
