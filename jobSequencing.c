#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int profit;
    int deadline;
} job;

int cmp(const void *a, const void *b) {
    job *ia = (job *) a;
    job *ib = (job *) b;
    return ib->profit - ia->profit;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int jobSequencing(job jobs[], int n) {
    qsort(jobs, n, sizeof(job), cmp);
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        max_deadline = max(max_deadline, jobs[i].deadline);
    }
    int *slot = (int *) calloc(max_deadline, sizeof(int));
    int max_profit = 0;
    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline - 1;
        while (deadline >= 0 && slot[deadline])
            deadline--;
        if (deadline >= 0) {
            slot[deadline] = 1;
            max_profit += jobs[i].profit;
        }
    }
    free(slot);
    return max_profit;
}

int main() {
    job jobs[] = {{1, 35, 3}, {2, 30, 4}, {3, 25, 4}, {4, 20, 2}, {5, 15, 3}, {6, 12, 1}, {7, 5, 2}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    int max_profit = jobSequencing(jobs, n);
    printf("Maximum profit = %d\n", max_profit);
    return 0;
}
