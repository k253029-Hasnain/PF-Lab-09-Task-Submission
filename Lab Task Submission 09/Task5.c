#include <stdio.h>

void printData(void *ptr, char type) {
    if (type == 'i') {
        printf("Integer: %d\n", *(int *)ptr);
    }
    else if (type == 'f') {
        printf("Float: %.2f\n", *(float *)ptr);
    }
    else if (type == 'c') {
        printf("Character: %c\n", *(char *)ptr);
    }
    else {
        printf("Invalid type code!\n");
    }
}
int main() {
    int productID;
    float price;
    char category;

    printf("Enter Product ID (int): ");
    scanf("%d", &productID);

    printf("Enter Price (float): ");
    scanf("%f", &price);

    printf("Enter Category Code (char): ");
    scanf(" %c", &category);

    printf("\n--- Output ---\n");

    printData(&productID, 'i');
    printData(&price, 'f');
    printData(&category, 'c');

    return 0;
}
