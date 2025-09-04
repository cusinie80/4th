#include <iostream>
#include <string>

using namespace std;

// Function to simulate a Turing Machine that accepts odd-length palindromes
bool isOddPalindrome(string tape) {
    int n = tape.length();

    // Reject if length is even
    if (n % 2 == 0) {
        return false;
    }

    // Check if it's a palindrome
    for (int i = 0; i < n / 2; i++) {
        if (tape[i] != tape[n - i - 1]) {
            return false; // Mismatch
        }
    }

    // All characters matched
    return true;
}

int main() {
    string input;

    cout << "Enter a binary string (0s and 1s only): ";
    cin >> input;

    // Check for invalid characters
    for (char c : input) {
        if (c != '0' && c != '1') {
            cout << "Invalid input. Only binary strings are allowed." << endl;
            return 1;
        }
    }

    if (isOddPalindrome(input)) {
        cout << "ACCEPTED: The string is an odd-length palindrome." << endl;
    } else {
        cout << "REJECTED: The string is NOT an odd-length palindrome." << endl;
    }

    return 0;
}