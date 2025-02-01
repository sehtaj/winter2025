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

int main() {
    int shift = 3;
    bool rightShift = true;
    string line;

    cout << "Enter shift value (0-25): ";
    cin >> shift;
    shift = shift % 26;
    
    string direction;
    cout << "Enter 'l' to shift left, 'r' to shift right" << endl;
    cin >> direction;
    if (direction == "l") {
        rightShift = false;
    }
    cout << "Enter 'e' to encrypt, 'd' to decrypt and then enter the text or enter 'q' to quit " << endl;
    cin.ignore();

    while (true) {
        getline(cin, line);
        if (line[0] == 'q') {  
            break;  
        }
        if (line[0] == 'e') {  
            cout << ProcessText(line, shift, true) << endl; 
        }
        if (line[0] == 'd') {  
            cout <<ProcessText(line, shift, false) << endl;
        }
    }
    return 0;
}