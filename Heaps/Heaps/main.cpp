// Given n Cartesian points in a 2D plane each prepresents the location of the cab.
// You are stading at origin, you want to know the names of nearest k cars


#include<iostream>
#include<queue>

using namespace std;


class Car{
public:
    string id;
    int x;
    int y;
    Car(string id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist() const {
        return x*x + y*y;
    }
};

class CarCompare {
public:
    bool operator() (const Car a, const Car b) {
        return a.dist() < b.dist();
    }
};


bool findNearestCars(vector<Car> cars, int k, int n) {
    priority_queue<Car, vector<Car>, CarCompare> carsQ(cars.begin(), cars.begin() + k);

    for(int i = k; i < n; i++) {
        auto car = cars[i];
        if(carsQ.top().dist() > car.dist()) {
            carsQ.pop();
            carsQ.push(car);
        }
    }
    vector<Car> vec;
    while(!carsQ.empty()) {
        vec.push_back(carsQ.top());
        carsQ.pop();
    }
    reverse(vec.begin(), vec.end());
    for(auto x: vec) {
        cout << x.id << " " << x.dist() << endl;
    }
    return true;
}



int main() {
    int n, k;
    cin >> n >> k;
    vector<Car> input;
    while(n--) {
        string id;
        int x, y;
        cin >> id >> x >> y;
        Car c(id, x, y);
        input.push_back(c);
    }
    findNearestCars(input, k, 5);

    return 0;
}
