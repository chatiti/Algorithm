#include <bits/stdc++.h>

using namespace std;

//一个点能到达，它左边的都能到达
//只需要判断从每个点出发能到达最远的距离
//当遍历到的点超过最远到达的距离则不能
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n && k < n - 1; ++i) {
            if (i > k) {
                return false;
            }
            k = max(k, i + nums[i]);
        }
        return true;
    }
};