#include <iostream>
#include <vector>

int countSpecialSequences(int m, int n) {
    // dp[i][j] will be the count of sequences of length i that end with the number j
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    // Initialize for sequences of length 1
    for (int j = 1; j <= m; ++j) {
        dp[1][j] = 1;  // There's exactly one sequence of length 1 that ends with j
    }

    // Fill the dp table
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= j / 2; ++k) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    // Sum up all sequences of length n
    int totalSequences = 0;
    for (int j = 1; j <= m; ++j) {
        totalSequences += dp[n][j];
    }

    return totalSequences;
}

int main() {
    int m = 10, n = 4;
    std::cout << "Total number of special sequences: " << countSpecialSequences(m, n) << std::endl;
    return 0;
}
