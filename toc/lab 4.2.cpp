#include <iostream>
#include <string>
using namespace std;

// Function to find longest common prefix of two strings
string commonPrefix(string s1, string s2) {
    string result = "";
    int len = min(s1.length(), s2.length());
    for (int i = 0; i < len; i++) {
        if (s1[i] == s2[i])
            result += s1[i];
        else
            break;
    }
    return result;
}

int main() {
    string prodE1 = "iEtsAs";
    string prodE2 = "iEts";
    string A = "a";

    cout << "Original Grammar:" << endl;
    cout << "E -> " << prodE1 << " | " << prodE2 << endl;
    cout << "A -> " << A << endl << endl;

    // Find common prefix
    string prefix = commonPrefix(prodE1, prodE2);
    string rem1 = prodE1.substr(prefix.length());
    string rem2 = prodE2.substr(prefix.length());

    cout << "After Removing Left Factoring:" << endl;
    cout << "E -> " << prefix << "E'" << endl;
    cout << "E' -> " << (rem1.empty() ? "e" : rem1);
    if (!rem2.empty())
        cout << " | " << rem2;
    else
        cout << " | e";
    cout << endl;

    cout << "A -> " << A << endl;

    return 0;
}

