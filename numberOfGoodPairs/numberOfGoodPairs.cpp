#include <unordered_map>
#include <assert.h>
#include <vector>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> nums_counter;
        for (int i = 0; i < nums.size(); ++i) {
            nums_counter[nums[i]]++;
        }
        int pairs_count = 0;
        for (const auto& key : nums_counter) {
            auto value = key.second;
            pairs_count += (value * (value - 1)) / 2;
        }
        return pairs_count;
    }
};

bool testSolution(vector<int> arr, int expected) {
     Solution solution;
     vector<int> arr_copy(arr);
    return solution.numIdenticalPairs(arr_copy) == expected;
}

int main() {
    assert(testSolution({1, 2, 3, 1, 1, 3}, 4));
    assert(testSolution({1, 1, 1, 1}, 6));
    assert(testSolution({1, 2, 3}, 0));
    return 0;
}