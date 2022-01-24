#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        return  (nums.size() ) * (nums.size() + 1) / 2 - sum;
    }
};

bool testSolution(vector<int> nums, int result) {
    Solution solution;
    return solution.missingNumber(nums) == result;
}

int main() {
    assert(testSolution({3,0,1}, 2));
    assert(testSolution({0,1}, 2));
    assert(testSolution({9,6,4,2,3,5,7,0,1}, 8));
    return 0;
}