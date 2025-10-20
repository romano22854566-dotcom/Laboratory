#include "Utilities.hpp"
#include <iostream>

using namespace std;

int InputInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            return value;
        }
        else {
            cout << "Ошибка: введите целое число\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
}

float InputFloat(const string& prompt) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            return value;
        }
        else {
            cout << "Ошибка: введите число с плавающей точкой\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
}

string InputString(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin,input);
        if (!input.empty()) return input;
        cout << "Ошибка\n";
    }
}

char InputChar(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin,input);
        if (input.size() == 1) return input[0];
        cout << "Ошибка: введите один символ\n";
    }
}
