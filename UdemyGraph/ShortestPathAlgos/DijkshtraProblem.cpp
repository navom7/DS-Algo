/*

Dijkstra
You are given a weighted undirected graph.

The vertices are enumerated from 1 to n.

Your task is to find the shortest path between the vertex 1 and the vertex n.(It is sure that there is only one possible answer)

Constraints

2≤ n ≤10^5

0≤ xi,yi,weight ≤10^4

All input values are integers.

Input : n = 5, edges = {{1,2,2},{2, 5, 5},{2, 3, 4},{1, 4, 1},{4, 3, 3},{3, 5, 1}}
Output : { 1, 4, 3, 5 }

*/

#include<iostream>
#include<vector>
#include<set>
#include<list>
using namespace std;


class Graph{

	int V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}

	void addEdge(int u,int v,int wt, bool undir = true){

		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}

    vector<int> dijkshtra(int source) {
        vector<int> dist(V, INT_MAX);
        set<pair<int,int>> s;
        vector<int> parent(V, -1);
        
        dist[source] = 0;
        s.insert({0, source});
        
        while(!s.empty()) {
            auto it = s.begin();
            int distTillNow = it->first;
            int node = it->second;
            s.erase(it);
            
            for(auto nbrs: l[node]) {
                int nbr = nbrs.second;
                int edge = nbrs.first;
                
                if(dist[nbr] > distTillNow + edge) {
                    auto idx = s.find({dist[nbr], nbr});
                    if(idx != s.end()) {
                        s.erase(idx);
                    }
                    parent[nbr] = node;
                    dist[nbr] = distTillNow + edge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        return parent;
    }


};


vector<int> shortestPath(vector<vector<int>> roads,int n)
{
    Graph g(n+1);
    for(auto x: roads) {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
        g.addEdge(x[0], x[1], x[2]);
    }
    vector<int> parent = g.dijkshtra(1);
    
    int temp = n;
    cout << endl;
    vector<int> result;
    while(parent[temp] != -1) {
        cout << temp << " ";
        result.push_back(temp);
        temp = parent[temp];
    }
    result.push_back(temp);
    reverse(result.begin(), result.end());
    return result;
}

int main() {


    return 0;
}