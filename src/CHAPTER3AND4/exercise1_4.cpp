#include <hashmap.h>
#include <fstream>
#include <simpio.h>
#include <cctype>
using namespace std;

void extractsParagraph(string &line) {
    int startingIndex, lineLength;
    istringstream stream(line);
    startingIndex = 0;
    lineLength = line.length();
    for (int i = 0; i < lineLength; i++) {
        if (line.at(i) == '\"') {
            startingIndex = i;
            break;
        }
    }
    line = line.substr(startingIndex + 1, lineLength - 2 - startingIndex);
}

void savesWordInMap(HashMap<string, int> &countedWords, string word) {
    if (countedWords.containsKey(word)) {
        countedWords.put(word, countedWords[word] + 1);
        return;
    }
    countedWords.put(word, 1);
}

void countsWordFrequencyInLine(HashMap<string, int> &countedWords, string &line) {
    int latestIndex, lineLength;
    char character;
    string word;
    latestIndex = 0;
    lineLength = line.length();
    for (int i = 0; i < lineLength - 1; i++) {
        character = line.at(i);
        if (character == ' ' || character == ',' || character == '.') {
            bool isEmptyChar = line.substr(latestIndex, i - latestIndex).length() == 0;
            if (isEmptyChar) {
                latestIndex = i + 1;
                continue;
            }
            word = line.substr(latestIndex, i - latestIndex);
            savesWordInMap(countedWords, word);
            latestIndex = i + 1;
        }
    }
    word = line.substr(latestIndex + 1, lineLength - 2);
    savesWordInMap(countedWords, word);
}

void createsSortedArrayWithWordFrequencies(HashMap<string, int> &countedWords, Vector<string> &keys, Vector<int> &values) {
    keys = countedWords.keys();
    values = countedWords.values();
    int keysSize = keys.size();
    // Bubble sorting based on the values in the pairs
    for (int i = 0; i < keysSize - 1; ++i) {
        for (int j = 0; j < keysSize - 1 - i; ++j) {
            if (values[j] < values[j + 1]) {
                int tempValue = values[j];
                string tempKey = keys[j];
                values[j] = values[j + 1];
                values[j + 1] = tempValue;
                keys[j] = keys[j + 1];
                keys[j + 1] = tempKey;
            }
        }
    }
}

string readsFile() {
    return promptUserForFilename("Give the file's path:", "Give a valid path:");
}

void countsWordFrequency() {
    HashMap<string, int> countedWords;
    string line, filePath;
    Vector<string> keys;
    Vector<int> values;
    ifstream infile;

    filePath = readsFile();
    infile.open(filePath);

    while (true) {
        getline(infile, line);
        if (infile.fail()) break;
        extractsParagraph(line);
        countsWordFrequencyInLine(countedWords, line);
    }

    infile.close();
    createsSortedArrayWithWordFrequencies(countedWords, keys, values);
    for (int i = 0; i < keys.size(); i++) cout << keys[i] << ": " << values[i] << endl;

}


