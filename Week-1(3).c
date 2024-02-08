#include <stdio.h>
// Function to solve Towers of Hanoi problem recursively
void towersOfHanoi(int num_disks, char source, char auxiliary, char destination) {
    if (num_disks == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    towersOfHanoi(num_disks - 1, source, destination, auxiliary);
    printf("Move disk %d from rod %c to rod %c\n", num_disks, source, destination);
    towersOfHanoi(num_disks - 1, auxiliary, source, destination);
}
int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    printf("Steps to solve Towers of Hanoi problem with %d disks:\n", num_disks);
    towersOfHanoi(num_disks, 'A', 'B', 'C');
    return 0;
}
