#include<iostream>
#include<climits>
#include<set>
#include<list>

using namespace std;

class Node{
public:
    int x;
    int y;
    int dist;
    Node(int i, int j, int dist) {
        this->x = i;
        this->y = j;
        this->dist = dist;
    }
    
};

class Compare{
public:
    bool operator() (const Node &a, const Node &b) {
        return a.dist <= b.dist;
    }
    
};

int shortest_path(vector<vector<int> > grid){
    int M = grid.size();
    int N = grid[0].size();
    
    int i = 0;
    int j = 0;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    
    vector<vector<int>> dist(M+1, vector<int>(N+1, INT_MAX));
    set<Node, Compare> st;
    
    dist[0][0] = grid[0][0];
    
    st.insert(Node(0, 0, dist[0][0]));
    
    while(!st.empty()) {
        auto it = st.begin();
        int cx = it->x;
        int cy = it->y;
        int cd = it->dist;
        st.erase(it);
        
        for(int k = 0; k < 4; k++) {
            int nx = cx+dx[k];
            int ny = cy+dy[k];
            
            if(nx >= 0 and ny >= 0 and nx < M and ny < N and ((cd + grid[nx][ny]) < dist[nx][ny])) {
                cout << cd << " " << nx << " " << ny << endl;
                Node temp(nx, ny, (grid[nx][ny]));
                
                if(st.find(temp) != st.end()) {
                    st.erase(st.find(temp));
                }
                
                int nd = grid[nx][ny] + cd;
                
                dist[nx][ny] = nd;
                
                st.insert(Node(nx, ny, nd));
            }
        }
        
    }
    
    
    return dist[M-1][N-1];
  
}

int main() {
 

    return 0;
}