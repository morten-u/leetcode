#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {

    for (int i = 0; i < (int)nums.size(); i++) {
        for (int j = i + 1; j < (int)nums.size(); j++) {

            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {};
}

typedef struct {
    vector<int> nums;
    int target;
    vector<int> expected;
} TestCase;

int main() {

    TestCase tests[] = {
        // Nums             target      Expected
      {{2, 7, 11, 15},      9,          {0, 1}},
      {{3, 2, 4},           6,          {1, 2}},
      {{3, 3},              6,          {0, 1}},
    };

    for (auto test : tests) {
        vector<int> result = twoSum(test.nums, test.target);

        if (result != test.expected) {
            cout << "\x1b[1;31mTest Failed\x1b[0m\n";
            cout << "Got: ";
            for (auto i : result) {
                cout << i << " ";
            }
            cout << "\nExpected: ";
            for (auto i : test.expected) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            cout << "\x1b[1;32mTest Passed!\x1b[0m\n";
        }
    }

    return 0;
}
