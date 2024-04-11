#include<iostream>
#include<list>
#include<climits>

using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if(undir) {
            l[j].push_back(i);
        }
    }

    int findCenter() {
        int cnt = INT_MIN, ans = 0;
        for(int i = 0; i < V; i++) {
            int sz = l[i].size();
            if(sz > cnt) {
                ans = i;
                cnt = sz;
            }
        }
        return ans;
    }

};

int findCenter(vector<vector<int>>edges)
{
    int n = edges.size()+2;
    Graph g(n);
    for(auto x: edges) {
        g.addEdge(x[0], x[1]);
    }
    return g.findCenter();
}


int main() {
    vector<vector<int>> edges = 
    {
        {1,2},
        {2,3},
        {4,2}
    };
    cout << findCenter(edges);


    return 0;
}