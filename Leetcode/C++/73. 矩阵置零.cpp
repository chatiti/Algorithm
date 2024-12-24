#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool row[n];
        bool col[m];
        for (int i = 0; i < n; ++i) {
            row[i] = false;
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            col[i] = false;
            for (int j = 0; j < n; ++j) {
                if (matrix[j][i] == 0) {
                    col[i] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (row[i]) {
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }
        for(int i = 0; i < m; ++i){
            if (col[i]) {
                for (int j = 0; j < n; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};