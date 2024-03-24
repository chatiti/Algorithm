#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int sum = 0;
        int res = 1e9;
        queue<int> q;
        for (auto it: nums) {
            q.push(it);
            sum += it;
            while (sum >= target) {
                res = min(res, (int) q.size());
                sum -= q.front();
                q.pop();
            }
        }

        if (res > 1e9 / 2) {
            return 0;
        }
        return res;
    }
};