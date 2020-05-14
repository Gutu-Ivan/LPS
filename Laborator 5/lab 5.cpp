#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void writeTextFile(const string& myString, string& file) {
    ofstream writeMyFile(file); //Create file and open to write
    writeMyFile << myString << "\n"; //Write file
    writeMyFile.close(); //Close file
}

string readTextFile(string& file) {
    string line;
    string text = "";
    ifstream readFile(file); // Open file to read

    while (getline(readFile, line)) {
        text += line + "\n";
    }
    readFile.close();
    return text;
}

int findLength(const string& phrase) {
    int maxLength = 0;
    string buffer;
    istringstream stream(phrase);
    stream >> buffer;
    while (stream && !buffer.empty()) {
        if (buffer.length() > maxLength) {
            maxLength = buffer.length();
        }
        buffer = "";
        stream >> buffer;
    }
    return maxLength;
}

string getLongestWord(const string& phrase) {
    int maxLength = findLength(phrase);
    string buffer;
    string text = "";
    istringstream stream(phrase);
    stream >> buffer;
    while (stream && !buffer.empty()) {
        if (maxLength == buffer.length()) {
            text += buffer + " ";
        }
        buffer = "";
        stream >> buffer;
    }
    return text;
}

string readLines(string& file) {
    string line;
    ifstream readFile(file);
    string text = "";

    while (getline(readFile, line)) {
        text += getLongestWord(line) + "\n";
    }
    return text;
}

string deleteLongestWord(const string& phrase) {
    string text = getLongestWord(phrase);
    string buffer;
    istringstream stream(phrase);
    stream >> buffer;
    string output = "";
    while (stream && !buffer.empty()) {
        if (text.find(buffer) == string::npos) {
            output += buffer + " ";
        }
        buffer = "";
        stream >> buffer;
    }
    return output;
}

void checkWordNumbersInString(const string& phrase, int& number) {
    string buffer;
    number = 0;
    istringstream stream(phrase);

    stream >> buffer;
    while (stream && !buffer.empty()) {
        buffer = "";
        number++;
        stream >> buffer;
    }
}

void checkWordNumbersInFile(const string& file, int& number) {
    ifstream readFile(file);
    string buffer;
    number = 0;

    readFile >> buffer;
    while (readFile && !buffer.empty()) {
        buffer = "";
        number++;
        readFile >> buffer;
    }
}

int checkChar(const string& word, char character) {
    int characterNumber = 0;

    for (char i : word) {
        if (i == character) {
            characterNumber++;

            if (characterNumber == 2) {
                return 1;
            }
        }
    }
    return 0;
}

string checkRepeatChar(const string& phrase, char character) {
    string buffer;
    istringstream stream(phrase);
    string text = "";

    stream >> buffer;
    while (stream && !buffer.empty()) {
        if (checkChar(buffer, character)) {
            text += buffer + " ";
        }
        buffer = "";
        stream >> buffer;
    }
    return text;
}

int main() {
    string myString;
    string file1 = "C:\\Users\\gutsu\\OneDrive\\Рабочий стол\\lab 5\\LAB 5\\LAB 5\\text.txt";
    string file2 = "C:\\Users\\gutsu\\OneDrive\\Рабочий стол\\lab 5\\LAB 5\\LAB 5\\text2.txt";
    string text;
    string myNewString;
    int number;
    char operation;
    char character;

    cout << "Enter phrase: ";
    getline(cin, myString);
    writeTextFile(myString, file1);

    do {
        cout << endl
            << "Chose option: " << endl
            << "1. Determina numarul de cuvinte " << endl
            << "2. De determinat cuvintele dintr-o fraza, de lungimea maxima " << endl
            << "3. De sters cuvintele dintr-o fraza, care satisfac conditia indicata " << endl
            << "4. Intr-un fisier text de determinat numarul de cuvinte " << endl
            << "5. De inscris in alt fisier text cuvintele, care satisfac condiţia indicata. " << endl
            << "6. De sters cuvintele dintr-un fisier text, care satisfac conditia indicata " << endl
            << "7. Intr-un fisier text de determinat cuvintele ce satisfac o conditie suplimentara " << endl
            << "0. Exit" << endl;
        cin >> operation;
        system("CLS");

        switch (operation) {
        case '1':
            checkWordNumbersInString(myString, number);
            cout << "numarul de litere: \t" <<  number ;
            break;

        case '2':
            cout << "Cuvante cu cea mai mare lungimea: " << getLongestWord(myString);
            break;

        case '3':
            cout << "De sters cuvantele cu lungimea maximala: " << deleteLongestWord(myString);
            break;

        case '4':
            checkWordNumbersInFile(file1, number);
            cout << number << " cuvinte in fisier ";
            break;


        case '5':
            cout << "Text file: ";
            cout << getLongestWord(readLines(file1));
            break;


        case '6':
            cout << "Text file: ";
            writeTextFile(deleteLongestWord(myString), file2);
            cout << readTextFile(file2);
            break;

        case '7':
            cout << " Enter character to search:\n";
            cin >> character;
            cout << checkRepeatChar(myString,character);
            break;

        case '0':
            cout << "Exit from program successful!";
            break;

        default:
            cout << "Wrong option" << endl;
            break;
        }
    } while (operation != '0');
}