#include <iostream>
using namespace std;

int main() {
    cout << "DFA that accepts the string '1001' \n";

    string R0 = "";
    string R1 = "1";
    string R2 = "10";
    string R3 = "100";
    string R4 = "1001";

    cout << "\nBuilding the Regular Expression step by step:\n";
    cout << "R1 = " << R0 << " + 1 = " << R1 << endl;
    cout << "R2 = " << R1 << " + 0 = " << R2 << endl;
    cout << "R3 = " << R2 << " + 0 = " << R3 << endl;
    cout << "R4 = " << R3 << " + 1 = " << R4 << endl;

    cout << "\nSo, the regular expression that accepts the string is: " << R4 << endl;

    return 0;
}
