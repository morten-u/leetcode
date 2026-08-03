#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    vector<int> merged = vector<int>();

    int a = 0;
    int b = 0;

    while (a < (int)nums1.size() && b < (int)nums2.size()) {

        if (nums1[a] < nums2[b]) {
            merged.push_back(nums1[a]);
            a++;
        } else {
            merged.push_back(nums2[b]);
            b++;
        }
    }

    while (a < (int)nums1.size()) {
        merged.push_back(nums1[a]);
        a++;
    }

    while (b < (int)nums2.size()) {
        merged.push_back(nums2[b]);
        b++;
    }

    double median = 0;
    if (merged.size() % 2 == 0) {
        int high = merged.size() / 2;
        int low = high - 1;

        median = (merged[high] + merged[low]) / 2.0;
    } else {
        median = merged[merged.size() / 2];
    }
    return median;
}

typedef struct TestCase{
    vector<int> nums1;
    vector<int> nums2;
    double expected;
} TestCase;

int main() {

    TestCase tests[] = {
      {{1, 3}, {2}, 2.00000},
      {{1, 2}, {3, 4}, 2.50000},
    };


    int index = 0;
    for (auto test : tests) {
        double res = findMedianSortedArrays(test.nums1, test.nums2);

        if (res != test.expected) {
            cout << "\x1b[1;31mTest Failed\x1b[0m\n";
            cout << "test #" << index << "\n";
            cout << "Got: " << res << "\n";
            cout << "Want: " << test.expected << "\n";
        } else {
            cout << "\x1b[1;32mTest Passed\x1b[0m\n";
        }
        index++;
    }

    return 0;
}
