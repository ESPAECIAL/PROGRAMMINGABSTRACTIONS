#ifndef _topooperations_h
#define _topooperations_h

enum Direction {
    NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST, NONE, INVALID
};

struct GeoPoint {
    double x;
    double y;
};


Direction getDirection(GeoPoint start, GeoPoint end);
GeoPoint midPoint(GeoPoint a, GeoPoint b);

#endif