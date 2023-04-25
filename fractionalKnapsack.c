#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} item;

int cmp(const void *a, const void *b) {
    item *ia = (item *) a;
    item *ib = (item *) b;
    return (double) ib->value / ib->weight - (double) ia->value / ia->weight;
}

double fractionalKnapsack(item items[], int n, int capacity) {
    double max_value = 0;
    qsort(items, n, sizeof(item), cmp);
    for (int i = 0; i < n; i++) {
        if (capacity <= 0)
            return max_value;
        int weight = items[i].weight;
        int value = items[i].value;
        double fraction = (double) capacity / weight;
        if (fraction >= 1) {
            max_value += value;
            capacity -= weight;
        } else {
            max_value += fraction * value;
            capacity = 0;
        }
    }
    return max_value;
}

int main() {
    item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    double max_value = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in knapsack = %lf\n", max_value);
    return 0;
}
