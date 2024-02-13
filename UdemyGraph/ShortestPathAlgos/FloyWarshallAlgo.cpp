#include<iostream>
#include<vector>
using namespace std;

#define INF 10000

vector<vector<int>> floyd_warshall(vector<vector<int>> graph) {
    int V = graph.size();
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    return graph;
}

int main(){


	// 4 Vertices (4 X 4 Matrix)
	vector<vector<int> > graph = {
								 {0,INF,-2,INF},
								 {4,0,3,INF},
								 {INF,INF,0,2},
								 {INF,-1,INF,0}
								};


	auto result = floyd_warshall(graph);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result.size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}