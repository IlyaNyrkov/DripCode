#include <vector>
#include <assert.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNumber = 0;
        for (int i = 0; i < nums.size(); ++i) {
            singleNumber ^= nums[i];
        }
        return singleNumber;
    }
};

bool testSolution(vector<int> nums, int result) {
    Solution solution;
    return solution.singleNumber(nums) == result;
}

int main() {
    assert(testSolution({4, 1, 2, 1, 2}, 4));
    assert(testSolution({2, 2, 1}, 1));
    assert(testSolution({1}, 1));
    return 0;
}