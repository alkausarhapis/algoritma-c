// #include <stdio.h>

// int main() {

//     int a;
//     scanf("%d", &a);
//     // Loop vertical
//     for (int i = 0; i <= a; i++)
//     {
//         // Loop horizontal
//         for (int j = 0; j <= a; j++)
//         {
//             // Write bintang dengan kondisi tengah kosong
//             if (i == 0 || j == 0 || i == a || j == a)
//             {
//                 // printf("%d", i); 

//                 printf("*"); 
//             } else {
//                 printf(" ");
//             }
            
//         }
        
//         printf("\n");
//     }
    

//     return 0;
// }

// Segitiga
#include <stdio.h>

int main() {
    int a;

    printf("Enter the number of rows: ");
    scanf("%d", &a);

    for (int i = 1; i <= a; i++) {
        // Print spaces before the dots
        for (int j = 1; j <= a - i; j++) {
            printf(" ");
        }

        // Print dots for this row
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf(".");
        }

        printf("\n");
    }

    return 0;
}

// // Bulet
// #include <stdio.h>
// #include <math.h>

// int main() {
//     int radius;

//     printf("Enter the radius of the circle: ");
//     scanf("%d", &radius);

//     // Determine the dimensions of the output grid
//     int width = 2 * radius + 1;
//     int height = radius + 1;

//     // Iterate through each row
//     for (int y = -radius; y <= radius; y++) {
//         // Iterate through each column
//         for (int x = -radius; x <= radius; x++) {
//             // Check if the current point is within the circle's radius
//             if (x * x + y * y <= radius * radius) {
//                 printf(".");
//             } else {
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }
