#include <stdio.h>
#include <string.h>
// Function to find the position of string T in string S
int findString(const char *S, const char *T) {
    int i, j, pos = -1;
    for (i = 0; S[i] != '\0'; i++) {
        j = 0;
        while (T[j] != '\0' && S[i + j] == T[j])
            j++;
        if (T[j] == '\0') {
            pos = i;
            break;
        }
    }
    return pos;
}
int main() {
    char S[100], T[100];
    printf("Enter string S: ");
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = '\0'; // Removing trailing newline character
    printf("Enter string T: ");
    fgets(T, sizeof(T), stdin);
    T[strcspn(T, "\n")] = '\0'; // Removing trailing newline character
    int position = findString(S, T);
    if (position != -1) {
        printf("String T begins at position %d in string S.\n", position);
    } else {
        printf("String T does not exist in string S.\n");
    }
    return 0;
}
