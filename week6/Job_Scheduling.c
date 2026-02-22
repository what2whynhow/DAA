// CH.SC.U4CSE24113
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    int deadline;
    int profit;
} Job;
void jobScheduling(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    int *result = (int *)malloc(maxDeadline * sizeof(int));
    int *slot = (int *)malloc(maxDeadline * sizeof(int));
    int totalProfit = 0;
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = i;
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("\nJob Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) {
            printf("%d ", jobs[result[i]].id);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
    free(result);
    free(slot);
}
int main() {
    printf("CH.SC.U4CSE24150\n");
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        printf("Enter profit and deadline for Job %d: ", jobs[i].id);
        scanf("%d %d", &jobs[i].profit, &jobs[i].deadline);
    }
    jobScheduling(jobs, n);
    return 0;
}
