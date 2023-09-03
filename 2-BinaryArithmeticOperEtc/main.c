#include <stdio.h>

int main() {
    // printf("Ini tambah : %d\n", 2+3); printf("Ini kurang : %d\n", 3-2);
    // printf("Ini kali : %d\n", 3*3);
    // printf("Ini bagi : %d\n", 5/2);
    // printf("Ini bagi (desimal) : %f\n", 5.0/2.0);
    // printf("Arithmetic (%d+%d) /%d = %d\n", 5, 2, 3, (5+2)/3);
    // printf("AND: %d\n", 6&5);
    // printf("OR: %d\n", 6|5);
    // printf("XOR : %d\n", 6^5);
    // printf("Shift Right: %d\n", 6>>2); printf("Shift Left : %d\n", 6<<2);


    // Pre-increment
    int angka = 0;
    printf("====PRE INCREMENT====\n");
    printf("%d\n", ++angka);
    
    // Post-increment
    int angka2 = 0;
    printf("====POST INCREMENT====\n");
    printf("%d\n", angka2++);
    printf("%d\n", angka2);

    // Pre-decrement
    int angka3 = 0;
    printf("====PRE DECREMENT====\n");
    printf("%d\n", --angka3);

    // Post-decrement
    int angka4 = 0;
    printf("====POST DECREMENT====\n");
    printf("%d\n", angka4--);
    printf("%d\n", angka4);

    return 0;
}