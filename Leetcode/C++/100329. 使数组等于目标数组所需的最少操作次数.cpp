#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumOperations(vector<int> &nums, vector<int> &target) {
        vector<long long> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] -= target[i];
        }

        dp[0] = abs(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            if ((long long)nums[i - 1] * (long long)nums[i] > 0) {
                dp[i] = dp[i - 1];
                dp[i] += abs(nums[i]) - abs(nums[i - 1]) > 0 ?
                         abs(nums[i]) - abs(nums[i - 1]) : 0;
            } else {
                dp[i] = dp[i - 1] + abs(nums[i]);
            }
        }
        return dp[nums.size() - 1];
    }
};