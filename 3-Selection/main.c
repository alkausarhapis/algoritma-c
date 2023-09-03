#include <stdio.h>

int main() {
    // lebih lengkapnya di intellij
    int a = 134225;

    // if else
    if (a%2 == 0)
    {
        printf("angka genap\n");
    } else {
        printf("angka ganjil\n");
    }
    
    
    // switch
    switch (a)
    {
    case 1:
        printf("satu\n");
        break;
    
    case 2:
        printf("satu\n");
        break;
    
    case 3:
        printf("satu\n");
        break;
    
    case 4:
        printf("satu\n");
        break;
    
    default:
        printf("bukan 1-4\n");
        break;
    }

    // ternary
    printf("%s", (a%2==0? "Genap\n" : "Ganjil\n"));

    return 0;
}