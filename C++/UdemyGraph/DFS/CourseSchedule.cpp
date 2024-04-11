/*
Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

Constraints:

1 <= numCourses <= 10^5

0 <= prerequisites.length <= 5000

prerequisites[i].length == 2

0 <= ai, bi < numCourses

All the pairs prerequisites[i] are unique.

Sample input :  numCourses = 2  prerequistics : [[1,0]]
Sample Output : true
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }
    
    void addEdge(int a, int b) {
        l[a].push_back(b);
    }
    
    bool dfs(int source, vector<bool> &visited, vector<bool> &instack) {
        visited[source] = true;
        instack[source] = true;
        
        for(auto x: l[source]) {
            if(!visited[x]) {
                bool foundCycle = dfs(x, visited, instack);
                if(foundCycle)
                    return true;
            } else if(instack[x]) {
                return true;
            }
        }
        instack[source] = false;
        return false;
    }
};

bool canFinish(vector<vector<int>> prerequisites,int numCourses) {
    Graph g(numCourses);
    
    for(auto x: prerequisites) {
        g.addEdge(x[0], x[1]);
    }
    vector<bool> visited(numCourses, false);
    vector<bool> instack(numCourses, false);
    
    for(int i = 0; i < numCourses; i++) {
        if(!visited[i]) {
            bool isCyclePresent = g.dfs(i, visited, instack);
            if(isCyclePresent)
                return false;
        }
    }
    return true;
    
    
}


int main(){


    return 0;
}



