#include <stdio.h>

// Function
void printHello() {
    printf("Hello world\n");
}

int sum(int a, int b) {
    int total = a + b;
    return total;
}

int sumpoint(int *a, int *b) {
    // int *a = &first;
    printf("Alamat = %d\n", a);
    int total = *a + *b;
    return total;
}



int main () {
    // int a = 0;
    // // Pointer
    // int *p;
    // // Pointer pointer
    // int **pp;
    // p = &a;
    // pp = &p;

    // printf("%d\n", &a);    
    // printf("%d\n", &p);    
    // printf("%d\n", *pp);    
    // printf("%d", **pp);    
    
    printHello();
    printf("%d\n", sum(1, 3));

    int first = 5;
    int second = 4;
    printf("%d", sumpoint(&first, &second));


    return 0;
}