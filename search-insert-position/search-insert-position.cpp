#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right);
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

bool testSolution(vector<int> nums, int target, int result) {
    Solution solution;
    return solution.searchInsert(nums, target) == result;
}

int main() {
    assert(testSolution({1, 3, 5, 6}, 5, 2));
    assert(testSolution({1, 3, 5, 6}, 2, 1));
    assert(testSolution({1, 3, 5, 6}, 7, 4));
}