#include <stdio.h>

// Recursive adalah function yang memanggil dirinya sendiri
int fibonacci (int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}


int main () {

    int f = fibonacci(10);

    printf("%d", f);

    return 0;
}