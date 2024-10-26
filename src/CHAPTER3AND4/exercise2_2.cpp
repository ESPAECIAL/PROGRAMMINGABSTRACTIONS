#include "exercise2_2.h"
#include <iomanip>
#include <simpio.h>

using namespace std;

void floatingPointToScientific () {
    double floatingNumber = getDouble("Introduce a floating point number", "ERROR. Do it again!");
    cout << scientific << endl;
    cout << setprecision(6) << floatingNumber;
}
