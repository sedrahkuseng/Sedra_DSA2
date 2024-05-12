#include <iostream>
#include <vector>

int findKthElement(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    int index1 = 0, index2 = 0;

    while (true) {
        // Edge cases
        if (index1 == m) {
            return nums2[index2 + k - 1];
        }
        if (index2 == n) {
            return nums1[index1 + k - 1];
        }
        if (k == 1) {
            return std::min(nums1[index1], nums2[index2]);
        }

        // Normal cases
        int half = k / 2;
        int newIndex1 = std::min(index1 + half, m) - 1;
        int newIndex2 = std::min(index2 + half, n) - 1;
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];

        if (pivot1 <= pivot2) {
            k -= (newIndex1 - index1 + 1);
            index1 = newIndex1 + 1;
        }
        else {
            k -= (newIndex2 - index2 + 1);
            index2 = newIndex2 + 1;
        }
    }
}

int main() {
    std::vector<int> arr1 = { 2, 3, 6, 7, 9 };
    std::vector<int> arr2 = { 1, 4, 8, 10 };
    int k = 5;
    std::cout << "The " << k << "th element of the merged sorted array is: "
        << findKthElement(arr1, arr2, k) << std::endl;
    return 0;
}
