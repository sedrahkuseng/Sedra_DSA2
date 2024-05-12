#include <iostream>
#include <vector>
#include <algorithm>

// Function to check if it is possible to allocate books such that the maximum pages is maxPages
bool isPossible(std::vector<int>& books, int students, int maxPages) {
    int cnt = 1;
    int totalPages = 0;

    for (int pages : books) {
        if (pages > maxPages) return false; // If a single book has more pages than maxPages, return false
        if (totalPages + pages > maxPages) {
            cnt++; // Need one more student
            totalPages = pages; // This book becomes the first book for the new student
            if (cnt > students) return false; // More students needed than available
        }
        else {
            totalPages += pages;
        }
    }
    return true;
}

int findPages(std::vector<int>& books, int students) {
    if (books.size() < students) return -1; // Not enough books to distribute
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(books, students, mid)) {
            result = mid; // Found a possible solution, try for a better (smaller) answer
            high = mid - 1;
        }
        else {
            low = mid + 1; // Not possible to allocate with mid as max pages, need more pages
        }
    }
    return result;
}

int main() {
    std::vector<int> books = { 12, 34, 67, 90 }; // Example: Book pages
    int students = 2; // Number of students
    std::cout << "Minimum maximum pages: " << findPages(books, students) << std::endl;
    return 0;
}
