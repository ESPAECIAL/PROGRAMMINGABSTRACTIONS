#include <iostream>
#include <hashmap.h>
#include <simpio.h>
#include <iomanip>
#include "exercise2_1.h"
using namespace std;

void fromIntegerToOctAndHex() {
    int number;
    number = getInteger("Input an integer to be transformed to octal and hexadecimal", "ERROR. Try again!");
    cout << setw(10) << "Integer" << setw(10) << "Octal" << setw(15) << "Hexadecimal" << endl;
    cout << setw(10) << number << setw(10) << oct << number << setw(15) << hex << number;
}
