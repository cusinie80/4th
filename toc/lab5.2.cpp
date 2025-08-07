#include <iostream>
#include <stack>
using namespace std;

bool isAccepted(string input) {
    stack<char> st;
    int i = 0;
    int n = input.length();

    // Phase 1: Push until 'c' is found
    while (i < n && input[i] != 'c') {
        if (input[i] == '0' || input[i] == '1')
            st.push(input[i]);
        else
            return false; // invalid character
        i++;
    }

    // If 'c' not found or at start/end, reject
    if (i == n || i == 0 || i == n - 1 || input[i] != 'c') return false;

    i++; // Skip 'c'

    // Phase 2: Compare with stack
    while (i < n) {
        if (st.empty()) return false;
        if (input[i] != st.top()) return false;
        st.pop();
        i++;
    }

    // If stack is empty after full match, accept
    return st.empty();
}

int main() {
    string str = "11c11";
     cout<<"ayush Rauniyar\n";
    if (isAccepted(str))
        cout << "11c11 Accepted\n";
    else
        cout << "11c11 Rejected\n";
    return 0;
}

