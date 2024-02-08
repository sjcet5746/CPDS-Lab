#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
// Function to insert a substring into a main string from a given position
void insertSubstring(char mainString[], char subString[], int position) {
    int mainLength = strlen(mainString);
    int subLength = strlen(subString);
    // Shift characters to the right to make space for the substring
    for (int i = mainLength; i >= position; i--) {
        mainString[i + subLength] = mainString[i];
    }
    // Insert the substring into the main string
    for (int i = 0; i < subLength; i++) {
        mainString[position + i] = subString[i];
    }
}
int main() {
    char mainString[MAX_LENGTH], subString[MAX_LENGTH];
    int position;
    printf("Enter the main string: ");
    fgets(mainString, MAX_LENGTH, stdin);
    mainString[strcspn(mainString, "\n")] = '\0'; // Removing trailing newline character
    printf("Enter the substring to insert: ");
    fgets(subString, MAX_LENGTH, stdin);
    subString[strcspn(subString, "\n")] = '\0'; // Removing trailing newline character
    printf("Enter the position to insert the substring: ");
    scanf("%d", &position);
    if (position < 0 || position > strlen(mainString)) {
        printf("Invalid position!\n");
        return 1;
    }
    insertSubstring(mainString, subString, position);
    printf("Result after insertion: %s\n", mainString);
    return 0;
}
