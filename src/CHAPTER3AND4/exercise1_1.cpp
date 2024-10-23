#include <cctype>
#include <iostream>
#include <simpio.h>

using namespace std;

void getUpperCasedString() {
    string line = getLine("Write the name of a city: ");
    for (char& character: line){
        character = toupper(character);
    }
    cout << line << endl;
}
