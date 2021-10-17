#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        /* code */
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertSortedArr(int arr[], int size, int capacity, int element)
{
    int index = 0;
    for (int i = size - 1; arr[i] >= element; i--)
    {
        arr[i + 1] = arr[i];
        index = i;
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {4, 7, 6, 88, 99};
    int size = 5;
    int capacity = 100;
    int element = 77;
    insertSortedArr(arr, size, capacity, element);
    size += 1;
    display(arr, size);
}