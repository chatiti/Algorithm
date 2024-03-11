#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int dp[10010];
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            dp[i] = 1e9;
        }
        dp[0] = 0;
        for (int i = 0; i < n - 1; ++i) {
            int jump = nums[i];
            for (int j = i + 1; j <= i + jump; ++j) {
                if (j < n) {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1];

    }
};