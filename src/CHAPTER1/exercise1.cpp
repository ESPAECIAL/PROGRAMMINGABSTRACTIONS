#include <iostream>
#include <cmath>
using namespace std;

enum A {
    ax = 1,
    ay = 2,
    az = 3,
};

enum B {
    bx = 0,
    by = 9,
    bz = 1,
};

double euclideanDistance() {
    double ax = static_cast<double>(A::ax);
    double ay = static_cast<double>(A::ay);
    double az = static_cast<double>(A::az);
    double bx = static_cast<double>(B::bx);
    double by = static_cast<double>(B::by);
    double bz = static_cast<double>(B::bz);
    return std::sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by) + (az - bz) * (az - bz));
}

int main() {
    cout << "The euclidean distance between A and B is " << euclideanDistance() << endl;
    return 0;
}
