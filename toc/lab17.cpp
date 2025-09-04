#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isAccepted(const string& input) {
    stack<char> st;
    int i = 0;
    int len = input.length();

    // First, process 'a's and push to stack
    while (i < len && input[i] == 'a') {
        st.push('A');  // Push for every 'a'
        i++;
    }

    // Now process 'b's
    while (i < len && input[i] == 'b') {
        // For each 'b', pop 2 'a's
        if (st.size() < 2) {
            return false;  // Not enough 'a's for this 'b'
        }
        st.pop();
        st.pop();
        i++;
    }

    // If there are leftover characters or stack is not empty, reject
    if (i != len || !st.empty()) {
        return false;
    }

    return true;
}

int main() {
    string input;
    cout << "Enter string of the form a^2n b^n: ";
    cin >> input;

    if (isAccepted(input)) {
        cout << "String is accepted by the PDA.\n";
    } else {
        cout << "String is rejected by the PDA.\n";
    }

    return 0;
}