#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isAnBn(string str) {
    stack<char> st;
    int i = 0, n = str.length();

    // q0: Read 'a' and push
    while (i < n && str[i] == 'a') {
        st.push('A');
        i++;
    }

    // q1: Read 'b' and pop
    while (i < n && str[i] == 'b') {
        if (st.empty()) return false; // More b's than a's
        st.pop();
        i++;
    }

    // Accept if all matched and stack is empty
    return (i == n && st.empty());
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    if (isAnBn(input))
        cout << "Accepted: String is in L = {a^n b^n | n>=1}" << endl;
    else
        cout << "Rejected: String not in language" << endl;
}
