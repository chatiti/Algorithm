#include <bits/stdc++.h>

using namespace std;


//首先对数组进行排序，排序后固定一个数 nums[i]nums[i]nums[i]，再使用左右指针指向 nums[i]nums[i]nums[i]后面的两端，数字分别为 nums[L]nums[L]nums[L] 和 nums[R]nums[R]nums[R]，计算三个数的和 sumsumsum 判断是否满足为 000，满足则添加进结果集
//如果 nums[i]nums[i]nums[i]大于 000，则三数之和必然无法等于 000，结束循环
//如果 nums[i]nums[i]nums[i] == nums[i−1]nums[i-1]nums[i−1]，则说明该数字重复，会导致结果重复，所以应该跳过
//当 sumsumsum == 000 时，nums[L]nums[L]nums[L] == nums[L+1]nums[L+1]nums[L+1] 则会导致结果重复，应该跳过，L++L++L++
//当 sumsumsum == 000 时，nums[R]nums[R]nums[R] == nums[R−1]nums[R-1]nums[R−1] 则会导致结果重复，应该跳过，R−−R--R−−
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 3) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int L = i + 1;
            int R = len - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    while (L < R && nums[L] == nums[L + 1]) L++;
                    while (L < R && nums[R] == nums[R - 1]) R--;
                    L++;
                    R--;
                } else if (sum < 0) {
                    L++;
                } else {
                    R--;
                }

            }
        }
        return ans;
    }


};