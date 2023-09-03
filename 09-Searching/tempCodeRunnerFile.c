#include <stdio.h>

int arr[] = {34, 12, 76, 43, 89, 5, 63, 18, 7, 99,
            50, 29, 83, 61, 42, 13, 77, 22, 8, 55,
            91, 3, 47, 68, 17, 38, 80, 25, 64, 1,
            88, 52, 39, 70, 19, 59, 96, 31, 71, 11};

int length = sizeof(arr) / sizeof(arr[0]);

void bubbleSortAsc() {
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarySearch(int search) {
    // bubbleSortAsc();

    int low = 0;
    int high = length - 1;

    while (low <= high)
    {
        int mid = (low+high/2);
        if (arr[mid] == search)
        {
            return mid;
        } else if (search < arr[mid])
        {
            high = mid-1;
        } else if (search > arr[mid])
        {
            low = mid + 1;
        }    
    } 
    
    return -1;
}

void print() {
    for (int i = 0; i < length; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int main () {
    int searchInput;

    bubbleSortAsc();
    print();

    printf("Masukkan angka yang ingin dicari : ");
    scanf("%d", &searchInput);
    int searchReturn = binarySearch(searchInput);

    if (searchReturn == -1)
    {
        printf("Nilai tidak ditemukan");
    } else {
        printf("Angka %d berada di index ke %d", searchInput, searchReturn);
    }
    

    return 0;
}