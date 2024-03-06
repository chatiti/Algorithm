#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKOr(vector<int> &nums, int k) {
        int sum[32] = {0};
        for (int i = 0; i <= 31; i++) {
            for (int num: nums) {
                sum[i] += num >> i & 1;
            }
        }

        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (sum[i] >= k) {
                result += 1 << i;
            }
        }
        return result;
    }
};