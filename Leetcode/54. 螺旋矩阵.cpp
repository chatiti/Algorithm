#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = n - 1, t = 0, b = m - 1;
        while (l <= r && t <= b) {
            for (int i = l; l <= r && t <= b && i <= r; ++i) {
                res.push_back(matrix[t][i]);
            }
            t++;
            for (int i = t; l <= r && t <= b && i <= b; ++i) {
                res.push_back(matrix[i][r]);
            }
            r--;
            for (int i = r; l <= r && t <= b && i >= l; --i) {
                res.push_back(matrix[b][i]);
            }
            b--;
            for (int i = b; l <= r && t <= b && i >= t; --i) {
                res.push_back(matrix[i][l]);
            }
            l++;
        }

        return res;
    }
};