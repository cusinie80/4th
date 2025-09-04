#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter a binary string: ";
    cin >> s;

    int state = 0; // q0 = even 1s, q1 = odd 1s

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            state = 1 - state; // toggle state on '1'
        // '0' causes no change
    }

    if (state == 1)
        cout << "Accepted (odd number of 1s)\n";
    else
        cout << "Rejected (even number of 1s)\n";

    return 0;
}

