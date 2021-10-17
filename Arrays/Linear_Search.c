#include <stdio.h>
int LinearSearch(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 8, 55, 4, 2, 123, 75};
    int element = 55;
    int size = sizeof(arr) / sizeof(int);
    int indexSearch = LinearSearch(arr, size, element);
    if (indexSearch == -1)
        printf("The element %d was not found  \n", element);
    else
        printf("The element %d was found at index %d \n", element, indexSearch);
    return 0;
}