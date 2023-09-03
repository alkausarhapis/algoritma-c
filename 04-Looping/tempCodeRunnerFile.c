#include <stdio.h>

int main() {
    int a;

    printf("Enter the number of rows: ");
    scanf("%d", &a);

    for (int i = 1; i <= a; i++) {
        // Print spaces before the dots
        for (int j = 1; j <= a - i; j++) {
            printf(" ");
        }

        // Print dots for this row
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf(".");
        }

        printf("\n");
    }

    return 0;
}