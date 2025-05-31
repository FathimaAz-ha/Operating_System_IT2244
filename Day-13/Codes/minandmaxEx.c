/*Write a C program that:
Accepts an array of integers from the user.
Finds and displays the maximum and minimum values in the array.*/ 

#include <stdio.h>

int main() {
    int arr[100], n, i, max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    max = min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    return 0;
}