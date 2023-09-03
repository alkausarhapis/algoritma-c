#include <stdio.h>
#include <string.h>

int main () {

    // Replace string
    char str[20][100];

    // Same as
    // int a;
    // scanf("%d", a);
    // a = 11;
    // printf("%d", a);

    scanf("%s", str[0]);
    strcpy(str[0], "Replaced");
    printf("%s\n", str[0]);

    // int a[5];
    // a[0] = 1;
    // printf("%d\n", a[0]);
    // a[0] = 2;
    // printf("%d", a[0]);

    return 0;
}