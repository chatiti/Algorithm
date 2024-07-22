#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int maximumDetonation(vector<vector<int>> &bombs) {
        int n = bombs.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));

        for (int i = 0; i < bombs.size(); ++i) {
            for (int j = 0; j < bombs.size(); ++j) {
                if (pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2) <= pow(bombs[i][2], 2)) {
                    dp[i][j] = true;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> visit(n, false);
            visit[i] = true;
            res = max(res, dfs(i, bombs, visit, dp));
        }

        return res;

    }

    int dfs(int i, vector<vector<int>> &bombs, vector<bool> &visit, vector<vector<bool>> &dp) {
        int res = 1;
        for (int j = 0; j < bombs.size(); ++j) {
            if (!visit[j] && dp[i][j]) {
                visit[j] = true;
                res += dfs(j, bombs, visit, dp);
            }
        }
        return res;
    }
};