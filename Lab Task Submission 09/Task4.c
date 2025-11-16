#include <stdio.h>

void searchElement( int rows, int cols, int arr[][cols], int target) {
    int found = 0;
    int *p = &arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*( p + (i * cols + j) ) == target) {
                printf("Element %d found at Row = %d, Column = %d\n", target, i+1, j+1);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}
int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    printf("Enter array elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", (*(arr + i) + j));
        }
    }
    int target;
    printf("Enter element to search: ");
    scanf("%d", &target);

    searchElement( rows, cols, arr, target);

    return 0;
}
