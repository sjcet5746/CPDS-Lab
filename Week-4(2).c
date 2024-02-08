#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 1000
// Function to count lines, words, and characters in a given text
void countMetrics(char text[], int *lines, int *words, int *characters) {
    *lines = 0;
    *words = 0;
    *characters = 0;
    int i = 0;
    char c;
    // Counting lines, words, and characters
    while ((c = text[i]) != '\0') {
        if (c == '\n') {
            (*lines)++;
        }
        if (!isspace(c) && (isspace(text[i - 1]) || i == 0)) {
            (*words)++;
        }
        if (!isspace(c)) {
            (*characters)++;
        }
        i++;
    }
}
int main() {
    char text[MAX_LENGTH];
    printf("Enter the text (press Ctrl+D on Unix/Linux or Ctrl+Z on Windows to end input):\n");
    // Read text until EOF (End of File)
    int c, i = 0;
    while ((c = getchar()) != EOF && i < MAX_LENGTH - 1) {
        text[i++] = c;
    }
    text[i] = '\0'; // Null-terminate the string
    int lines, words, characters;
    // Count lines, words, and characters
    countMetrics(text, &lines, &words, &characters);
    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);
    return 0;
}
