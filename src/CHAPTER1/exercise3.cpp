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

Vector createsVectorsWithPoints(Point p1, Point p2) {
    Vector vector;
    vector.x = p1.x - p2.x;
    vector.y = p1.y - p2.y;
    vector.z = p1.z - p2.z;
    return vector;
}

bool isTheTriangleRectangle(Point a, Point b, Point c) {
    Vector ab = createsVectorsWithPoints(a, b);
    Vector bc = createsVectorsWithPoints(b, c);
    Vector ac = createsVectorsWithPoints(a, c);
    double abac = ab.x * ac.x + ab.y * ac.y + ab.z * ac.z;
    double abbc = ab.x * bc.x + ab.y * bc.y + ab.y * bc.y;
    double acbc = ac.x * bc.x + ac.y * bc.y + ac.z * bc.z;
    return abac == 0 || abbc == 0 || acbc == 0;
}

string isTheTriangleFormedBy3DotsRectangleWithLabel(Point a, Point b, Point c) {
    if (isTheTriangleRectangle(a, b, c))
        return "The triangle formed with the Dots is rectangle";
    return "The triangle formed with the Dots is not rectangle";
}

int main() {
    Point a1 = {0, 0, 0};
    Point b1 = {3, 0, 0};
    Point c1 = {0, 4, 0};
    Point a2 = {0, 0, 0};
    Point b2 = {2, 2, 0};
    Point c2 = {1, 3, 0};
    cout << "(" << to_string(a1.x) << ", " << to_string(a1.y) << ", " << to_string(a1.z) << "), ";
    cout << "(" << to_string(b1.x) << ", " << to_string(b1.y) << ", " << to_string(b1.z) << "), ";
    cout << "(" << to_string(c1.x) << ", " << to_string(c1.y) << ", " << to_string(c1.z) << ")" << endl;
    cout << isTheTriangleFormedBy3DotsRectangleWithLabel(a1, b1, c1) << endl;
    cout << "(" << to_string(a2.x) << ", " << to_string(a1.y) << ", " << to_string(a1.z) << "), ";
    cout << "(" << to_string(b2.x) << ", " << to_string(b2.y) << ", " << to_string(b2.z) << "), ";
    cout << "(" << to_string(c2.x) << ", " << to_string(c2.y) << ", " << to_string(c2.z) << ")" << endl;
    cout << isTheTriangleFormedBy3DotsRectangleWithLabel(a2, b2, c2) << endl;
    return 0;
}