#include <iostream>
using namespace std;

int main() {
    char a[4];
    cout << "Enter 4-character binary string (e.g., 1001):\n";
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    int state = 0;  // Start at q0

    for (int i = 0; i < 4; i++) {
        switch (state) {
            case 0:  // q0
                if (a[i] == '1')
                    state = 1;  // q1
                else
                    state = -1; // invalid
                break;

            case 1:  // q1
                if (a[i] == '0')
                    state = 2;  // q2
                else
                    state = -1;
                break;

            case 2:  // q2
                if (a[i] == '0')
                    state = 3;  // q3
                else
                    state = -1;
                break;

            case 3:  // q3
                if (a[i] == '1')
                    state = 4;  // q4 (accept)
                else
                    state = -1;
                break;

            default:
                state = -1;
        }

        if (state == -1) {
            break; // invalid path, reject early
        }
    }

    if (state == 4)
        cout << "Accepted by NFA\n";
    else
        cout << "Rejected by NFA\n";

    return 0;
}

