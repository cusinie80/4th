#include <iostream>
#include <string>
using namespace std;

// Function to check if a string is an even-length palindrome
bool isEvenPalindrome(const string& s) {
    int n = s.length();

    // Check for even length
    if (n % 2 != 0) {
        return false;
    }

    // Check for palindrome
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    // Validate input
    for (char c : input) {
        if (c != 'a' && c != 'b') {
            cout << "Invalid input: only 'a' and 'b' allowed.\n";
            return 1;
        }
    }

    if (isEvenPalindrome(input)) {
        cout << "ACCEPTED: The string is an even-length palindrome.\n";
    } else {
        cout << "REJECTED: The string is NOT an even-length palindrome.\n";
    }

    return 0;
}
