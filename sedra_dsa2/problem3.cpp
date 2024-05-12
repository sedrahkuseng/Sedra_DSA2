#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int start, end, profit;
};

bool jobComparator(Job s1, Job s2) {
    return (s1.end < s2.end);
}

int binarySearch(std::vector<Job>& jobs, int index) {
    int lo = 0, hi = index - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (jobs[mid].end <= jobs[index].start) {
            if (jobs[mid + 1].end <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else {
            hi = mid - 1;
        }
    }
    return -1;
}

int jobScheduling(std::vector<Job>& jobs) {
    std::sort(jobs.begin(), jobs.end(), jobComparator);
    int n = jobs.size();
    std::vector<int> dp(n);
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int inclProf = jobs[i].profit;
        int l = binarySearch(jobs, i);
        if (l != -1) inclProf += dp[l];
        dp[i] = std::max(inclProf, dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    std::vector<Job> jobs = { {3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200} };
    std::cout << "Optimal profit is " << jobScheduling(jobs) << std::endl;
    return 0;
}
