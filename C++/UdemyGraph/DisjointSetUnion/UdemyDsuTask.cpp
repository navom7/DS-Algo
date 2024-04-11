/*
Disjoint Set Union
Implement disjoint sets union data structure. You have to perform queries of two types:

1 u v — unite two sets that contain u and v , respectively;

2 u v — check that two elementsuand v belong to the same set.

You will be given an array of query, each query contains three integer query type x , u, and v .

Output a vector containing answer for each type 2 query True if u and v belong to the same set otherwise false  respectively.

Constraints:

1<=u, v<=10^5

Example:

Input: query = [[1,1,2],[1,1,3],[2,1,4],[2,2,3]] 
 
Output: {false, true}
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
    
    void addEdge(int a, int b) {
        l.push_back(make_pair(a,b));
    }
    
    int findSet(int i, int parent[]) {
        cout << i << " and parent is: " << parent[i] << endl;
        if(parent[i] == -1) {
            return i;
        }
        return findSet(parent[i], parent);
    }
    
    void union_st(int a, int b, int parent[]) {
        int s1 = findSet(a, parent);
        int s2 = findSet(b, parent);
        
        if(s1 != s2) {
            parent[s2] = s1;
        }
    }
    
    
    
};

vector<bool> DSU(vector<vector<int>>query)
{
    int v = query.size();
    Graph g(100001);
    int* parent = new int[100001];
    for(int i = 0; i <= 100000; i++) {
        parent[i] = -1;
    }
    vector<bool> res;
    
    for(auto x: query) {
        int op = x[0];
        int u = x[1];
        int v = x[2];
        cout << op <<" " << u << " " << v << endl;
        if(op == 1) {
            g.union_st(u,v, parent);
        } else {
            int s1 = g.findSet(u, parent);
            int s2 = g.findSet(v, parent);
            cout << s1 << " " << s2 << " : s1 and s2" << endl;
            res.push_back(s1 == s2);
        }
    }
    delete [] parent;
    return res;
}