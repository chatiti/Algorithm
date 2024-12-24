#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        int left[n], right[n];

        int sum = 1;
        for (int i = 0; i < n; ++i) {
            sum *= nums[i];
            left[i] = sum;
        }
        sum = 1;
        for (int i = n - 1; i >= 0; --i) {
            sum *= nums[i];
            right[i] = sum;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int l = 1, r = 1;
            if (i - 1 >= 0) {
                l = left[i - 1];
            }
            if (i + 1 < n) {
                r = right[i + 1];
            }
            ans.push_back(l * r);
        }
        return ans;

    }
};