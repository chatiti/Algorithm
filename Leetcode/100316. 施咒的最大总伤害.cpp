#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int> &power) {
        unordered_map<int, int> m;
        for (auto it: power) {
            m[it]++;
        }

        vector<pair<int, int>> a(m.begin(), m.end());

        std::sort(a.begin(), a.end());

        int n = a.size();
        vector<vector<long long >> dp(n, vector<long long>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = (long long)  a[0].first *  (long long) a[0].second;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

            int l = -1, r = i - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (a[mid].first < a[i].first - 2) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (l < 0) {
                dp[i][1] = (long long) a[i].first * (long long) a[i].second;
            } else {
                dp[i][1] = max(dp[l][0], dp[l][1]) + (long long) a[i].first * (long long) a[i].second;
            }


        }

        return max(dp[n - 1][0], dp[n - 1][1]);

    }
};