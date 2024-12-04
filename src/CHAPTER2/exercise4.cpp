#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x;
    double y;
};

struct PolygonWithFiveVertices {
    Point point1;
    Point point2;
    Point point3;
    Point point4;
    Point point5;
    std::vector<Point> getVerticesInOrder() const {
        return {point1, point2, point3, point4, point5};
    }
};

void printsCentroidOfPolygonsWithFiveVertices(PolygonWithFiveVertices &polygon);
double calculatesCentroidXOfPolygonsWithFiveVertices(PolygonWithFiveVertices &polygon);
double calculatesCentroidYOfPolygonsWithFiveVertices(PolygonWithFiveVertices &polygon);
double summation(PolygonWithFiveVertices &polygon, string axis);
double calculatesFactors(Point current, Point next, string axis);
double calculatesAreaOfPolygonWithFiveVertices(PolygonWithFiveVertices polygon);


void printsCentroidOfPolygonsWithFiveVertices(PolygonWithFiveVertices &polygon) {
    double cx, cy;
    cx = calculatesCentroidXOfPolygonsWithFiveVertices(polygon);
    cy = calculatesCentroidYOfPolygonsWithFiveVertices(polygon);
    cout << "The centroid of the polygon is (" + to_string(cx) + ", " + to_string(cy) + ")" << endl;
}

double calculatesCentroidXOfPolygonsWithFiveVertices(PolygonWithFiveVertices &polygon) {
    return (1.0 / (6.0 * calculatesAreaOfPolygonWithFiveVertices(polygon))) * summation(polygon, "x");
};

double calculatesCentroidYOfPolygonsWithFiveVertices(PolygonWithFiveVertices &polygon) {
    return (1.0 / (6.0 * calculatesAreaOfPolygonWithFiveVertices(polygon))) * summation(polygon, "y");
};

double summation(PolygonWithFiveVertices &polygon, string axis) {
    std::vector<Point> vertices = polygon.getVerticesInOrder();
    int vertexCounter = 0;
    double factor1, factor2;
    double summation = 0;
    for (const auto& vertex : vertices) {
        if (vertexCounter == 4) break;
        summation +=  calculatesFactors(vertex, vertices.at(vertexCounter + 1), axis);
        vertexCounter++;
    }
    return summation;
}

double calculatesFactors(Point current, Point next, string axis) {
    double factor1, factor2;
    factor1 = axis == "x" ? current.x * next.x : current.y * next.y;
    factor2 = current.x * next.y - next.x * current.y;
    return factor1 * factor2;
}

double calculatesAreaOfPolygonWithFiveVertices(PolygonWithFiveVertices polygon) {
    polygon.getVerticesInOrder();
    std::vector<Point> vertices = polygon.getVerticesInOrder();
    double summation = 0;
    double xi, yi, xi1, yi1;
    for (int i = 0; i < 4; i++) {
        xi = vertices.at(i).x;
        xi1 = vertices.at(1+i).x;
        yi = vertices.at(i).y;
        yi1 = vertices.at(i+1).y;
        summation += (xi*yi1 - yi*xi1);
    }
    return (1.0 / 2.0) * (summation);
}

int main() {
    PolygonWithFiveVertices polygon1 = {{0, 0}, {4, 0}, {4, 3}, {2, 5}, {0, 3}};
    printsCentroidOfPolygonsWithFiveVertices(polygon1);
    PolygonWithFiveVertices polygon2 = {{1, 2}, {6, 2}, {5, 5}, {3, 6}, {0, 4}};
    printsCentroidOfPolygonsWithFiveVertices(polygon2);
    return 0;
}