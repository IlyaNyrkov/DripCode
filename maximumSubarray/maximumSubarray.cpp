#include <vector>
#include <climits>
#include <assert.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int result = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum < nums[i]) {
                sum = nums[i];
            }
            if (result < sum) {
                result = sum;
            }
        }
        return result;
    }
};

bool testSolution(vector<int> input, int result) {
    vector<int> arr_copy(input);
    Solution solution;
    return solution.maxSubArray(arr_copy) == result;
}

int main() {
    assert(testSolution({-2,1,-3,4,-1,2,1,-5,4}, 6));
    assert(testSolution({1}, 1));
    assert(testSolution({5,4,-1,7,8}, 23));
    assert(testSolution({-1, 0}, 0));
    return 0;
}