#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int id, deadline, profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

std::pair<int, int> JobScheduling(std::vector<Job>& jobs, int n) {
    std::sort(jobs.begin(), jobs.end(), comparison);
    int maxProfit = 0, countJobs = 0;
    std::vector<bool> slot(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = std::min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                maxProfit += jobs[i].profit;
                countJobs++;
                slot[j] = true;
                break;
            }
        }
    }
    return { countJobs, maxProfit };
}

int main() {
    std::vector<Job> jobs = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15} };
    int n = jobs.size();
    std::pair<int, int> result = JobScheduling(jobs, n);
    std::cout << "Maximum number of jobs: " << result.first << std::endl;
    std::cout << "Maximum profit: " << result.second << std::endl;
    return 0;
}
