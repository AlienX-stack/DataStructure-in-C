#include <stdio.h>

void display(int arr[], int n)
{
    // Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index)
{

    int i = 0;
    for (i = 0; i < size; i++)
        if (arr[i] == element)
            break;
    if (i < size)
    {
        for (int j = i; i < size - 1; i++)
        {
            arr[j] = arr[j + 1];
        }
    }
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 12, index = 3;

    display(arr, size);

    indInsertion(arr, size, element, 100, index);
    size -= 1;

    display(arr, size);

    return 0;
}