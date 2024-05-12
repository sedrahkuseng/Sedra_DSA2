#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Meeting {
    int start;
    int end;
};

bool compare(Meeting m1, Meeting m2) {
    if (m1.end == m2.end)
        return m1.start < m2.start;
    return m1.end < m2.end;
}

int maxMeetings(vector<int>& start, vector<int>& end, int N) {
    vector<Meeting> meetings(N);

    // Create meetings
    for (int i = 0; i < N; ++i) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    // Sort meetings by end time
    sort(meetings.begin(), meetings.end(), compare);

    int count = 0;
    int last_end_time = 0;

    // Select meetings
    for (auto& meeting : meetings) {
        if (meeting.start > last_end_time) {
            last_end_time = meeting.end;
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> start = { 10, 12, 20 };
    vector<int> end = { 20, 25, 30 };
    int N = 3;

    cout << "Maximum number of meetings: " << maxMeetings(start, end, N) << endl;
    return 0;
}
