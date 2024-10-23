#include <fstream>
#include <string>
#include <strlib.h>
#include <simpio.h>
using namespace std;

void extractsCitiesStartingWithVowel(string input, string output) {
    ifstream infile;
    ofstream outfile;
    infile.open(input);
    outfile.open(output);
    string line, lowerCasedLine;
    while(true) {
        getline(infile, line);
        if(infile.fail()) break;
        lowerCasedLine = toLowerCase(line);
        bool isA = startsWith(lowerCasedLine, "a");
        bool isE = startsWith(lowerCasedLine, "e");
        bool isI = startsWith(lowerCasedLine, "i");
        bool isO = startsWith(lowerCasedLine, "o");
        bool isU = startsWith(lowerCasedLine, "u");
        if (isA || isE || isI || isO || isU) outfile << line + '\n';
    }
    infile.close();
    outfile.close();
}

void testsExtractionOfCitiesStartingWithVowel() {
    string inFileName = promptUserForFilename("Give a file", "Give a valid file");
    string outFileName = promptUserForFilename("Give a file", "Give a valid file");
    extractsCitiesStartingWithVowel(inFileName, outFileName);
}
