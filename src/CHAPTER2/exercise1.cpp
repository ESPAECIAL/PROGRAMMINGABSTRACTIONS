#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};


Point A = {1.0, 2.0};
Point B = {2.0, 3.0};
Point C = {3.0, 4.0};

double areaOfTriangleWithThreePoints() {
    return (1.0 / 2.0) * std::abs((A.x * (B.y - C.y) + B.x * (C.y - B.y) + C.x * (A.y - B.y)));
}

int main () {
    cout << "The area of the triangle is: " << areaOfTriangleWithThreePoints() << endl;
    return 0;
}