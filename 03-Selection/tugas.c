#include <stdio.h>

int main() {

    int input;
    int atas, bawah;

    scanf("%d\n", &input);
    scanf("%d %d\n", &atas, &bawah);

    if (input >= atas && input <= bawah)
    {
        printf("Nilai %d diantara %d dan %d\n", input, atas, bawah);
    } else {
        printf("Nilai %d tidak diantara %d dan %d\n", input, atas, bawah);
    }
    

    return 0;
}