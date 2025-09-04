#include <iostream>
#include <string>
using namespace std;
bool turingMachine(string input) {
    int n = input.length();
    int aCount = 0, bCount = 0;
    int i = 0;
    while (i < n && input[i] == 'a') {
        aCount++;
        i++;
    }
    while (i < n && input[i] == 'b') {
        bCount++;
        i++;
    }
    if (i != n || aCount != bCount || aCount == 0) {
        return false;
    }
    return true;
}
int main() {
    string input;
    cout << "Enter input string (only a's followed by b's): ";
    cin >> input;
    if (turingMachine(input)) {
        cout << "String ACCEPTED by the Turing Machine.\n";
    } else {
        cout << "String REJECTED by the Turing Machine.\n";
    }
    return 0;
}