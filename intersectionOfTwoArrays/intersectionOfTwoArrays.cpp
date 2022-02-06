#include <assert.h>
#include <vector>
#include <unordered_set>

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_set = {begin(nums1), end(nums1)};
        unordered_set<int> nums2_set = {begin(nums2), end(nums2)};
        vector<int> result;
        for (const auto& elem : nums1_set) {
            if (nums2_set.find(elem) != nums2_set.end()) {
                result.push_back(elem);
            }
        }
        return result;
    }
};

bool testSolution(vector<int> nums1, vector<int> nums2, vector<int> expected) {
    Solution solution;
    return solution.intersection(nums1, nums2) == expected;
}

int main() {
    assert(testSolution({1, 2, 2, 1}, {2, 2}, {2}));
    assert(testSolution({4, 9, 5}, {9,4,9,8,4}, {9, 4}));
    return 0;
}