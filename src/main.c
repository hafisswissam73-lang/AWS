#include <stdio.h>

int main() {
    int choice;

    printf("===== DATABASE SYSTEM =====\n");
    printf("1. B-Tree\n");
    printf("2. LSM Tree\n");
    printf("3. Exit\n");

    printf("Choose your option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("B-Tree selected!\n");
            break;

        case 2:
            printf("LSM Tree selected!\n");
            break;

        case 3:
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
