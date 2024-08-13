#ifndef _geoshapes_h
#define _geoshapes_h

enum ShapeType {
    CIRCLE, LINE, POINT
};

const double PI = 3.14159265358979323846;

struct GeoPoint {
    double longitude;
    double latitude;
};

double calculateArea(ShapeType);
double calculateDistance(GeoPoint a, GeoPoint b);
double calculateCircleArea();

#endif