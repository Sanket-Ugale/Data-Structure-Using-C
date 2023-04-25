#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int n;                      // number of items
int w[MAX_SIZE], v[MAX_SIZE];  // weight and value of each item
int W;                      // maximum weight of the knapsack
int dp[MAX_SIZE + 1][MAX_SIZE + 1];  // dynamic programming table

// Function to calculate the maximum value that can be obtained
int knapsack() {
    // Fill the dynamic programming table using bottom-up approach
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (w[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = (v[i - 1] + dp[i - 1][j - w[i - 1]]) > dp[i - 1][j] ? 
                    (v[i - 1] + dp[i - 1][j - w[i - 1]]) : dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    // Read input
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &W);
    // Calculate the maximum value that can be obtained
    int max_value = knapsack();
    // Print the result
    printf("The maximum value that can be obtained is %d\n", max_value);
    return 0;
}
