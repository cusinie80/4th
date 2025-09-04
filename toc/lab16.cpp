#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindromePDA(string input) {
    stack<char> st;
    int n = input.size();
    int mid = n / 2;

    // Push first half onto stack
    for (int i = 0; i < mid; i++) {
        st.push(input[i]);
    }

    int startSecondHalf = (n % 2 == 0) ? mid : mid + 1; // skip middle for odd length

    // Match second half with stack
    for (int i = startSecondHalf; i < n; i++) {
        if (st.empty() || st.top() != input[i])
            return false; // mismatch
        st.pop();
    }

    return st.empty(); // accepted if stack fully matched
}

int main() {
    string str;
    cout << "Enter string over {a,b}: ";
    cin >> str;

    if (isPalindromePDA(str))
        cout << str << " is ACCEPTED" << endl;
    else
        cout << str << " is REJECTED" << endl;

    return 0;
}
