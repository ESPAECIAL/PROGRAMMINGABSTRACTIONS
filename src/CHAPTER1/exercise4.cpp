#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
    double z;
};

struct Vector {
    double x;
    double y;
    double z;
};

Point A = {1.0, 1.0, 3.0};
Point B = {2.0, 1.0, -2.0};
Point C = {1.0, 0.0, 1.0};
Vector AB, AC;

Vector vectorizeTwoPoints(Point p1, Point p2) {
    return {x: p1.x - p2.x,y: p1.y - p2.y,z: p1.z - p1.z};
}

Vector calculatesCrossProduct(Vector v1, Vector v2) {
    Vector crossProduct;
    crossProduct.x = v1.y * v2.z - v2.z * v1.y;
    crossProduct.y = v1.z * v2.x - v2.x * v1.z;
    crossProduct.z = v1.x * v2.y - v2.y * v1.x;
    return crossProduct;
};

double calculatesVectorMagnitude(Vector v) {
    return ::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
};

double calculatesAreaOfCrossedProducts(Vector crossedVectors) {
    double vectorMagnitude = calculatesVectorMagnitude(crossedVectors);
    return vectorMagnitude * 0.5;
};

int main() {
    AB = vectorizeTwoPoints(A, B);
    AC = vectorizeTwoPoints(A, C);
    Vector crossedABAC = calculatesCrossProduct(AB, AC);
    double area = calculatesAreaOfCrossedProducts(crossedABAC);
    cout << "The area of the 3D triangle is " << area << endl;
    return 0;
}