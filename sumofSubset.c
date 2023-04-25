#include <stdio.h>

#define MAX_SIZE 100

int n;                  // number of elements
int a[MAX_SIZE];        // array of elements
int target_sum;         // target sum
int sum_so_far = 0;     // current sum
int include[MAX_SIZE];  // array to track which elements are included in the current subset

// Recursive function to find all subsets that sum up to the target sum
void sum_of_subset(int i) {
    if (sum_so_far == target_sum) {
        printf("{ ");
        for (int j = 0; j < n; j++) {
            if (include[j] == 1) {
                printf("%d ", a[j]);
            }
        }
        printf("}\n");
        return;
    }
    if (i == n || sum_so_far > target_sum) {
        return;
    }
    include[i] = 1;
    sum_so_far += a[i];
    sum_of_subset(i + 1);
    sum_so_far -= a[i];
    include[i] = 0;
    sum_of_subset(i + 1);
}

int main() {
    // Read input
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target_sum);
    // Find all subsets that sum up to the target sum
    sum_of_subset(0);
    return 0;
}
