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