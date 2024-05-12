#include <iostream>
#include <vector>
#include <algorithm>

struct Pair {
    int first, second;
};

// Comparator to sort pairs based on the first element
bool comparePairs(const Pair& p1, const Pair& p2) {
    return p1.first < p2.first;
}

// Function to find the maximum length of chain using dynamic programming
int maxChainLenDP(std::vector<Pair>& pairs) {
    int n = pairs.size();
    // Sort pairs based on the first element
    std::sort(pairs.begin(), pairs.end(), comparePairs);

    // DP array to store the maximum chain length ending with pairs[i]
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If this pair can follow the pair j
            if (pairs[i].first > pairs[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Find the maximum value in dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    std::vector<Pair> pairs = { {5, 24}, {15, 28}, {27, 40}, {50, 60}, {39, 45} };
    std::cout << "The maximum length of chain using DP is " << maxChainLenDP(pairs) << std::endl;
    return 0;
}
