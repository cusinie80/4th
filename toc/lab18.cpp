#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isAccepted(string input) {
    stack<char> st;
    int i = 0, n = input.length();
    int a_count = 0;
    int b_count = 0;
    int c_count = 0;
    while (i < n && input[i] == 'a') {
        st.push('A');
        a_count++;
        i++;
    }
    while (i < n && input[i] == 'b') {
        b_count++;
        i++;
    }
    while (i < n && input[i] == 'c') {
        if (st.empty()) return false;
        st.pop();
        c_count++;
        i++;
    }
    if (b_count != 2 * a_count) return false; 
    if (c_count != a_count) return false;     
    return (i == n && st.empty());
}
int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;
    if (isAccepted(input)) {
        cout << "Accepted by the PDA." << endl;
    } else {
        cout << "Rejected by the PDA." << endl;
    }
    return 0;
}