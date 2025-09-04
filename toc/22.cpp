#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to compute 2's complement
string twosComplement(string binary) {
    int n = binary.length();

    // Step 1: Invert the bits
    string inverted = binary;
    for (int i = 0; i < n; i++) {
        inverted[i] = (binary[i] == '0') ? '1' : '0';
    }

    // Step 2: Add 1 to the inverted string
    string result = inverted;
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (result[i] == '1' && carry == 1) {
            result[i] = '0';
            carry = 1;
        } else if (result[i] == '0' && carry == 1) {
            result[i] = '1';
            carry = 0;
        }
    }

    return result;
}

// Function to validate if a string is binary
bool isBinary(string s) {
    for (char c : s) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

int main() {
    string original, supposedComplement;

    cout << "Enter the original binary string: ";
    cin >> original;

    cout << "Enter the supposed 2's complement: ";
    cin >> supposedComplement;

    // Validate inputs
    if (!isBinary(original) || !isBinary(supposedComplement)) {
        cout << "REJECTED: Inputs must be binary strings (0s and 1s only)." << endl;
        return 1;
    }

    // Pad the shorter string with leading zeros
    int len1 = original.length();
    int len2 = supposedComplement.length();
    if (len1 < len2) {
        original = string(len2 - len1, '0') + original;
    } else if (len2 < len1) {
        supposedComplement = string(len1 - len2, '0') + supposedComplement;
    }

    string actualComplement = twosComplement(original);

    if (actualComplement == supposedComplement) {
        cout << "ACCEPTED: The second string is the 2's complement of the first." << endl;
    } else {
        cout << "REJECTED: The second string is NOT the 2's complement of the first." << endl;
        cout << "Expected 2's complement: " << actualComplement << endl;
    }

    return 0;
}