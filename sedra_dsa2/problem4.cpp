#include <iostream>
#include <vector>
#include <algorithm>

struct Pair {
    int first, second;
};

// Comparator to sort pairs based on the second element
bool comparePairs(const Pair& p1, const Pair& p2) {
    return p1.second < p2.second;
}

// Function to find the maximum length of chain
int maxChainLen(std::vector<Pair>& pairs) {
    // Sort pairs based on the second element
    std::sort(pairs.begin(), pairs.end(), comparePairs);

    int count = 1; // Start with the first pair
    Pair last = pairs[0]; // Start chaining with the first pair

    for (int i = 1; i < pairs.size(); i++) {
        // If the current pair can follow the last pair in the chain
        if (pairs[i].first > last.second) {
            last = pairs[i]; // Update the last element to current
            count++; // Increase the count of pairs in the chain
        }
    }

    return count;
}

int main() {
    std::vector<Pair> pairs = { {5, 24}, {15, 28}, {27, 40}, {50, 60}, {39, 45} };
    std::cout << "The maximum length of chain is " << maxChainLen(pairs) << std::endl;
    return 0;
}
