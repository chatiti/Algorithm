
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        int a[n];
        for (int i = 0; i < n; ++i) {
            a[i] = nums[i];
        }
        for (int i = 0; i < n; ++i) {
            nums[(i + k) % n] = a[i];
        }

    }
};