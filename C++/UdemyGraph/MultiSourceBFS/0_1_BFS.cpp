#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<queue>
#include<deque>
#include<unordered_map>

using namespace std;

#define ll long long
#define um unordered_map
int R;
int C;

class UndirectedWeightedGraph{
    int V;
    list<pair<int,int>> *l;
public:
    UndirectedWeightedGraph(int n) {
        V = n;
        l = new list<pair<int,int>>[V];
    }
    void addEdge(int i, int j, int wt) {
        l[i].push_back({wt, j});
        l[j].push_back({wt, i});
    }

    void bfs(int source) {
        deque<pair<int,int>> dq;
        vector<int> dist(V, INT_MAX);

        dq.push_front({0, source});
        dist[source] = 0;

        while(!dq.empty()) {
            auto ft = dq.front();
            dq.pop_front();
            int distTillNow = ft.first;
            int node = ft.second;
            cout << node << " -> " << distTillNow << endl;

            for(auto nbrPair: l[node]) {
                int edge = nbrPair.first;
                int nbr = nbrPair.second;

                if(dist[nbr] > distTillNow + edge) {
                    dist[nbr] = distTillNow + edge;
                }
                if(edge == 1) {
                    dq.push_back({edge, nbr});
                } else {
                    dq.push_front({edge, nbr});
                }
            }

        }
    }
};



int main() {
    UndirectedWeightedGraph g(7);
    g.addEdge(1,2,1);
    g.addEdge(3,2,0);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(5,4,0);
    g.addEdge(1,5,1);
    g.addEdge(1,6,0);
    g.addEdge(5,6,1);
    g.bfs(1);
    return 0;
}