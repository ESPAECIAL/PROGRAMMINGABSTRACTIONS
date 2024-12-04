#include <iostream>
#include <cmath>
#include "topooperations.h"

using namespace std;

Direction getDirection(GeoPoint start, GeoPoint end) {
    if (start.x == end.x && start.y < end.y) return NORTH;
    if (start.x < end.x && start.y < end.y) return NORTHEAST;
    if (start.x < end.x && start.y == end.y) return EAST;
    if (start.x < end.x && start.y > end.y) return SOUTHEAST;
    if (start.x == end.x && start.y > end.y) return SOUTH;
    if (start.x > end.x && start.y > end.y) return SOUTHWEST;
    if (start.x > end.x && start.y == end.y) return WEST;
    if (start.x > end.x && start.y < end.y) return NORTHWEST;
    if (start.x == end.x && start.y == end.y) return NONE;
    return INVALID;
}

GeoPoint midPoint(GeoPoint a, GeoPoint b) {
    GeoPoint mPoint;
    mPoint.x = (a.x + b.x) / 2.0;
    mPoint.y = (a.y + b.y) / 2.0;
    return mPoint;
}

void testGetDirection() {
    GeoPoint start, end;

    std::cout << "GET DIRECTION TESTS.\n";

    // Test case 1: NORTH
    start = {0.0, 0.0};
    end = {0.0, 1.0};
    if (getDirection(start, end) == NORTH) {
        std::cout << "Test case 1 (NORTH) passed.\n";
    } else {
        std::cout << "Test case 1 (NORTH) failed.\n";
    }

    // Test case 2: NORTHEAST
    start = {0.0, 0.0};
    end = {1.0, 1.0};
    if (getDirection(start, end) == NORTHEAST) {
        std::cout << "Test case 2 (NORTHEAST) passed.\n";
    } else {
        std::cout << "Test case 2 (NORTHEAST) failed.\n";
    }

    // Test case 3: EAST
    start = {0.0, 0.0};
    end = {1.0, 0.0};
    if (getDirection(start, end) == EAST) {
        std::cout << "Test case 3 (EAST) passed.\n";
    } else {
        std::cout << "Test case 3 (EAST) failed.\n";
    }

    // Test case 4: SOUTHEAST
    start = {0.0, 0.0};
    end = {1.0, -1.0};
    if (getDirection(start, end) == SOUTHEAST) {
        std::cout << "Test case 4 (SOUTHEAST) passed.\n";
    } else {
        std::cout << "Test case 4 (SOUTHEAST) failed.\n";
    }

    // Test case 5: SOUTH
    start = {0.0, 0.0};
    end = {0.0, -1.0};
    if (getDirection(start, end) == SOUTH) {
        std::cout << "Test case 5 (SOUTH) passed.\n";
    } else {
        std::cout << "Test case 5 (SOUTH) failed.\n";
    }

    // Test case 6: SOUTHWEST
    start = {0.0, 0.0};
    end = {-1.0, -1.0};
    if (getDirection(start, end) == SOUTHWEST) {
        std::cout << "Test case 6 (SOUTHWEST) passed.\n";
    } else {
        std::cout << "Test case 6 (SOUTHWEST) failed.\n";
    }

    // Test case 7: WEST
    start = {0.0, 0.0};
    end = {-1.0, 0.0};
    if (getDirection(start, end) == WEST) {
        std::cout << "Test case 7 (WEST) passed.\n";
    } else {
        std::cout << "Test case 7 (WEST) failed.\n";
    }

    // Test case 8: NORTHWEST
    start = {0.0, 0.0};
    end = {-1.0, 1.0};
    if (getDirection(start, end) == NORTHWEST) {
        std::cout << "Test case 8 (NORTHWEST) passed.\n";
    } else {
        std::cout << "Test case 8 (NORTHWEST) failed.\n";
    }

    // Test case 9: NONE
    start = {0.0, 0.0};
    end = {0.0, 0.0};
    if (getDirection(start, end) == NONE) {
        std::cout << "Test case 9 (NONE) passed.\n";
    } else {
        std::cout << "Test case 9 (NONE) failed.\n";
    }
}

void testMidPoint() {
    GeoPoint a, b, expected, result;

    std::cout << "\nMID POINT TESTS.\n";

    // Test case 1
    a = {0.0, 0.0};
    b = {2.0, 2.0};
    expected = {1.0, 1.0};
    result = midPoint(a, b);
    if (result.x == expected.x && result.y == expected.y) {
        std::cout << "Test case 1 passed.\n";
    } else {
        std::cout << "Test case 1 failed.\n";
    }

    // Test case 2
    a = {-1.0, -1.0};
    b = {1.0, 1.0};
    expected = {0.0, 0.0};
    result = midPoint(a, b);
    if (result.x == expected.x && result.y == expected.y) {
        std::cout << "Test case 2 passed.\n";
    } else {
        std::cout << "Test case 2 failed.\n";
    }

    // Test case 3
    a = {0.0, 0.0};
    b = {0.0, 2.0};
    expected = {0.0, 1.0};
    result = midPoint(a, b);
    if (result.x == expected.x && result.y == expected.y) {
        std::cout << "Test case 3 passed.\n";
    } else {
        std::cout << "Test case 3 failed.\n";
    }
}

int main () {
    testGetDirection();
    testMidPoint();
    return 0;
}