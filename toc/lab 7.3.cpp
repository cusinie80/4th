#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to compute two's complement
string twosComplement(string bin) {
    int n = bin.length();

    // Step 1: Invert the bits
    string inverted = bin;
    for (int i = 0; i < n; i++) {
        inverted[i] = (bin[i] == '0') ? '1' : '0';
    }

    // Step 2: Add 1 to the inverted binary number
    string result = inverted;
    bool carry = true;
    for (int i = n - 1; i >= 0; i--) {
        if (inverted[i] == '1' && carry) {
            result[i] = '0';
        } else if (inverted[i] == '0' && carry) {
            result[i] = '1';
            carry = false;
        } else {
            result[i] = inverted[i]; // No change
        }
    }

    return result;
}

int main() {
    string input;
    cout << "Enter an 8-bit binary number: ";
    cin >> input;

    // Validate input
    if (input.length() != 8 || input.find_first_not_of("01") != string::npos) {
        cout << "Invalid input. Please enter an 8-bit binary number (only 0 and 1).\n";
        return 1;
    }

    string result = twosComplement(input);
    cout << "Two's complement: " << result << endl;

    return 0;
}
