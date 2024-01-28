/*
Keys and Rooms
There are N rooms and you start in room 0. Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room.

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length. A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0).

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Constraints:

1 <= rooms.length <= 1000

0 <= rooms[i].length <= 1000

The number of keys in all rooms combined is at most 3000.



Expected Time Complexity: O(N + E), where N is the number of rooms, and E is the total number of keys.
*/



#include<iostream.h>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;


class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int a, int b, bool undir = true) {
        l[a].push_back(b);
        if(undir) {
            l[b].push_back(a);
        }
    }

    void dfs(vector<bool> &visited, int source) {
        for(auto x: l[source]) {
            if(!visited[x]) {
                visited[x] = true;
                dfs(visited, x);
            }
        }
    }


};



bool canVisitAllRooms(vector<vector<int>> rooms) {
    int n = rooms.size();
    Graph g(n);
    
    for(int i = 0; i < n; i++) {
        for(int x: rooms[i]) {
            g.addEdge(i, x);
        }
    }

    vector<bool> visited(n, false);
    visited[0] = true;
    g.dfs(visited, 0);
    for(auto x: visited) {
        if(!x) {
            return false;
        }
    }
    return true;

}




int main() {


}