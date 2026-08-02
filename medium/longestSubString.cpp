#include <iostream>
#include <string>

using namespace std;

int lenghtOfLongestSubString(string s) {


    int longest = 0;
    for (int i = 0; i < (int)s.size(); i++) {

        string res = "";
        for (int j = i; j < (int)s.size(); j++) {
            if (res.contains(s[j])) break;

            res += s[j];
        }
        if ((int)res.size() > longest) {
            longest = res.size();
        }

    }


    return longest;
}

typedef struct {
    string input;
    int expected;
} TestCase;

int main() {

    TestCase tests[] = {
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
        {"S", 1},
        {"mq", 2},
    };

    int testsLength = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < testsLength; i++) {
        int res = lenghtOfLongestSubString(tests[i].input);
        if (res != tests[i].expected) {
            cout << "\x1b[1;31mTest Failed\x1b[0m\n";
            cout << "Input: " << tests[i].input << "\n";
            cout << "Got: " << res << "\n";
            cout << "Expected: " << tests[i].expected << "\n";
        } else {
            cout << "\x1b[1;32mTest Passed\x1b[0m\n";
        }
    }


    return 0;
}
