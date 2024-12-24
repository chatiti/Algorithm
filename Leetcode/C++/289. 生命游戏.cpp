#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int n = board.size();
        int m = board[0].size();
        int temp[n][m];
        int x[] = {-1, 0, 1};
        int y[] = {-1, 0, 1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int count = 0;
                for (auto xx: x) {
                    for (auto yy: y) {
                        int nx = i + xx;
                        int ny = j + yy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if ((nx != i || ny != j) && board[nx][ny] == 1) {
                                count++;
                            }
                        }
                    }
                }
                if (count < 2) {
                    temp[i][j] = 0;
                } else if (count == 3) {
                    temp[i][j] = 1;

                } else if (count > 3) {
                    temp[i][j] = 0;
                } else {
                    temp[i][j] = 1;
                    if (board[i][j] == 0) {
                        temp[i][j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board[i][j] = temp[i][j];
            }
        }
    }

};