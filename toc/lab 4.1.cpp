#include <stdio.h>
#include <string.h>

#define MAX 10

void removeLeftRecursion(char nonTerminal, char* production) {
    char alpha[MAX][MAX], beta[MAX][MAX];
    int i = 0, j = 0, k = 0, l = 0;
    int isLeftRecursive = 0;

    char* token = strtok(production, "|");
    
    // Separate alpha and beta productions
    while (token != NULL) {
        if (token[0] == nonTerminal) {
            isLeftRecursive = 1;
            strcpy(alpha[i++], token + 1);  // remove leading non-terminal
        } else {
            strcpy(beta[j++], token);
        }
        token = strtok(NULL, "|");
    }

    if (isLeftRecursive) {
        // Print transformed productions
        printf("%c -> ", nonTerminal);
        for (k = 0; k < j; k++) {
            printf("%s%c' ", beta[k], nonTerminal);
            if (k != j - 1) printf("| ");
        }

        printf("\n%c' -> ", nonTerminal);
        for (l = 0; l < i; l++) {
            printf("%s%c' ", alpha[l], nonTerminal);
            if (l != i - 1) printf("| ");
        }
        printf("| e\n");
    } else {
        // No left recursion
        printf("%c -> %s\n", nonTerminal, production);
    }
}

int main() {
    // Example grammar
    char nonTerminals[3] = {'E', 'T', 'F'};
    char productions[3][MAX] = {
        "E+T|T",
        "T*F|F",
        "(E)|id"
    };

    for (int i = 0; i < 3; i++) {
        removeLeftRecursion(nonTerminals[i], productions[i]);
    }

    return 0;
}

