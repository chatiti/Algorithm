#include <bits/stdc++.h>

using namespace std;

class neighborSum {
public:
    vector<vector<int>> &g;
    int n;
    map<int, vector<int>> m;
    vector<vector<int>> d{{-1, -1},
                          {1,  1},
                          {-1, 1},
                          {1,  -1}};
    vector<vector<int>> a{{1,  0},
                          {-1, 0},
                          {0,  1},
                          {0,  -1}};

    neighborSum(vector<vector<int>> &grid) : g(grid), n(grid.size()) {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                m[grid[i][j]] = vector<int>{i, j};
            }
        }
    }

    int adjacentSum(int value) {
        int x = m[value][0];
        int y = m[value][1];
        int sum = 0;
        for (auto it: a) {
            if (x + it[0] >= 0 && x + it[0] < n && y + it[1] >= 0 && y + it[1] < n) {
                sum += g[x + it[0]][y + it[1]];
            }
        }
        return sum;
    }

    int diagonalSum(int value) {
        int x = m[value][0];
        int y = m[value][1];
        int sum = 0;
        for (auto it: d) {
            if (x + it[0] >= 0 && x + it[0] < n && y + it[1] >= 0 && y + it[1] < n) {
                sum += g[x + it[0]][y + it[1]];
            }
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */