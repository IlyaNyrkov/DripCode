#include <assert.h>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_to_count;
        for (int i = 0; i < s.size(); ++i) {
            char_to_count[s[i]]++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (char_to_count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

bool testSolution(string input, int expected) {
    Solution solution;
    return solution.firstUniqChar(input) == expected;
}

int main() {
    assert(testSolution("aabb", -1));
    assert(testSolution("leetcode", 0));
    assert(testSolution("loveleetcode", 2));
    return 0;
}