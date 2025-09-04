#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter a binary string: ";
    cin >> s;

    int state = 0;
    char c;

    for (int i = 0; i < s.length(); i++) {
        c = s[i];
        switch (state) {
            case 0: state = (c == '1') ? 1 : -1; break;
            case 1: state = (c == '0') ? 2 : -1; break;
            case 2: state = (c == '0') ? 3 : -1; break;
            case 3: state = (c == '1') ? 4 : -1; break;
            default: state = -1;
        }
        if (state == -1) break;
    }

    if (state == 4)
        cout << "Accepted (input is 1001)\n";
    else
        cout << "Rejected (input is not 1001)\n";

    return 0;
}

