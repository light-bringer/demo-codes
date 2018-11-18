/*
c program to search and create another array
*/
#include <stdio.h>

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

int main(void)
{
    int barr[100];
    int arr[] = {2, 3, 4, 10, 40, 21, 25, 34, 23, 12, 1, 2 , 3, 4, 5, 6};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int counter = 1;
    int incrementer  = 0;
    for (counter=1; counter<=100; counter++ ) {
        int result;
        result = binarySearch(arr, 0, n-1, counter);
        if(result == -1) {
            printf("Element is not present in array\n");
            barr[incrementer] = counter;
            incrementer++;
        }
        else {
            printf("Element is present at index %d\n", result);
            continue;

        }

    }

    int i=0;
        printf("new array!\n");
        for(i=0; i< incrementer; i++) {
            printf("%d   ", barr[i]);
        }

    return 0;
}
