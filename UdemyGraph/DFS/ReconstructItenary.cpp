#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

bool customCompare(vector<string> a, vector<string> b) {
    if(a[0] == b[0]) {
        return a[1] < b[1];
    }
    
    return a[0] < b[0];
}

class Graph{
    unordered_map<string, set<string>> mp;
public:

    void addEdge(string a, string b) {
        mp[a].insert(b);
    }

    void dfsHelper(unordered_map<string, bool> &visited, string source, vector<string> &result){
        visited[source] = true;
        result.push_back(source);
        for(auto x: mp[source]) {
            if(!visited[x]) {
                dfsHelper(visited, x, result);
            }
        }
    }

    vector<string> dfs(string source) {
        unordered_map<string, bool> visited;
        vector<string> result;

        dfsHelper(visited, source, result);
        return result;
    }


};

vector<string> findItinerary(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), customCompare);
    int N = tickets.size();

    Graph g;
    for(auto x: tickets) {
        g.addEdge(x[0], x[1]);
    }

    return g.dfs("JFK");
    
}