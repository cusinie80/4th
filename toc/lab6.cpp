
#include <iostream>
using namespace std;

const int NFA_STATES = 5;
const int DFA_STATES = 8; // up to 2^NFA_STATES possible subsets
const int SYMBOLS = 2; // '0' and '1'

// NFA transitions: nfa[state][symbol][index]
int nfa[NFA_STATES][SYMBOLS][2]; // max 2 next states per symbol, for simplicity

// DFA transitions: dfa[state][symbol] = next DFA state index
int dfa[DFA_STATES][SYMBOLS];

// DFA state bitmasks: each DFA state represents a set of NFA states
int dfaStates[DFA_STATES];
int dfaCount = 0;

// Get next NFA set (bitmask) for a given DFA state and input symbol
int getNextSet(int currentSet, int symbol) {
    int nextSet = 0;
    for (int state = 0; state < NFA_STATES; state++) {
        if (currentSet & (1 << state)) {
            for (int i = 0; i < 2; i++) {
                int next = nfa[state][symbol][i];
                if (next != -1)
                    nextSet |= (1 << next);
            }
        }
    }
    return nextSet;
}

// Find existing DFA state number or add as new
int getOrAddDfaState(int set) {
    for (int i = 0; i < dfaCount; i++) {
        if (dfaStates[i] == set)
            return i;
    }
    dfaStates[dfaCount] = set;
    return dfaCount++;
}

int main() {
    // Initialize NFA transitions to -1 (no transition)
    for (int i = 0; i < NFA_STATES; i++)
        for (int s = 0; s < SYMBOLS; s++)
            for (int k = 0; k < 2; k++)
                nfa[i][s][k] = -1;

    // Define NFA for "1001"
    nfa[0][1][0] = 1; // state 0 on '1' ? 1
    nfa[1][0][0] = 2; // state 1 on '0' ? 2
    nfa[2][0][0] = 3; // state 2 on '0' ? 3
    nfa[3][1][0] = 4; // state 3 on '1' ? 4

    // Initialize DFA start state as {0} ? bitmask = 1<<0 = 1
    dfaCount = 0;
    dfaStates[dfaCount++] = 1 << 0;

    // Build DFA using simple loop
    for (int i = 0; i < dfaCount; i++) {
        for (int symbol = 0; symbol < SYMBOLS; symbol++) {
            int nextSet = getNextSet(dfaStates[i], symbol);
            if (nextSet == 0)
                dfa[i][symbol] = -1; // dead state
            else
                dfa[i][symbol] = getOrAddDfaState(nextSet);
        }
    }

    // Print DFA transition table using q0, q1, ...
    cout << "DFA Transition Table:\n";
    cout << "State\tOn 0\tOn 1\n";
    for (int i = 0; i < dfaCount; i++) {
        cout << "q" << i << "\t";
        for (int symbol = 0; symbol < SYMBOLS; symbol++) {
            if (dfa[i][symbol] == -1)
                cout << "-\t";
            else
                cout << "q" << dfa[i][symbol] << "\t";
        }
        cout << endl;
    }

    // Print final DFA states (those containing NFA final state 4)
    cout << "\nFinal DFA States: ";
    for (int i = 0; i < dfaCount; i++) {
        if (dfaStates[i] & (1 << 4))
            cout << "q" << i << " ";
    }
    cout << endl;

    return 0;
}
