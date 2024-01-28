// Reconstruct Itinerary
// You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

// All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

// You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

// Constraints

// 1 <= tickets.length <= 300

// tickets[i].length == 2

// fromi.length == 3

// toi.length == 3

// fromi and toi consist of uppercase English letters.

// fromi != toi



// Input : tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}}
// Output : {"JFK","MUC","LHR","SFO","SJC"}
// Expected Time Complexity: O(ElogE ), where E is equal to tickets.length



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