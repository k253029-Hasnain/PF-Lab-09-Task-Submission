#include <stdio.h>

void inputRuns(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Player %d runs: ", i + 1);
        scanf("%d", arr + i);
    }
}
int totalRuns(int *arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}
float averageRuns(int total, int size) {
    return (float)total / size;
}
void highestScorer(int *arr, int size, int *max, int *index) {
    *max = *arr;
    *index = 0;
    for(int i = 1; i < size; i++) {
        if(*(arr + i) > *max) {
            *max = *(arr + i);
            *index = i;
        }
    }
}
int main() {
    int runs[11];
    int total, maxScore, index;
    float avg;

    printf("Enter runs scored by 11 players:\n");
    inputRuns(runs, 11);

    total = totalRuns(runs, 11);
    avg = averageRuns(total, 11);
    highestScorer(runs, 11, &maxScore, &index);

    printf("\n--- Match Summary ---\n");
    printf("Total Runs: %d\n", total);
    printf("Average Runs: %.2f\n", avg);
    printf("Highest Scorer: Player %d\n", index + 1);
    printf("Highest Score: %d\n", maxScore);

    return 0;
}