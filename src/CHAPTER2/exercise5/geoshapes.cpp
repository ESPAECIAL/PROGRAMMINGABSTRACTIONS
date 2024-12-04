#include <iostream>
#include <cmath>
#include <cassert>
#include "geoshapes.h"

using namespace std;

double calculatesDistance(GeoPoint a, GeoPoint b) {
    return std::sqrt((a.longitude - b.latitude) * (a.longitude - b.latitude) + (a.longitude - b.longitude) * (a.longitude - b.longitude));
}

double calculatesArea(ShapeType shape) {
    double area;
    switch (shape) {
        case 0:
            return calculatesCircleArea();
            break;
        case 1:
            cout << "Points does not have defined area" << endl;
            return 1;
        case 2:
            cout << "Lines does not have defined area" << endl;
            return 2;
        default:
            cout << "The shape is not known";
            return 3;
    }
}

double calculatesCircleArea() {
    double radius;
    cout << "Enter the radius of the circle" << endl;
    cout << "radius: ";
    cin >> radius;
    return radius * radius * PI;
}

void testCalculatesDistance() {
    GeoPoint p1 = {0.0, 0.0};
    GeoPoint p2 = {3.0, 4.0};
    assert(calculatesDistance(p1, p2) == 5.0);
    cout << "calculateDistance test passed." << endl;
}

void testCalculatesArea() {
    cin.clear();
    cout << "Give a 5 get a successful assert" << endl;
    double area = calculatesArea(CIRCLE);
    assert(area == 25.0 * PI);
    assert(calculatesArea(LINE) == 0.0);
    assert(calculatesArea(POINT) == 0.0);
    cout << "calculateArea test passed." << endl;
}

int main() {
    testCalculatesDistance();
    testCalculatesArea();
    return 0;
}