/*
Find the minimum spanning tree of the graph.

Input
On the first line there will be two integers N - the number of nodes and M - the number of edges. (1 <= N <= 10000), (1 <= M <= 100000)
M lines follow with three integers i j k on each line representing an edge between node i and j with weight k. The IDs of the nodes are between 1 and n inclusive. The weight of each edge will be <= 1000000.

Output
Single number representing the total weight of the minimum spanning tree on this graph. There will be only one possible MST.

Example
Input:
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40

Output:
17






How Prim's Algorithm Works:
Initialization: Start with an empty set S that will eventually contain all the vertices of the MST. Select an arbitrary vertex to begin the MST and add it to S.

Edge Selection: From the set of edges that connect vertices in S to vertices outside S, select the edge with the smallest weight and add it to the MST. Also, add the vertex at the other end of this edge to S.

Repeat: Repeat step 2 until S includes all vertices of the graph.

Completion: When all vertices are included in S, the MST is complete.

Key Points:
Prim's algorithm can start from any vertex, making it especially useful for dense graphs.
It can be implemented using various priority queue data structures to select the minimum weight edge efficiently, such as a binary heap, a Fibonacci heap, or even a simple array.
The complexity of Prim's algorithm depends on the data structures used for the priority queue. With a binary heap, the time complexity is 
�
(
�
log
⁡
�
)
O(ElogV), where 
�
E is the number of edges, and 
�
V is the number of vertices.
*/


#include<iostream>
#include<list>
#include<vector>
#include<queue>


using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *l;
public:
    Graph(int n) {
        V = n;
        l = new list<pair<int,int>> [n];
    }

    void addEdge(int x, int y, int w) {
        l[x].push_back({y, w});
        l[y].push_back({x,w});
    }

    int primsMst(int source) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
        bool * visited = new bool[V]{false};

        Q.push({0,source});
        int ans = 0;

        while(!Q.empty()) {
            // cout << "here->" << endl;
            auto pr = Q.top();
            Q.pop();

            int w = pr.first;
            int node = pr.second;

            if(visited[node]) {
                continue;
            }
            visited[node] = true;
            ans += w;
            for(auto nbr: l[node]) {
                int nw = nbr.second;
                int nnode = nbr.first;
                if(!visited[nnode]) {
                    Q.push({nw, nnode});
                }
            }
        }
        return ans;
    }
};



int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N+1);
    while(M--) {
        int a, b, c;
        cin >> a >> b >> c;
        g.addEdge(a,b,c);
    }

    cout << g.primsMst(1) << endl;
}