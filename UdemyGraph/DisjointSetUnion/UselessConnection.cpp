/*
Useless Connection
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.



Sample Test Case :



Example 1:



Input:

edges = {{1,2},{1,3},{2,3}}

Output:

{2,3}



Example 2:



Input:

edges = {{1,2},{2,3},{3,4},{1,4},{1,5}}

Output:

{1,4}



Constraints:

n == edges.length

3 <= n <= 1000

edges[i].length == 2

1 <= ai < bi <= edges.length

ai != bi

There are no repeated edges.

The given graph is connected.

Expected Time Complexity: O( n+m ), where m is the number of edges
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
    vector<int> find_cycle(vector<vector<int>>& edges) {
        vector<int> parent(100001, -1);
        for(auto x: edges) {
            int a = x[0];
            int b = x[1];
            
            int s1 = find_set(a, parent);
            int s2 = find_set(b, parent);
            
            if(s1 == s2) {
                return {a, b};
            } else {
                union_set(s1, s2, parent);
            }
        }
        return {};
    }
};


vector<int> findUselessConnection(vector<vector<int>> edges) {
    Graph g(1001);
    return g.find_cycle(edges);
}




