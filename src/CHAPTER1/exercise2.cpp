#include <iostream>
#include <cmath>
using namespace std;

enum A {
    ax = 0,
    ay = 1,
    az = 2,
};

enum B {
    bx = 1,
    by = -1,
    bz = -3,
};

struct MID {
    double mx;
    double my;
    double mz;
};

double calculateMidX() {
    double ax = static_cast<double>(A::ax);
    double bx = static_cast<double>(B::bx);
    if (ax > bx)
        return bx + ((ax - bx) / 2.0);
    return ax + ((bx - ax) / 2.0);
}

double calculateMidY() {
    double ay = static_cast<double>(A::ay);
    double by = static_cast<double>(B::by);
    if (ay > by)
        return by + ((ay - by) / 2.0);
    return ay + ((by - ay) / 2.0);
}

double calculateMidZ() {
    double az = static_cast<double>(A::az);
    double bz = static_cast<double>(B::bz);
    if (az > bz)
        return bz + ((az - bz) / 2.0);
    return az + ((bz - az) / 2.0);
}

MID calculatesMidPointOfTwoPoints() {
    MID mid;
    mid.mx = calculateMidX();
    mid.my = calculateMidY();
    mid.mz = calculateMidZ();
    return mid;
}

std::string printsMidPointOfTwoPoints() {
    MID mid = calculatesMidPointOfTwoPoints();
    string midPointMessage = "The midpoint between the points A (" + to_string(A::ax) + ", " + to_string(A::ay) +", " + to_string(A::az) + ")";
    midPointMessage += " and B (" + to_string(B::bx) + ", " + to_string(B::by) + ", " + to_string(B::bz) + ")";
    midPointMessage += " is: (" + to_string(mid.mx) + ", " + to_string(mid.my) + ", " + to_string(mid.mz) + ")";
    return midPointMessage;
}

int main() {
    cout << printsMidPointOfTwoPoints() << endl;
}