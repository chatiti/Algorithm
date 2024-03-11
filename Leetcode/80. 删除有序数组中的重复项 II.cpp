#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int current = -1;
        int i = 0, j = 0;
        int count = 0;
        for (; i < nums.size(); ++i) {
            if (nums[i] == current) {
                if (count < 2) {
                    swap(nums[i], nums[j]);
                    count++;
                    j++;
                }
            } else {
                current = nums[i];
                swap(nums[i], nums[j]);
                count = 1;
                j++;
            }
        }
        return j ;
    }
};