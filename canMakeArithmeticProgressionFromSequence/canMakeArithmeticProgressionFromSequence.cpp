#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int prev = arr[1];
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i) {
            if (diff != arr[i] - prev) {
                return false;
            }
            prev = arr[i];
        }
        return true;
    }
};

bool testSolution(vector<int> arr, bool result) {
    Solution solution;
    vector<int> arr_copy = arr;
    return solution.canMakeArithmeticProgression(arr_copy) == result;
}

int main() {
    assert(testSolution({-68, -96, -12, -40, 16}, true));
    assert(testSolution({3, 5, 1}, true));
    assert(testSolution({1, 2, 4}, false));
    return 0;
}