#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please provide a file name\n";
        return 1;
    }
    
    bool countLines = false, countWords = false, countChars = false;
    string filename = "";
    
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-l") {
            countLines = true;
        }
        else if (arg == "-w") {
             countWords = true;
        }
        else if (arg == "-c") {
             countChars = true;
        } else {
            filename = arg;
        }
    }
    ifstream file(filename);
    if (!file) {
        cout << "Error: Cannot open file " << filename << "\n";
        return 1;
    }

    int lines = 0, words = 0, chars = 0;
    string line, word;

    while (getline(file, line)) {
        lines++;
        chars += line.length();
        stringstream ss(line);
        while (ss >> word) {
            words++;
        }
    }
    if (!countLines && !countWords && !countChars) {
        countLines =true;
        countWords =true;
        countChars = true;
    }
    if (countLines) {
        cout << lines << " ";
    }
    if (countWords) {
        cout << words << " ";
    }
    if (countChars) {cout << chars << " ";
    }
    cout << filename << "\n";
    return 0;
}