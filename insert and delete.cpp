#include <stdio.h>

#define MAX 100  // Maximum array size

int main() {
    int arr[MAX] = {1, 20, 40, 35};
    int n = 4, num, pos, i;

    // Insert a number
    printf("Enter number to insert: ");
    scanf("%d", &num);
    printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos >= 0 && pos <= n && n < MAX) {
        for (i = n; i > pos; i--) {
            arr[i] = arr[i - 1];  // Shift right
        }
        arr[pos] = num;
        n++;

        // Display array after insertion
        printf("Array after insertion: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Invalid position for insertion.\n");
    }

    // Delete a number
    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos >= 0 && pos < n) {
        for (i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];  // Shift left
        }
        n--;

        // Display array after deletion
        printf("Array after deletion: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Invalid position for deletion.\n");
    }

    return 0;
}
