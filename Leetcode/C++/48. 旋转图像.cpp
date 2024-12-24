#include <bits/stdc++.h>

using namespace std;

//方法1：翻转前x,y->翻转后y,n-x-1
//方法2：先对角线翻转，再每行翻转

//class Solution {
//public:
//    void rotate(vector<vector<int>> &matrix) {
//        int n = matrix.size();
//        bool visit[n][n];
//        memset(visit, 0, sizeof visit);
//
//        int temp;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                int x = i, y = j;
//                temp = matrix[x][y];
//                while (!visit[y][n - x - 1]) {
//                    visit[y][n - x - 1] = true;
//                    swap(temp, matrix[y][n - x - 1]);
//                    int tt = x;
//                    x = y;
//                    y = n - tt - 1;
//                }
//            }
//        }
//    }
//};


class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        // 对角线交换
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 每行翻转
        for (auto &row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};