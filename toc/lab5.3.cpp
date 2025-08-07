#include <iostream>
#include <stack>
using namespace std;

bool isEvenPalindrome(string str) {
    int n = str.length();

    // Odd-length strings cannot be in ww^r
    if (n % 2 != 0) return false;

    stack<char> st;

    // Push first half into stack
    for (int i = 0; i < n / 2; ++i) {
        st.push(str[i]);
    }

    // Compare second half with stack
    for (int i = n / 2; i < n; ++i) {
        if (st.empty()) return false;
        if (str[i] != st.top()) return false;
        st.pop();
    }

    // If stack is empty, it matched fully
    return st.empty();
}

int main() {
    string input = "abba"; // Change this to test other strings
 cout<<"ayush Rauniyar\n";
    if (isEvenPalindrome(input))
        cout << "Accepted: " << input << " is in ww^r\n";
    else
        cout << "Rejected: " << input << " is NOT in ww^r\n";

    return 0;
}

