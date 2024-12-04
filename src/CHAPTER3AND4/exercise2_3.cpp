#include "exercise2_3.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void showsHowADescriptionIsFormatted() {
    string line;
    char character;

    cout << "Write a description to parse: ";
    getline(cin, line);
    istringstream withWhiteSkips(line);
    cout << "Default for skipping white spaces: ";
    while (withWhiteSkips >> character) cout << character;
    cout << endl;
    istringstream withoutWhiteSkips(line);
    withoutWhiteSkips >> noskipws;
    cout << "Not skipping white spaces: ";
    while (withoutWhiteSkips >> character) cout << character;
}
