#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize all slots to -1 (empty)
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using linear probing
void insert(int key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Hash table is full!\n");
            return;
        }
    }
    hashTable[index] = key;
}

// Search key
int search(int key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;
        index = (index + 1) % SIZE;
        if (index == start)
            return -1;
    }
    return -1;
}

// Display table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d] -> %d\n", i, hashTable[i]);
}

// Main
int main() {
    int choice, key, pos;
    init();

    do {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                pos = search(key);
                if (pos != -1)
                    printf("Key %d found at index %d\n", key, pos);
                else
                    printf("Key %d not found!\n", key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
