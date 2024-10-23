#include <iostream>
#include <fstream>
#include <hashmap.h>
#include <simpio.h>
#include <filesystem>
#include "exercise1_6.h"
using namespace std;

ofstream CURRENTFILE;
ifstream CURRENTFILEVIEWER;
string CURRENTFILEPATH;
int PROGRAMSTEP, CURRENTGENERALPROCEDURE, SELECTEDTOOL;
HashMap<int, string> ACTIONS = {{0, "(1) Add a new line"}, {1, "(2) Count locations"}, {2, "(3) Reverse coordinates"}};
HashMap<int, string> generalProcedures = {{0, "(1) Creates File"}, {1, "(2) Edits File"}};

void cliForGISOperations();
void generalProcedureSelector();
void generalProcedure();
void preViewer(bool withTools = false);
void selectTool();
void tooler();
void printsLine(string line, int lineLength);
void addNewLine();
void stepSelector();
void printsGeneralProcedures();
string returnsSingularVariable(string line, string variable = "latitude");
void createsFile();
bool parseAndValidInput(string &input, int &output, int minValue, int maxValue);
bool parseAndValidNumericalValue(string &input, double &output);
void openExistingFile(bool comesFromCreation = false);
int linesOfFile();

void cliForGISOperations() {
    PROGRAMSTEP = 0;
    while(true) {
        if (PROGRAMSTEP == -1) {
            cout << "Finished" << endl;
            break;
        }
        switch (PROGRAMSTEP) {
            case 0:
                generalProcedureSelector();
                [[fallthrough]];
            case 1:
                generalProcedure();
                [[fallthrough]];
            case 2:
                preViewer();
                [[fallthrough]];
            case 3:
                selectTool();
                [[fallthrough]];
            case 4:
                tooler();
                [[fallthrough]];
            default:
                break;
        }
        // stepSelector();
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
            CURRENTGENERALPROCEDURE = intGeneralProcedure - 1;
            break;
        }
        cout << "Such option is invalid, the valid options are: " << endl;
        printsGeneralProcedures();
    }
    PROGRAMSTEP = 1;
}

void generalProcedure() {
    switch(CURRENTGENERALPROCEDURE){
    case 0:
        createsFile();
        openExistingFile(true);
        break;
    case 1:
        openExistingFile();
        break;
    default: break;
    }
    PROGRAMSTEP = 2;
}

void preViewer(bool withTools) {
    string line;
    int lineCounter = 0, optionCounter = 0, lines = linesOfFile();

    switch (CURRENTGENERALPROCEDURE) {
    case 1:
        while (getline(CURRENTFILEVIEWER, line)) {
            int lineLength = line.length();
            if (CURRENTFILEVIEWER.eof() || CURRENTFILEVIEWER.fail()) break;
            if (lines - lineCounter > ACTIONS.size()) {
                printsLine(line, lineLength);
                cout << endl;
                lineCounter++;
            } else {
                printsLine(line, lineLength);
                if (!withTools)
                    cout << setw(20) << ACTIONS.get(optionCounter) << endl;
                optionCounter++;
                lineCounter++;
            }
        }
        break;
    case 0:
        cout << "EMPTY FILE" << endl;
        break;
    default:
        break;
    }
    PROGRAMSTEP = 3;
}

void selectTool () {
    string selectedTool;
    int intSelectedTool;

    cout << "What you want to do?: ";
    for (const std::string &option: ACTIONS.values()) cout << option << " ";
    getline(cin, selectedTool);
    while (true) {
        if (parseAndValidInput(selectedTool, intSelectedTool, 0, 2)) {
            SELECTEDTOOL = intSelectedTool - 1;
            break;
        }
        cout << "Input a valid option: ";
        getline(cin, selectedTool);
    }
    PROGRAMSTEP = 4;
}

void tooler() {
    switch (SELECTEDTOOL) {
    case 0:
        addNewLine();
        preViewer(true);
        break;
    case 1:

    default: break;
    }
}

void printsLine(string line, int lineLength) {
    char character;
    string separator;
    int latestIndex, index;
    index = 0;
    latestIndex = 0;

    while(true) {
        character = line.at(index);
        if (character == ' ' || index >= lineLength - 1) {
            cout << setw(15) << left << line.substr(latestIndex, index - latestIndex);
            latestIndex = index + 1;
            index += 2;
        }
        if (index >= lineLength - 1) break;
        index++;
    }

}

void addNewLine() {
    string place, longitude, latitude, newLine;
    double doubleLongitude, doubleLatitude;
    cout << "What's the place's name? ";
    getline(cin, place);
    while (true) {
        cout << "What's the longitude's? ";
        getline(cin, longitude);
        if(parseAndValidNumericalValue(longitude, doubleLongitude)) break;
    }
    while (true) {
        cout << "What's the latitude's? ";
        getline(cin, latitude);
        if(parseAndValidNumericalValue(latitude, doubleLatitude)) break;
    }
    newLine = place + " " + longitude + " " + latitude + "\n";
    if (CURRENTFILE.is_open()) {
        CURRENTFILE.clear();
        CURRENTFILE.seekp(0, ios::end);
        CURRENTFILE << newLine;
        CURRENTFILE.flush();
        cout << "New line added successfully." << endl;
        CURRENTFILEVIEWER.close();
        CURRENTFILEVIEWER.open(CURRENTFILEPATH);
    } else {
        cerr << "Error: The file is not open for writing." << endl;
    }
}


void stepSelector() {
    string selectedStep;
    int intSelectedStep;

    while (true) {
        cout << "Press (1) and enter to select again the general procedure or (0) to finish the program: ";
        getline(cin, selectedStep);
        if (parseAndValidInput(selectedStep, intSelectedStep, 0, 1)) {
            PROGRAMSTEP = intSelectedStep - 1;
            break;
        }
    }
}

void printsGeneralProcedures () {
    for (int i = 0; i < generalProcedures.size(); i++) {
        cout << generalProcedures.get(i) << endl;
    }
}

string  returnsSingularVariable(string line, string variable) {
    char character;
    string subLine;
    int lineLength = line.length();

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
    if (variable == "latitude") {
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

bool parseAndValidInput(string &input, int &output, int minValue, int maxValue) {
    istringstream stream(input);
    stream >> skipws >> output;
    return (!stream.fail() && (stream.eof() || isspace(stream.peek())) && (output >= minValue && output <= maxValue));
}

bool parseAndValidNumericalValue(string &input, double &output) {
    istringstream stream(input);
    stream >> skipws >> output;
    if (stream.fail()) return false;
    if (!stream.eof() && !isspace(stream.peek())) return false;
    return true;
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
    if (!comesFromCreation)
        CURRENTFILEPATH = promptUserForFilename("Give the .txt file's path:", "Give a valid .txt file's path");
    cout << "CURRENT FILE PATH: " << CURRENTFILEPATH << endl;

    if (CURRENTFILE.is_open())
        CURRENTFILE.close();
    if (CURRENTFILEVIEWER.is_open())
        CURRENTFILEVIEWER.close();

    // Open the file for reading and writing without truncating its contents
    CURRENTFILE.open(CURRENTFILEPATH, std::ios::in | std::ios::out);
    CURRENTFILEVIEWER.open(CURRENTFILEPATH);

    if (!CURRENTFILE.is_open() || !CURRENTFILEVIEWER.is_open()) {
        cerr << "Failed to open the file for reading and writing." << endl;
    }
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
