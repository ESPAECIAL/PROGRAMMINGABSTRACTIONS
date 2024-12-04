#include <fstream>
#include <string>
#include <strlib.h>
#include <simpio.h>
#include "exercise1_3.h"
using namespace std;

void splitsCsvIntoThreeColumns(string pathInput, string pathLatitudes, string pathLongitudes, string pathPlaces) {
    ifstream input;
    ofstream latitudes;
    ofstream longitudes;
    ofstream places;
    string line, subLine;
    int column, latestIndex;
    input.open(pathInput);
    latitudes.open(pathLatitudes);
    longitudes.open(pathLongitudes);
    places.open(pathPlaces);
    while (true) {
        getline(input, line);
        if (input.fail()) break;
        column = 0;
        latestIndex = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line.at(i) == ',') {
                subLine = line.substr(latestIndex, i - latestIndex);
                switch(column) {
                    case 0:
                        latitudes << subLine + "\n";
                        break;
                    case 1: longitudes << subLine + "\n";
                        break;
                }
                column++;
            }
        }
        places << line.substr(latestIndex, line.length() - 1);
    }
    latitudes.close();
    longitudes.close();
    places.close();
}

void testsExtractionOfThreeColumnsFromCSV() {
    string pathInput = promptUserForFilename("Give a csv file with three variables", "Give a valid file");
    string pathLatitudes = promptUserForFilename("Give a csv file for latitudes", "Give a valid file");
    string pathLongitudes = promptUserForFilename("Give a csv file for longitudes", "Give a valid file");
    string pathPlaces = promptUserForFilename("Give a csv file for places", "Give a valid file");
    splitsCsvIntoThreeColumns(pathInput, pathLatitudes, pathLongitudes, pathPlaces);
}
