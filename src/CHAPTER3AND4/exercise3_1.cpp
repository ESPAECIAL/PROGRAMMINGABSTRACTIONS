#include "exercise3_1.h"
#include <fstream>
#include <sstream>
#include <simpio.h>

using namespace std;

void printsCoordinates(string line);
bool isDouble(string str);

void coordinatesChecker() {
    string line;
    string pathfile = promptUserForFilename("Enter the file path (including the file name and extension):", "Try again:");
    ifstream stream(pathfile);
    bool isHeader = true;
    while(getline(stream, line)) {
        if (isHeader) {
            isHeader = false;
            continue;
        }
        if (stream.fail()) break;
        if (stream.bad()) stream.clear(); // is the same of: if (!stream.good())
        printsCoordinates(line);
        cout << endl;
    }
    if (!stream.eof()) cout << "The line failed without reaching the end of the file";
}

void printsCoordinates(string line) {
    string subline;
    int commas = 0;
    int pos = 0;
    while (true) {
        int newPos = line.find(',');
        if (newPos < 0 || commas > 2) break;
        subline = line.substr(pos, newPos);
        if (!isDouble(subline)) {
            cout << "Invalid row (" << subline << ")";
            break;
        }
        cout << subline << " ";
        line = line.substr(newPos + 1, line.length() - newPos);
        commas++;
    }
}

bool isDouble(const string str) {
    istringstream iss(str);
    double d;
    return (iss >> d) && iss.eof();
}
