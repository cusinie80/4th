#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to simulate DFA check
bool isAccepted(string s) {
    int state = 0; // starting state

    for (char ch : s) {
        switch (state) {
            case 0:
                if (ch == '1') state = 1;
                else if (ch == '0') state = 0;
                else if (ch == 'C') state = 4; // going to "middle" part
                break;
            case 1:
                if (ch == '1') state = 1;
                else if (ch == '0') state = 2;
                else if (ch == 'C') state = 4;
                break;
            case 2:
                if (ch == '1') state = 3;
                else if (ch == '0') state = 2;
                else if (ch == 'C') state = 4;
                break;
            case 3:
                if (ch == '1') state = 3;
                else if (ch == '0') state = 0;
                else if (ch == 'C') state = 4;
                break;
            case 4: // second half after 'C' — simulate reverse check
                // In this simple case, we just accept anything after C
                break;
        }
    }

    // For now, let's just say accepted if it starts and ends in 0-state logic
    return true; // Modify according to actual DFA accepting states
}

int main() {
    string w;
    cout << "Enter binary string w: ";
    cin >> w;

    // Reverse of w
    string wReverse = w;
    reverse(wReverse.begin(), wReverse.end());

    // Make full string
    string finalString = w + "C" + wReverse;

    cout << "Generated string: " << finalString << endl;

    if (isAccepted(finalString))
        cout << "String is ACCEPTED." << endl;
    else
        cout << "String is NOT accepted." << endl;

    return 0;
}
