#include <iostream>
#include <cstring>
using namespace std;

int main() {
    cout << "Rightmost derivation of string: -(id*id)+id\n";
    cout << "Grammar:\n";
    cout << "S ? S*S | S+S | -S | (S) | id\n\n";

    // We'll store and print the derivation at each step
    char step[100];

    // Step 1: Start with S
    strcpy(step, "S");
    cout << step << endl;

    // Step 2: S ? S+S
    strcpy(step, "S+S");
    cout << step << endl;

    // Step 3: rightmost S ? -S
    strcpy(step, "S+-S");
    cout << step << endl;

    // Step 4: -S ? (S)
    strcpy(step, "S+(S)");
    cout << step << endl;

    // Step 5: (S) ? (S*S)
    strcpy(step, "S+(S*S)");
    cout << step << endl;

    // Step 6: rightmost S ? id ? (S*id)
    strcpy(step, "S+(S*id)");
    cout << step << endl;

    // Step 7: left S inside ? id ? (id*id)
    strcpy(step, "S+(id*id)");
    cout << step << endl;

    // Step 8: leftmost S ? id ? (id*id)+id
    strcpy(step, "(id*id)+id");
    cout << step << endl;

    return 0;
}

