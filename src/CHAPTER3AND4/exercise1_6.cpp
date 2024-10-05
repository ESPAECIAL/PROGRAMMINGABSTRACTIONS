#include <iostream>
#include <fstream>
#include <hashmap.h>
#include <simpio.h>
#include <filesystem>
#include "exercise1_6.h"
using namespace std;

ifstream CURRENTFILE;
string CURRENTFILEPATH;
int programStep, currentGeneralProcedure;
HashMap<int, string> ACTIONS = {{0, "(1) Add a new line"}, {1, "(2) Count locations"}, {2, "(3) Reverse coordinates"}};
HashMap<int, string> generalProcedures = {{0, "(1) Creates File"}, {1, "(2) Edits File"}};

void cliForGISOperations();
void generalProcedureSelector();
void generalProcedure();
void preViewer();
void printsLine(string line, int lineLength);
void stepSelector();
void printsGeneralProcedures();
bool validsGeneralProcedureInput(string generalProcedure);
string returnsSingularVariable(string line, string variable = "latitude");
void createsFile();
bool parseAndValidInput(string &input, int &output, int minValue, int maxValue);
void openExistingFile(bool comesFromCreation = false);
int linesOfFile();

void cliForGISOperations() {
    programStep = 0;
    while(true) {
        if (programStep == -1) {
            cout << "Finished" << endl;
            break;
        }
        switch (programStep) {
        case 0:
            generalProcedureSelector();
        case 1:
            generalProcedure();
        default:
            break;
        }
        preViewer();
        stepSelector();
    }
}

void generalProcedureSelector() {
    int intGeneralProcedure;
    string generalProcedure;
    printsGeneralProcedures();
    cout << "What do you want to do?: ";
    while (true) {
        getline(cin, generalProcedure);
        if (parseAndValidInput(generalProcedure, intGeneralProcedure, 1, generalProcedures.size())) {
            currentGeneralProcedure = intGeneralProcedure - 1;
            break;
        }
        cout << "Such option is invalid, the valid options are: " << endl;
        printsGeneralProcedures();
    }
    programStep = 1;
}

void generalProcedure() {
    switch(currentGeneralProcedure){
    case 0:
        createsFile();
        openExistingFile(true);
        break;
    case 1:
        openExistingFile();
        break;
    default: break;
    }
}

void preViewer () {
    char character;
    string line, subLine;
    int lineCounter, lineLength, optionCounter, lines;

    lineCounter = 0;
    optionCounter = 0;
    lines = linesOfFile();

    switch (currentGeneralProcedure) {
    case 1:
        while (true) {
            int latestIndex, index;
            index = 0;
            latestIndex = 0;
            getline(CURRENTFILE, line);
            lineLength = line.length();
            if (CURRENTFILE.eof() || CURRENTFILE.fail()) break;
            if (lines - lineCounter > ACTIONS.size()) {
                while(true) {
                    character = line.at(index);
                    if (character == ' ' || index >= lineLength - 1) {
                        cout << line.substr(latestIndex, index - latestIndex) << ", ";
                        latestIndex = index + 1;
                        index += 2;
                    }
                    if (index >= lineLength - 1) break;
                    index++;
                }
                cout << endl;
                lineCounter = lineCounter + 1;
            } else {
                latestIndex = 0;
                while(true) {
                    character = line.at(index);
                    if (character == ' ' || index >= lineLength - 1) {
                        cout << line.substr(latestIndex, index - latestIndex) << ", ";
                        latestIndex = index + 1;
                        index += 2;
                    }
                    if (index >= lineLength - 1) break;
                    index++;
                }
                cout << ACTIONS.get(optionCounter) << endl;
                optionCounter++;
                lineCounter = lineCounter + 1;
            }
        }
    default: break;
    }
}

void printsLine(string line, int lineLength) {
    char character;
    int latestIndex, index;
    index = 0;
    latestIndex = 0;
    while(true) {
        character = line.at(index);
        if (character == ' ' || index >= lineLength - 1) {
            cout << line.substr(latestIndex, index - latestIndex) << ", ";
            latestIndex = index + 1;
            index += 2;
        }
        if (index >= lineLength - 1) break;
        index++;
    }
}

void stepSelector() {
    string selectedStep;
    int intSelectedStep;

    while (true) {
        cout << "Press (1) and enter to select again the general procedure or (0) to finish the program: ";
        getline(cin, selectedStep);
        if (parseAndValidInput(selectedStep, intSelectedStep, 0, 1)) {
            programStep = intSelectedStep - 1;
            break;
        }
    }
}

void printsGeneralProcedures () {
    for (int i = 0; i < generalProcedures.size(); i++) {
        cout << generalProcedures.get(i) << endl;
    }
}

bool validsGeneralProcedureInput(string generalProcedure) {
    istringstream stream(generalProcedure);
    int intGeneralProcedure;
    stream >> skipws >> intGeneralProcedure;
    if (!stream.fail() && (stream.eof() || isspace(stream.peek())) && generalProcedures.containsKey(intGeneralProcedure - 1)) {
        currentGeneralProcedure = intGeneralProcedure;
        return true;
    }
    return false;
}

string returnsSingularVariable(string line, string variable) {
    char character;
    string subLine;
    int lineLength = line.length();

    if (variable == "place") {
        for (int i = 0; i < lineLength; i++) {
            character = line.at(i);
            if (character == ' ') return line.substr(0, i);
        }
        return "";
    }
    if (variable == "longitude") {
        int latestIndex;
        bool placePassed = false;
        for (int i = 0; i < lineLength; i++) {
            character = line.at(i);
            if (!placePassed && character == ' ') {
                latestIndex = i;
                cout << i << endl;
                cout << line.at(i - 1) << endl;
                placePassed = !placePassed;
                continue;
            }
            if (placePassed && character == ' ') return line.substr(latestIndex, i);
        }
        return "";
    }
    for (int i = lineLength - 1; i > 1; i--) {
        character = line.at(i);
        if (character == ' ') return line.substr(i+1, lineLength - i - 1);
    }
    return "";
}

bool parseAndValidInput(string &input, int &output, int minValue, int maxValue) {
    istringstream stream(input);
    stream >> skipws >> output;
    return (!stream.fail() && (stream.eof() || isspace(stream.peek())) && (output >= minValue && output <= maxValue));
}

void createsFile() {
    string pathFolder, fileName, pathFile;
    while (true) {
        while (true) {
            cout << "Write the path to specify the folder where will be saved the file: ";
            cin >> pathFolder;
            if(std::filesystem::is_directory(pathFolder)) break;
        }
        while (true) {
            cout << "Write the name of the file (not including the extension): ";
            cin >> fileName;
            if(fileName.find('.') == std::string::npos) break;
        }
        CURRENTFILEPATH = pathFolder + "/" + fileName + ".txt";
        ofstream file(CURRENTFILEPATH);
        if (file.is_open()) {
            file.close();
            break;
        }
    }
}

void openExistingFile(bool comesFromCreation) {
    if (!comesFromCreation) CURRENTFILEPATH = promptUserForFilename("Give the .txt file's path:", "Give a valid .txt file's path");
    CURRENTFILE.open(CURRENTFILEPATH);
}

int linesOfFile () {
    string line;
    int lines = 0;
    ifstream tempfile;
    tempfile.open(CURRENTFILEPATH);
    while(getline(tempfile, line)) lines++;
    tempfile.close();
    return lines;
}
