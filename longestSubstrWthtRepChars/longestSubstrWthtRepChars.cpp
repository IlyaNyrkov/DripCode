#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // array of all ASCII character positions in given string
        int arr[127];
        for (int i = 0; i < 127; ++i) {
            arr[i] = -1;
        }
        // start of string
        int start = 0;
        // max character count in string
        int ans = 0;
        // current character count in string
        int counter = 0;
        for (int i = 0; i < s.size(); ++i) {
            int charIndex = s[i] - ' ';
            if (arr[charIndex] < start) {
                ans = max(ans, ++counter);
            } else {
                // if we find reoccuring of character we move starting point by one
                start = arr[charIndex] + 1;
                // since we moved starting point we need to change counter value
                // we substract indexes of second appearence of a character and first appearence
                // that way we can keep on moving with pointer i and not loosing counter
                //
                //  s,i             s  i                s  i
                //  |           ->  |  | counter = 3 ->  |  | counter = 3
                //  abcadcbba       abcadcbba          abcadcbba
                counter = i - arr[charIndex];
            }
            arr[charIndex] = i;
        }
        return ans;
    }
};

bool testSolution(string str, int result) {
    Solution solution;
    return solution.lengthOfLongestSubstring(str) == result;
}

int main() {
    assert(testSolution("abcabcbb", 3));
    assert(testSolution("bbbbb", 1));
    assert(testSolution("pwwkew", 3));
    return 0;
}