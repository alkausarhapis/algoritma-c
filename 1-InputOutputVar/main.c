#include <stdio.h>
// stdio means stardart input output

int main() {
    int bilBulat;
    float decimal = 1.5f;
    char karakter = 'a';
    char string[100] = "Hello world";

    printf("Masukkan int : ");
    scanf("%d", &bilBulat);
    getchar();
    printf("%d\n", bilBulat);

    printf("Masukkan desimal : ");
    scanf("%f", &decimal);
    getchar();
    // .3 = berapa angka dibelakang koma
    printf("%.3f\n", decimal);

    printf("Masukkan char : ");
    scanf("%c", &karakter);
    getchar();
    printf("%c\n", karakter);

    printf("Masukkan string : ");
    scanf("%[^]", string);
    getchar();
    printf("%s\n", string);
    return 0;
}