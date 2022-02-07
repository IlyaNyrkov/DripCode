#include <assert.h>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (!st.empty() && (s[i] == ']' || s[i] == '}' || s[i] == ')')) {
                if ((st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '(' && s[i] == ')')) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return st.empty();
    }
};

bool testSolution(string paranthesesString, bool result) {
    Solution solution;
    return solution.isValid(paranthesesString) == result;
}

int main() {
    assert(testSolution("[[]]", true));
    assert(testSolution("{}[]()()", true));
    assert(testSolution("{()()[][]}", true));
    assert(testSolution("{)", false));
}

