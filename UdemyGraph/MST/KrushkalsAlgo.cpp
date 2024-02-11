
/*
How Kruskal's Algorithm Works:
Sort the Edges: Begin by sorting all the edges of the graph in non-decreasing order of their weights.

Initialize MST: Start with an empty graph that will eventually become the MST.

Select the Edges: Iterate through the sorted edges and for each edge, check if adding it to the MST will form a cycle:

If adding the edge does not form a cycle, include it in the MST.
If adding the edge would form a cycle, discard it.
Check Termination: Repeat step 3 until there are 
�
−
1
V−1 edges in the MST, where 
�
V is the number of vertices in the original graph.

Disjoint Set Union (DSU) in Kruskal's Algorithm
Kruskal's algorithm relies heavily on the Disjoint Set Union (DSU) or Union-Find data structure to efficiently manage the sets of vertices and check for cycles. The DSU helps in quickly determining whether two vertices belong to the same set (or component) and thereby assists in cycle detection when considering whether to add an edge to the MST.

*/

#include<iostream>
#include<list>
#include<vector>

using namespace std;

class DSU{
    int* parent;
    int* rank;
public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for(int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int findSet(int i) {
        if(parent[i] == -1) {
            return i;
        }
        return parent[i] = findSet(parent[i]);
    }

    void unite(int a, int b) {
        int s1 = findSet(a);
        int s2 = findSet(b);

        if(s1 != s2) {
            if(rank[s1] > rank[s2]) {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            } else {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
    }
};


class Graph{
    int V;
    vector<vector<int>> edgeList;
public:
    Graph(int n) {
        V = n;
    }

    void addEdge(int a, int b, int w) {
        edgeList.push_back({w, a, b});
    }

    int krushkalMst() {

        DSU d(V);
        sort(edgeList.begin(), edgeList.end());
        int ans = 0;
        for(auto edge: edgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            int s1 = d.findSet(x);
            int s2 = d.findSet(y);

            if(s1 != s2) {
                d.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }

};


int main() {

	Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(1,3,3);
	g.addEdge(3,2,4);
	g.addEdge(2,0,2);
	g.addEdge(0,3,2);
	g.addEdge(1,2,2);
    
	// int n,m;
	// cin>>n>>m;

	// Graph g(n);
	// for(int i=0;i<m;i++){
	// 	int x,y,w;
	// 	cin>>x>>y>>w;
	// 	g.addEdge(x-1,y-1,w);
	// }

	cout<<g.krushkalMst()<<endl;


}