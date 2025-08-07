#include <iostream>
#include <stack>
using namespace std;

bool isAccepted(string input) {
    stack<char> st;
    int i = 0;
    
    // Push 'a's
    while (i < input.length() && input[i] == 'a') {
        st.push('A');
        i++;
    }

    // Pop for 'b's
    while (i < input.length() && input[i] == 'b') {
        if (st.empty()) return false;
        st.pop();
        i++;
    }

    // If all a's matched with b's and stack is empty
    return (st.empty() && i == input.length());
}

int main() {
    string str = "aaaabbbb";
    cout<<"ayush Rauniyar\n";
    if (isAccepted(str))
        cout << "aaaabbbb Accepted\n";
    else
        cout << "aaaabbbb Rejected\n";
    return 0;
}

