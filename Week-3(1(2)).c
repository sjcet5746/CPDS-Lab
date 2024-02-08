#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
// Function to delete n characters from a given position in a string
void deleteChars(char string[], int position, int n) {
    int length = strlen(string);

    // Shift characters to the left to overwrite the deleted characters
    for (int i = position; i <= length; i++) {
        string[i] = string[i + n];
    }
}
int main() {
    char string[MAX_LENGTH];
    int position, n;
    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);
    string[strcspn(string, "\n")] = '\0'; // Removing trailing newline character
    printf("Enter the position to start deletion: ");
    scanf("%d", &position);
    printf("Enter the number of characters to delete: ");
    scanf("%d", &n);
    if (position < 0 || position >= strlen(string) || n < 0) {
        printf("Invalid input!\n");
        return 1;
    }
    deleteChars(string, position, n);
    printf("Result after deletion: %s\n", string);
    return 0;
}
