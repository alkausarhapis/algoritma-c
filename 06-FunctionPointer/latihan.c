#include <stdio.h>

int main () {
    int arr[10];

    // Array values
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
        // print 0-9 and arr pointer address
        printf("%d = %d\n", i, &arr[i]);
    }

    // Declare pointer
    int *a;
    int b;

    // Replace 0 with new value
    scanf("%d %d", &a, &b);
    // arr[i] = b
    *a = b;

    // Undo print
    for (int i = 0; i < 10; i++)
    {
        printf("%d = %d\n", i, arr[i]);
    }
    return 0;
}