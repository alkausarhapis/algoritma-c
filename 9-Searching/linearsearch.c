#include <stdio.h>

int arr[] = {34, 12, 76, 43, 89, 5, 63, 18, 7, 99,
            50, 29, 83, 61, 42, 13, 77, 22, 8, 55,
            91, 3, 47, 68, 17, 38, 80, 25, 64, 1,
            88, 52, 39, 70, 19, 59, 96, 31, 71, 11};

int length = sizeof(arr) / sizeof(arr[0]);

int linearSearch(int search) {
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }
    
    return -1;
}

int main () {
    int searchInput;
    scanf("%d", &searchInput);
    int searchReturn = linearSearch(searchInput);

    if (searchReturn == -1)
    {
        printf("Nilai tidak ditemukan");
    } else {
        printf("%d", searchReturn);
    }
    

    return 0;
}