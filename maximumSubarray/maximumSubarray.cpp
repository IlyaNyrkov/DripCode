#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> subSums(nums);
        for (int i = 1; i < subSums.size(); ++i) {
            subSums[i] += subSums[i - 1];
        }
        int maxInd = 0;
        int minInd = 0;
        for (int i = 0; i < subSums.size(); ++i) {
            if (subSums[i] > subSums[maxInd]) {
                maxInd = i;
            }
            if (subSums[i] < subSums[minInd]) {
                minInd = i;
            }
        }
        int result = subSums[maxInd];
        if ((result < result - subSums[minInd]) && minInd != maxInd) {
            result -= subSums[minInd];
        }
        return result;
    }
};

int main() {

    return 0;
}