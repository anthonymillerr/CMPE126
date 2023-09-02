#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


bool isDigit(char c) {  
    return c >= '0' && c <= '9';
}

int isInteger(string s) {  //Function to convert a string to an integer
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!isDigit(s[i])) { //If character is not a digit
            throw "Invalid input";
        }
        num = num * 10 + (s[i] - '0'); //Convert character to integer and add to num
    }
    return num;
}

// Function to convert a string to a double
double isDouble(string s) {
    stack<int> digits;
    bool decimalPointFound = false;
    int decimalPlaces = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') { //Decimal point is found
            decimalPointFound = true;
        }
        else if (isDigit(s[i])) { // If character is a digit, push it to the stack
            digits.push(s[i] - '0');
            if (decimalPointFound) { // If decimal point has been found, increment decimal places
                decimalPlaces++;
            }
        }
        else { // If character is not a digit or decimal point
            throw "Invalid input";
        }
    }
    double num = 0.0;
    double placeValue = 1.0;
    while (!digits.empty()) { // Pop each digit from the stack and add to num with corresponding place value
        num += digits.top() * placeValue;
        digits.pop();
        placeValue *= 10.0;
    }
    return num / pow(10, decimalPlaces); // Divide by 10 to the power of decimal places to get the final double value
}

int main() {
    string s;
    cout << "Enter A Positive Integer Or Decimal Number: ";
    cin >> s;
    if (s.find('.') == string::npos) { // If decimal point is not found in input, convert to integer
        int num = isInteger(s);
        cout << "Integer String Converted To Value: " << num << endl;
    }
    else { // If decimal point is found in input, convert to double
        double num = isDouble(s);
        cout << "Decimal String Converted To Value: " << num << endl;
    }
}
