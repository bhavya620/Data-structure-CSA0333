#include <stdio.h>

// Function to print part of the array
void printPart(int arr[], int start, int end) {
    printf("[");
    for (int i = start; i <= end; i++) {
        printf("%d", arr[i]);
        if (i < end)
            printf(", ");
    }
    printf("]");
}

// Merge two sorted parts
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    printf("Merging: ");
    printPart(arr, l, r);
    printf("\n");
}

// Merge Sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        printf("Dividing: ");
        printPart(arr, l, m);
        printf(" and ");
        printPart(arr, m + 1, r);
        printf("\n");

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to print full array
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

// Main function
int main() {
    int arr[] = {5, 3, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted: ");
    printArray(arr, n);

    return 0;
}
