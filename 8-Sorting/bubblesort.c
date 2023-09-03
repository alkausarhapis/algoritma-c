#include <stdio.h>
#include <stdbool.h>

int arr[] = {9, 4, 6, 1, 5, 8, 3, 7, 2};
int length = sizeof(arr) / sizeof(arr[0]);

void bubbleSortAsc() {
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // Masukin arr[j] ke temp
                int temp = arr[j]; // temp = 9
                // ubah value arr[j] jadi value pada arr[j+1] 
                arr[j] = arr[j+1]; // arr[0] = 4
                // masukin arr yang di temp ke arr[j+1] yang kosong
                arr[j+1] = temp; // arr[1] = 9
            }
        }
    }
}

void bubbleSortDesc() {
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;        
            }
        }
    }
}

void print() {
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    
}

int main() {
    bubbleSortAsc();
    print();
    bubbleSortDesc();
    print();
    return 0;
}
