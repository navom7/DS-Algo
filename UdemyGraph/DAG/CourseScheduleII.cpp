/*
Course Schedule II
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return lexicographically smallest of them. If it is impossible to finish all courses, return an empty array.

Constraints:

1 <= numCourses <= 2000

0 <= prerequisites.length <= numCourses * (numCourses - 1)

prerequisites[i].length == 2

0 <= ai, bi < numCourses

ai != bi

All the pairs [ai, bi] are distinct.



Expected Time Complexity: O(V + E) where V represents the number of vertices and E represents the number of edges.
*/


#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
    vector<int> indegree(n, 0);
    vector<int> res;
    vector<vector<int> > adjList(n);
    set<int> q;
    
    for(auto edge: prerequisites) {
        int x = edge[0];
        int y = edge[1];
        
        indegree[x]++;
        adjList[y].push_back(x);
        
    }
    
    
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.insert(i);
        }
    }
    
    if(q.empty()) {
        return {};
    }
    
    while(!q.empty()) {
        auto it = q.begin();
        int f = *it;
        res.push_back(f);
        q.erase(it);
        for(auto nbr: adjList[f]) {
            indegree[nbr]--;
            if(indegree[nbr] == 0) {
                q.insert(nbr);
            }
        }
    }
    if(q.empty()) {
        return res;
    }
    return {};
}

