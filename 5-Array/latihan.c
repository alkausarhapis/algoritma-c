#include <stdio.h>
#include <string.h>


int main () {
    // ASCII
    printf("ASCII VALUE\n");
    printf("%d\n", 'a');
    printf("%d\n", 'z');
    printf("%d\n", 'A');
    printf("%d\n", 'Z');

    // Convert lowercase to uppercase using nested loop and ASCII
    char str[40];
    scanf("%[^\n]", str);
    getchar();

    int strlength = strlen(str);

    for (int i = 0; i < strlength ; i++)
    {
        // Check
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            // Substract the ASCII value of lowercase char
            str[i] -= 32;
        }
    }
        printf("%s", str); 
    
    // Convert lowercase to uppercase using function
    // char str[40];
    // scanf("%[^\n]", str);
    // getchar();
    
    // printf("%s", strupr(str)); 
    // printf("%s", strlwr(str)); 

    return 0;
}