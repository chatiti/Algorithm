#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int arr[10];
        int x[] = {0, 3, 6};
        int y[] = {0, 3, 6};

        for (int row = 0; row < 9; ++row) {
            memset(arr, 0, sizeof arr);
            for (int i = 0; i < 9; ++i) {
                char current = board[row][i];
                if (current != '.') {
                    if (arr[current - '0'] > 0) {
                        return false;
                    }
                    arr[current - '0']++;
                }
            }
        }


        for (int column = 0; column < 9; ++column) {
            memset(arr, 0, sizeof arr);
            for (int i = 0; i < 9; ++i) {
                char current = board[i][column];
                if (current != '.') {
                    if (arr[current - '0'] > 0) {
                        return false;
                    }
                    arr[current - '0']++;
                }
            }
        }


        for (auto sx: x) {
            for (auto sy: y) {
                memset(arr, 0, sizeof arr);
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char current = board[sx + i][sy + j];
                        if (current != '.') {
                            if (arr[current - '0'] > 0) {
                                return false;
                            }
                            arr[current - '0']++;
                        }
                    }
                }
            }
        }


        return true;
    }
};