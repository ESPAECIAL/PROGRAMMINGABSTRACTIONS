#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

double areaOfTriangleWithThreePoints(Point a, Point b, Point c) {
    return 0.5 * std::abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

bool areThreePointsCollinear(Point a, Point b, Point c) {   
    return areaOfTriangleWithThreePoints(a, b, c) == 0;
}

string printsCollinearityOfThreePoints(Point a, Point b, Point c) {
    return areThreePointsCollinear(a, b, c) ? "The points are collinear." : "The points are not collinear.";
}


int main () {
    Point p1 = {1.0, 2.0};
    Point p2 = {2.0, 3.0};
    Point p3 = {3.0, 4.0};
    cout << printsCollinearityOfThreePoints(p1, p2, p3) << endl;
    Point p4 = {1.0, 1.0};
    Point p5 = {1.0, 2.0};
    Point p6 = {2.0, 4.0};
    cout << printsCollinearityOfThreePoints(p4, p5, p6) << endl;
    return 0;
}