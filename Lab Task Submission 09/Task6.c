#include <stdio.h>

void takeAttendance(int rows, int cols, int arr[][cols]) {
    printf("Enter attendance (1 = Present, 0 = Absent):\n");
    for (int i = 0; i < rows; i++) {
        printf("Student %d:\n", i + 1);
        for (int j = 0; j < cols; j++) {
            printf("  Class %d: ", j + 1);
            scanf("%d", (*(arr + i) + j));
        }
    }
}
void calculatePercentage(int rows, int cols, int arr[][cols]) {
    printf("\n--- Attendance Report ---\n");
    for (int i = 0; i < rows; i++) {
        int present = 0;
        for (int j = 0; j < cols; j++) {
            if (*(*(arr + i) + j) == 1) {
                present++;
            }
        }

        float percentage = (present * 100.0f) / cols;
        printf("Student %d: %.2f%% attendance", i + 1, percentage);

        if (percentage < 75.0f) {
            printf("  --> WARNING: Below 75%%");
        }
        printf("\n");
    }
}
int main() {
    int rows = 4, cols = 5;
    int attendance[4][5];

    takeAttendance(rows, cols, attendance);
    calculatePercentage(rows, cols, attendance);

    return 0;
}
