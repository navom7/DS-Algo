#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
#include<set>

using namespace std;

#define ll long long
#define um unordered_map
int R;
int C;


class Graph{
    int V;
    list<pair<int,int>> *l;
public:
    Graph(int n) {
        V = n;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int a, int b, int wt) {
        l[a].push_back({wt,b});
        l[b].push_back({wt,a});
    }

    int dijkshtra(int source, int dest) {
        set<pair<int,int>> st;
        vector<int> dist(V, INT_MAX);
        st.insert({0, source});
        dist[source] = 0;

        while(!st.empty()) {
            auto it = st.begin();
            int distTillNow = it->first;
            int node = it->second;
            st.erase(it);

            for(auto nbrPair: l[node]) {
                int edgeDist = nbrPair.first;
                int nbr = nbrPair.second;

                if(dist[nbr] > distTillNow+edgeDist) {
                    auto idx = st.find({dist[nbr], nbr});
                    if(idx != st.end()) {
                        st.erase(idx);
                    }

                    dist[nbr] = distTillNow+edgeDist;
                    st.insert({dist[nbr], nbr});
                }
            }

        }
        for(int i = 0; i < V; i++) {
            cout << i << " " << dist[i] << endl;
        }
        return dist[dest];
    }
};


int main() {
    Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkshtra(0,4) << endl;
    
    return 0;
}