#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct Line {
    double a;
    double b;
    double c;
};

bool areTheLinesParallel(Line &line1, Line &line2);
string printsTheIntersectionOfTwoRectLines(Line &line1, Line &line2);
double findsTheXIntersection(Line &line1, Line &line2);
double findsTheYIntersection(Line &line1, Line &line2, double &x);

int main () {
    // Example 2: Intersected lines
    Line line1 = {1, 2, 3};
    Line line2 = {4, 2, 3};
    if (areTheLinesParallel(line1, line2)) {
        cout << "The lines are parallel" << endl;
        return 0;
    }
    cout << printsTheIntersectionOfTwoRectLines(line1, line2) << endl;
    // Example 2: Parallel lines
    Line line3 = {2, 4, 6};
    Line line4 = {2, 4, 10};
    if (areTheLinesParallel(line3, line4)) {
        cout << "The lines are parallel" << endl;
        return 0;
    }
    cout << printsTheIntersectionOfTwoRectLines(line3, line4) << endl;
    return 0;
}

bool areTheLinesParallel(Line &line1, Line &line2) {
    return line1.b / line1.a == line2.b / line2.a;
};

string printsTheIntersectionOfTwoRectLines(Line &line1, Line &line2) {
    double x, y;
    x = findsTheXIntersection(line1, line2);
    y = findsTheYIntersection(line1, line2, x);
    return "The intersection between the lines is: (" + to_string(x) + ", " + to_string(y) +  ")";
}

double findsTheXIntersection(Line &line1, Line &line2) {
    double factor1, factor2;
    factor1 = ((line1.c / line1.b) - (line2.c / line1.b));
    factor2 = ((line1.b * line2.b) * ((line1.a * line2.b) * (line2.a * line1.b)));
    return factor1 * factor2;
}

double findsTheYIntersection(Line &line1, Line &line2, double &x) {
    double y_line1, y_line2;
    y_line1 = (line1.c / line1.b) - line1.a * x;
    y_line2 = (line2.c / line2.b) - line2.a * x;
    if (y_line1 == y_line2) return y_line1;
    throw std::runtime_error("The lines do not intersect at the given x-coordinate.");
}