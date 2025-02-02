#include <iostream>
#include <string>

using namespace std;

char shiftChar(char c, int shift, bool encrypt) {
    if (!isalpha(c)) {  
        return c;  
    }
    char base;
    if (c >= 'A' && c <= 'Z') {
        base = 'A';  
    } else {
        base = 'a';
    }
    if (encrypt) {
        int newPos = c - base + shift;  
        if (newPos >= 26) {  
            newPos = newPos - 26; 
        }
        return base + newPos;
    }else{
        int newPos = c - base - shift; 
        if (newPos < 0) {  
            newPos = newPos + 26; 
        }
        return base + newPos;
    }
}
string ProcessText(string text, int shift, bool encrypt) {
    string result = ""; 
    for (int i = 1; i < text.size(); i++) { 
        result += shiftChar(text[i], shift, encrypt);
    }
    return result;
}

int main(int argc, char *argv[]) {
    int shift = 3;  
    bool encrypt = true;  
    string direction = "right"; 
    if (argc > 1) {
        shift = atoi(argv[1]); 
        if (shift < 0 || shift > 25) {
            cout << "Shift value must be between 0 and 25" << endl;
            return 1;
        }
    }
    if (argc > 2) {
        direction = argv[2];  
        if (direction == "left") {
            encrypt = false;  
        } else if (direction != "right") {
            cout << "Direction must be 'left' or 'right'" << endl;
            return 1;
        }
    }
    string line;
    while (true) {
        getline(cin, line);  
        if (line.empty()) {  
            continue;  
        }
        if (line[0] == 'q') {  
            break; 
        }
        if (line[0] == 'e') {  
            cout << ProcessText(line, shift, true) << endl;  
        }
        if (line[0] == 'd') {  
            cout << ProcessText(line, shift, false) << endl;  
        }
    }
    return 0;
}


