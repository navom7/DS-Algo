
#include<iostream>
#include<set>

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

class Compare{
public:
    bool operator() (Point a, Point b) {
        if(a.x == b.x) {
            return a.y < b.y;
        } else {
            return a.x < b.x;
        }
    }
};

void CoutRectangles(vector<Point> input, int n, set<Point, Compare> freq) {
    long count = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            auto a = input[i];
            auto b = input[j];

            if(a.x == b.x or a.y == b.y) {
                continue;
            }

            Point c(a.y, b.x);
            Point d(a.x, b.y);
            if(freq.find(c) != freq.end() and freq.find(d) != freq.end()) {
                count++;
            }
        }
    }
    cout << count << endl;
    
}

int main() {
    int n; cin >> n;
    vector<Point> inputIndices;
    set<Point, Compare> freq;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        Point p(x,y);
        freq.insert(p);
        inputIndices.push_back(p);
    }

    CoutRectangles(inputIndices, n, freq);

    return 0;
}