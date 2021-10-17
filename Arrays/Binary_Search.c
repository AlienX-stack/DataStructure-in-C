#include <stdio.h>

int Binary_Search(int arr[], int n, int element)
{
    int low = 0, mid = 0, high = n - 1;
    // Start Searching
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
            return mid;

        if (arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // Searching Ends
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 8, 55, 123, 225, 444};
    int element = 55;
    int size = sizeof(arr) / sizeof(int);
    int indexSearch = Binary_Search(arr, size, element);
    if (indexSearch == -1)
        printf("The element %d was not found  \n", element);
    else
        printf("The element %d was found at index %d \n", element, indexSearch);
    return 0;
}