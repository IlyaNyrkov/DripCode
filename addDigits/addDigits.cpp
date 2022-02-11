#include <assert.h>
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        if (num % 9 == 0) {
            return 9;
        }
        return num % 9;
    }
};

bool testSolution(int input, int expected) {
    Solution solution;
    return solution.addDigits(input) == expected;
}

int main() {
    assert(testSolution(38, 2));
    assert(testSolution(0, 0));
    return 0;
}