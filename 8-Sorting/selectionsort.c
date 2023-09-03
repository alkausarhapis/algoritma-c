#include <stdio.h>

int arr[] = {9, 4, 6, 1, 5, 8, 3, 7, 2};
int length = sizeof(arr) / sizeof(arr[0]);

void selectionSortAsc() {
    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        // pindahkan array[i] ke temp
        int temp = arr[i]; // temp = 9 
        // array[i] yang kosong isi array[min]
        arr[i]=arr[min]; // arr[0]=1
        // array[min] yang kosong isi value yg di temp
        arr[min] = temp; //arr[3] = 9
    }
}

void selectionSortDesc() {
    for (int i = 0; i < length - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }

        int temp = arr[i];
        arr[i]=arr[max];
        arr[max] = temp;
    }
}

void print() {
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    
}

int main () {
    selectionSortAsc();
    print();
    selectionSortDesc();
    print();

    return 0;
}