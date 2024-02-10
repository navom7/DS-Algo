/*
Forest Detection
You are given a list of lists edges representing an undirected graph. Each list contains (u, v) which means there is an undirected edge between nodes u and v. Return whether the graph is a collection of trees.

Constraints

n ≤ 100,000 where n is the length of edges

0 <= u, v <=100,000



Example:

Input

edges = [
    [0, 1],
    [0, 2],
    [3, 4],
    [4, 5]
]
Output

true
Explanation

The first two edges form one tree and the last two edges form another tree.



Expected Time Complexity: O( E ), where E is the number of edges  
*/




#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph{
    int V;
    list<pair<int,int>> l;
public:
    Graph(int v) {
        V = v;
    }
    
    void add_edge(int a, int b) {
        l.push_back({a,b});
    }
    
    int find_set(int i, vector<int> &parent) {
        if(parent[i] == -1) {
            return i;
        }
        return find_set(parent[i], parent);
    }
    
    void union_set(int a, int b, vector<int> &parent) {
        int s1 = find_set(a, parent);
        int s2 = find_set(b, parent);
        
        if(s1 != s2) {
            parent[s2] = s1;
        }
    }
    bool find_cycle(vector<vector<int>>& edges) {
        vector<int> parent(100001, -1);
        for(auto x: edges) {
            int a = x[0];
            int b = x[1];
            
            int s1 = find_set(a, parent);
            int s2 = find_set(b, parent);
            
            if(s1 == s2) {
                return false;
            } else {
                union_set(s1, s2, parent);
            }
        }
        return true;
    }
};

bool solve(vector<vector<int>> edges) {
    Graph g(100001);
    return g.find_cycle(edges);
}

int main() {

    return 0;
}