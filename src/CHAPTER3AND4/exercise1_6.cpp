#include <iostream>
#include <fstream>
#include <hashmap.h>
// #include <filesystem>
#include "exercise1_6.h"
using namespace std;

ifstream currentFile;
int programStep, currentGeneralProcedure;
HashMap<int, string> ACTIONS = {{0, "(1) Add a new line"}, {1, "(2) Count locations"}, {2, "(3) Reverse coordinates"}};
HashMap<int, string> generalProcedures = {{0, "(1) Creates File"}, {1, "(2) Edits File"}};

void cliForGISOperations();
void generalProcedureSelector();
void preViewer();
void stepSelector();
void printsGeneralProcedures();
bool validsGeneralProcedureInput(string generalProcedure);
bool parseAndValidInput(string &input, int &output, int minValue, int maxValue);

void cliForGISOperations() {
    programStep = 0;
    while(true) {
        if (programStep == -1) {
            cout << "Finished" << endl;
            break;
        }
        cout << "PROGRAM STEP: " << programStep << endl;
        switch (programStep) {
        case 0:
            generalProcedureSelector();
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
        if (parseAndValidInput(generalProcedure, intGeneralProcedure, 0, generalProcedures.size() + 1)) {
            currentGeneralProcedure = intGeneralProcedure;
            break;
        }
        cout << "Such option is invalid, the valid options are: " << endl;
        printsGeneralProcedures();
    }
    programStep = 1;
}

void preViewer () {
    switch (currentGeneralProcedure) {
    case 1:
    default: break;
    }

    cout << "Hello" << endl;
}

void stepSelector() {
    string selectedStep;
    int intSelectedStep;

    while (true) {
        cout << "Press (1) and enter to select again the general procedure or (0) to finish the program: ";
        getline(cin, selectedStep);
        if (parseAndValidInput(selectedStep, intSelectedStep, -1, 2)) {
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

bool parseAndValidInput(string &input, int &output, int minValue, int maxValue) {
    istringstream stream(input);
    stream >> skipws >> output;
    return (!stream.fail() && (stream.eof() || isspace(stream.peek())) && (output > minValue && output < maxValue));
}










// void createsFile(string &pathFolder, string &fileName, string &pathFile) {
//     while (true) {
//         while (true) {
//             cout << "Write the path to specify the folder where will be saved the file: ";
//             cin >> pathFolder;
//             if(std::filesystem::is_directory(pathFolder)) break;
//         }
//         while (true) {
//             cout << "Write the name of the file (not including the extension): ";
//             cin >> fileName;
//             if(fileName.find('.') == std::string::npos) break;
//         }
//         pathFile = pathFolder + "/" + fileName + ".txt";
//         ofstream file(pathFile);
//         if (file.is_open()) {
//             file.close();
//             break;
//         }
//     }
// }


// void withCreatedFile() {
//     string pathFolder;
//     string fileName;
//     string pathFile;
//     createsFile(pathFolder, fileName, pathFile);
//     currentFile.open(pathFile);
//     whatToDoWithOpenFile();
// }

// void performsgeneralProcedureSelector() {
//     switch (generalOperation) {
//     case 0:
//         withCreatedFile();
//         break;
//     default: cout << ":)" << endl;
//     }
// }
