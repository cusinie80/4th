#include <iostream>
#include <string>

using namespace std;

// Function to simulate a Turing Machine that accepts even-length palindromes
bool isEvenPalindrome(string tape) {
    int left = 0;
    int right = tape.length() - 1;

    // Check for even length
    if (tape.length() % 2 != 0) {
        return false; // Reject odd-length strings
    }

    // Simulate matching outer characters
    while (left < right) {
        if (tape[left] != tape[right]) {
            return false; // Mismatch ? Not a palindrome
        }
        // Move the head inward
        left++;
        right--;
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

    if (isEvenPalindrome(input)) {
        cout << "ACCEPTED: The string is an even-length palindrome." << endl;
    } else {
        cout << "REJECTED: The string is NOT an even-length palindrome." << endl;
    }

    return 0;
}