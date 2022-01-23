#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> uMap;
        for (int i = 0; i < nums.size(); ++i) {
            int scndNum = target - nums[i];
            if (uMap.find(scndNum) != uMap.end()) {
                return {uMap[scndNum], i};
            }
            uMap[nums[i]] = i;
        }
        // no results found
        return {-1, - 1};
    }
};

bool testSolution(vector<int> nums, int target, vector<int> expected) {
    Solution solution;
    return solution.twoSum(nums, target) == expected;
}

int main() {
    assert(testSolution({2, 7, 11, 15}, 9, {0, 1}));
    assert(testSolution({3, 2, 4, 6}, 6, {1, 2}));
    assert(testSolution({3, 3}, 6, {0, 1}));
    return 0;
}