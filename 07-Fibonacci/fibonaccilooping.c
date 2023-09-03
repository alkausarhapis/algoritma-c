#include <stdio.h>

int main () {
    int fn1, fn2, n, fn;

    printf("Masukkan index fibonacci : ");
    scanf("%d", &n);

    if (n >= 1) {
        fn1 = 0;
        fn2 = 1;
        fn = 0;

        for (int i = 0; i <= n; i++)
        {
            printf("Nilai ke- %d Fibonaccinya %d\n", i, fn);
            fn = fn1 + fn2;
            fn2 = fn1;
            fn1 = fn;
        }
    }
    printf("Masukkan nilai selain 0");

    
    return 0;
}