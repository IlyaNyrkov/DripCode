#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = i + 1; j < cols; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        size_t cols = matrix[0].size();
        size_t rows = matrix.size();
        for (int i = 0; i < cols / 2; ++i) {
            for (int j = 0; j < rows; ++j) {
                swap(matrix[j][i], matrix[j][cols - i - 1]);
            }
        }
    }
};

bool testSolution(vector<vector<int>> matrix, vector<vector<int>> expected) {
    vector<vector<int>> matrix_copy(matrix);
    Solution solution;
    solution.rotate(matrix_copy);
    return matrix_copy == expected;

}

int main() {
    assert(testSolution({{1, 2}, {3, 4}}, {{3, 1}, {4, 2}}));
    assert(testSolution({{1,2,3}, {4,5,6}, {7,8,9}}, {{7,4,1}, {8,5,2}, {9, 6, 3}}));
    assert(testSolution({{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
                        {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}));
    return 0;
}