#include <fstream>
#include <iomanip>
#include <iostream>
#include <simpio.h>
#include <cmath>
using namespace std;

string returnsSingularCoords(string &line, string dimension = "longitude") {
    char character;
    string subLine;
    int lineLength = line.length();

    if (dimension == "latitude") {
        for (int i = lineLength - 1; i > 1; i--) {
            character = line.at(i);
            if (character == ' ') return line.substr(i+1, lineLength - i - 1);
        }
        return "";
    }
    for (int i = 0; i < lineLength; i++) {
        character = line.at(i);
        if (character == ' ') return line.substr(0, i);
    }
    return "";
}

int givesFormattingNumber(double coordinate) {
    int intCoordinate = int(coordinate);
    if (intCoordinate < 0) intCoordinate = -intCoordinate;
    int coordinateLengthOfIntegerPart = log10(intCoordinate) + 1;
    return 6 + coordinateLengthOfIntegerPart;
}

void printsFormattedCoords(string longitude, string latitude) {
    istringstream streamLongitude(longitude);
    istringstream streamLatitude(latitude);
    double doubleLongitude, doubleLatitude;
    double formattingLongitudeNumber, formattingLatitudeNumber;
    streamLongitude >> doubleLongitude;
    streamLatitude >> doubleLatitude;
    formattingLongitudeNumber = givesFormattingNumber(doubleLongitude);
    formattingLatitudeNumber = givesFormattingNumber(doubleLatitude);
    cout << setw(11) << setprecision(formattingLongitudeNumber) << doubleLongitude << " | ";
    cout << setw(11) << setprecision(formattingLatitudeNumber) << doubleLatitude << endl;
}

void showsTextAs2DCoords() {
    ifstream input;
    string line, subLine, longitude, latitude, pathFile;
    pathFile = promptUserForFilename("Give the path of a .txt file: ", "Give a valid path for the .txt file: ");
    input.open(pathFile);
    cout << "  longitude |    latitude" << endl;
    cout << "  -----------------------" << endl;
    while (true) {
        getline(input, line);
        if (input.fail()) break;
        longitude = returnsSingularCoords(line);
        latitude = returnsSingularCoords(line, "latitude");
        printsFormattedCoords(longitude, latitude);
    }
}
