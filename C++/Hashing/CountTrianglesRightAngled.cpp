
#include<iostream>
#include<unordered_map>

using namespace std;

class Point{
public:
    int x;
    int y;
    Point() {

    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

void CountTraingles(vector<Point> input, int n) {
    unordered_map<int, int> x_axis;
    unordered_map<int, int> y_axis;
    for(auto x: input) {
        x_axis[x.x]++;
        y_axis[x.y]++;
    }

    long count = 0;
    for(int i = 0; i < n; i++) {
        auto p = input[i];
        int x = p.x;
        int y = p.y;
        count += ((x_axis[x]-1)* (y_axis[y]-1));
    }
    cout << count << endl;
    
}

int main() {
    int n; cin >> n;
    vector<Point> inputIndices;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        Point p(x,y);
        inputIndices.push_back(p);
    }

    CountTraingles(inputIndices, n);

    return 0;
}